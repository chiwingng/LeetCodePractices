#!/bin/sh

# A simple script to git add and commit solutions

problemId=$1

rm ${problemId}-*/*~
git add ${problemId}-*/
git commit -m "\"My solution to problem ${problemId}.\""
