package main

import (
	"encoding/json"
	"errors"
	"flag"
	"fmt"
	"io/ioutil"
	"net/http"
	"os"
	"os/exec"
	"path"
	"regexp"
	"strconv"
	"time"
)

var (
	numProblems = flag.Int("num_problems", 0, "")
)

const rootDir = "contests"

type ContestList struct {
	Result []Contest
}

type Contest struct {
	ID               int
	Name             string
	Phase            string
	StartTimeSeconds int64

	problems []string
}

func (c *Contest) startTime() time.Time {
	return time.Unix(c.StartTimeSeconds, 0)
}

func getContestList() ([]Contest, error) {
	resp, err := http.Get("https://codeforces.com/api/contest.list")
	if err != nil {
		return nil, err
	}
	defer resp.Body.Close()
	decoder := json.NewDecoder(resp.Body)
	cl := ContestList{}
	if err := decoder.Decode(&cl); err != nil {
		return nil, err
	}
	return cl.Result, nil
}

func printUpcomingContests() error {
	cs, err := getContestList()
	if err != nil {
		return err
	}
	for _, c := range cs {
		if c.Phase == "BEFORE" {
			fmt.Println(c.ID, c.startTime(), c.Name)
		}
	}
	return nil
}

func getProblems(contestID int) ([]string, error) {
	resp, err := http.Get(fmt.Sprintf("https://codeforces.com/contest/%d", contestID))
	if err != nil {
		return nil, err
	}

	if resp.StatusCode != 200 {
		return nil, fmt.Errorf("status code: %d", resp.StatusCode)
	}
	defer resp.Body.Close()
	buf, err := ioutil.ReadAll(resp.Body)
	if err != nil {
		return nil, err
	}
	body := string(buf)
	re := regexp.MustCompile(fmt.Sprintf("\"/contest/%d/problem/(.+)\"", contestID))
	ms := re.FindAllStringSubmatch(body, -1)
	if len(ms) == 0 {
		return nil, errors.New("no problem URLs found in the contest page")
	}
	seen := map[string]bool{}
	var problems []string
	for _, m := range ms {
		if len(m) != 2 {
			continue
		}
		if p := m[1]; !seen[p] {
			seen[p] = true
			problems = append(problems, p)
		}
	}
	return problems, nil
}

func exists(path string) (bool, error) {
	_, err := os.Stat(path)
	if err == nil {
		return true, nil
	}
	if os.IsNotExist(err) {
		return false, nil
	}
	return false, err
}

var tmpl = `#include <bits/stdc++.h>

#include "codeforces.h"

void Solve() {
}

void Main() {
  ints(t);
  rep(t) Solve();
}`

func createDirs(c *Contest) error {
	for _, p := range c.problems {
		dir := path.Join(rootDir, fmt.Sprintf("%d", c.ID), p)
		if err := os.MkdirAll(dir, 0750); err != nil && !os.IsExist(err) {
			return err
		}
		mainCC := path.Join(dir, "main.cc")
		if e, err := exists(mainCC); err != nil {
			return err
		} else if !e {
			if err := ioutil.WriteFile(mainCC, []byte(tmpl), 0644); err != nil {
				return err
			}
		}
	}
	return nil
}

func downloadSamples(c *Contest) error {
	for _, p := range c.problems {
		dir := path.Join(rootDir, fmt.Sprintf("%d", c.ID), p)
		testDir := path.Join(dir, "test")
		if e, err := exists(testDir); err != nil {
			return err
		} else if e {
			fmt.Printf("%s already exists; skip\n", testDir)
			continue
		}
		url := fmt.Sprintf("https://codeforces.com/contest/%d/problem/%s", c.ID, p)
		cmd := exec.Command("oj", "d", url)
		cmd.Dir = dir
		cmd.Stdin = os.Stdin
		cmd.Stdout = os.Stdout
		cmd.Stderr = os.Stderr
		if err := cmd.Run(); err != nil {
			return err
		}
	}
	return nil
}

func compete(contestIDStr string) error {
	contestID, err := strconv.Atoi(contestIDStr)
	if err != nil {
		return err
	}

	cs, err := getContestList()
	if err != nil {
		return err
	}

	var contest *Contest
	for _, c := range cs {
		if c.ID == contestID {
			contest = &c
			break
		}
	}
	if contest == nil {
		return fmt.Errorf("contest %d not found", contestID)
	}

	fmt.Println(contest.Name)
	if contest.Phase == "BEFORE" {
		d := contest.startTime().Sub(time.Now())
		fmt.Println("Starts in", d)
		timer := time.NewTimer(d + 5*time.Second)
		<-timer.C
	}

	if *numProblems == 0 {
		ps, err := getProblems(contest.ID)
		if err != nil {
			return err
		}
		contest.problems = ps
	} else {
		for i := 0; i < *numProblems; i++ {
			contest.problems = append(contest.problems, (string)([]byte{byte('A' + i)}))
		}
	}
	if err := createDirs(contest); err != nil {
		return err
	}
	return downloadSamples(contest)
}

func run() error {
	if len(flag.Args()) == 0 {
		fmt.Println("No contest ID is provided, printing upcoming contests.")
		if err := printUpcomingContests(); err != nil {
			return err
		}
		return nil
	}
	return compete(flag.Arg(0))
}

func main() {
	flag.Parse()
	if err := run(); err != nil {
		fmt.Println("Error:", err)
		os.Exit(1)
	}
}
