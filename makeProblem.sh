#!/bin/sh

# This is a simple script for creating a directory storing problem solutions

problemId=$1
problemTitle=$2

mkdir -p ${problemId}-${problemTitle}/
touch ${problemId}-${problemTitle}/${problemId}-${problemTitle}_cppSolution.cxx
touch ${problemId}-${problemTitle}/${problemId}-${problemTitle}_pythonSolution.py
