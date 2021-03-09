package main

import (
	"fmt"
	"io"
	"io/ioutil"
	"log"
	"os"
	"os/exec"
	"regexp"
)

type problem struct {
	contestID string
	problemID string
}

var solutionPath = regexp.MustCompile("contests\\/(\\d+)\\/([a-z])\\/")

func recognizeProblem(file string) (problem, error) {
	m := solutionPath.FindStringSubmatch(file)
	if len(m) != 3 {
		return problem{}, fmt.Errorf("failed to recognize a problem: %s", file)
	}
	return problem{
		contestID: m[1],
		problemID: m[2],
	}, nil
}

func preprocess(file string, dst io.Writer) error {
	cmd := exec.Command("preprocess", "--file", file)
	cmd.Stdout = dst
	cmd.Stderr = os.Stderr
	return cmd.Run()
}

func cfSubmit(file string, prob problem) error {
	cmd := exec.Command("cf-tool", "submit", prob.contestID, prob.problemID, "-f", file)
	cmd.Stdout = os.Stdout
	cmd.Stderr = os.Stderr
	return cmd.Run()
}

func run(file string) error {
	prob, err := recognizeProblem(file)
	if err != nil {
		return err
	}

	tmpFile, err := ioutil.TempFile("/tmp", "codeforces-submit-*.cc")
	if err != nil {
		return err
	}
	defer os.Remove(tmpFile.Name())

	if err := preprocess(file, tmpFile); err != nil {
		return err
	}
	if err := tmpFile.Close(); err != nil {
		return err
	}

	if err := cfSubmit(tmpFile.Name(), prob); err != nil {
		return err
	}

	return nil
}

func main() {
	if len(os.Args) != 2 {
		fmt.Fprintln(os.Stderr, "Usage: codeforces submit [solution]")
		os.Exit(2)
	}
	if err := run(os.Args[1]); err != nil {
		log.Print(err)
		os.Exit(1)
	}
}
