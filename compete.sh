#!/bin/bash

contest_id=$1

mkdir contest/$contest_id
cd contest/$contest_id

for problem_id in {A..G}; do
  mkdir $problem_id
  cd $problem_id
  oj d https://codeforces.com/contest/$contest_id/problem/$problem_id
  cp ../../../main.cc .
  cd ../
done
