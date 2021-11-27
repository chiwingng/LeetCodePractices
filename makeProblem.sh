#!/bin/sh

# This is a simple script for creating a directory storing problem solutions

problemId=$1
problemTitle=$2

if [[ "$problemId" = "-h" ]]; then
    echo "Usage of this script: "$0" [problemId] [problemTitle]."
    exit 0
fi

mkdir -p ${problemId}-${problemTitle}/
touch ${problemId}-${problemTitle}/${problemId}-${problemTitle}_cppSolution.cxx
touch ${problemId}-${problemTitle}/${problemId}-${problemTitle}_pythonSolution.py
