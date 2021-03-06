#!/bin/bash

contest_id=$1
problem_id=$2

preprocess --file=$HOME/projects/codeforces/contest/$contest_id/$problem_id/main.cc > /mnt/c/Users/keisu/Desktop/codeforces/main.cc
cat /mnt/c/Users/keisu/Desktop/codeforces/main.cc
