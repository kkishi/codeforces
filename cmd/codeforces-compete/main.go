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

	numProblems int
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

func problemPath(problemID int) string {
	return (string)([]byte{byte('a' + problemID)})
}

func problemURL(problemID int) string {
	return (string)([]byte{byte('A' + problemID)})
}

func createDirs(c *Contest) error {
	for p := 0; p < c.numProblems; p++ {
		dir := path.Join(rootDir, fmt.Sprintf("%d", c.ID), problemPath(p))
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
	for p := 0; p < c.numProblems; p++ {
		dir := path.Join(rootDir, fmt.Sprintf("%d", c.ID), problemPath(p))
		testDir := path.Join(dir, "test")
		if e, err := exists(testDir); err != nil {
			return err
		} else if e {
			fmt.Printf("%s already exists; skip\n", testDir)
			continue
		}
		url := fmt.Sprintf("https://codeforces.com/contest/%d/problem/%s", c.ID, problemURL(p))
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

	if *numProblems == 0 {
		return errors.New("getting the number of problems not supported yet")
	}
	contest.numProblems = *numProblems
	fmt.Println(contest)

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
