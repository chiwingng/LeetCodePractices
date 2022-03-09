#!/bin/sh

# This is a simple script for creating a directory storing problem solutions

problemId=$1
problemTitle=$2
nExamples=$3

if [ "$nExamples" = "" ]; then
    nExamples=1
fi

if [[ "$problemId" = "-h" ]]; then
    echo "Usage of this script: "$0" [problemId] [problemTitle]."
    exit 0
fi

mkdir -p ${problemId}-${problemTitle}/
touch ${problemId}-${problemTitle}/${problemId}-${problemTitle}_cppSolution.cxx
touch ${problemId}-${problemTitle}/${problemId}-${problemTitle}_pythonSolution.py

readmefile=${problemId}-${problemTitle}/README.md

echo "# ${problemId}. "$(echo ${problemTitle} | sed 's/_/ /g') > $readmefile
echo  >> $readmefile
echo "LeetCode Problem Link: <https://leetcode.com/problems/"$(echo ${problemTitle} | sed 's/_/-/g' | tr '[:upper:]' '[:lower:]')"/>">> $readmefile
echo  >> $readmefile
echo "## Description" >> $readmefile
echo  >> $readmefile
echo  >> $readmefile
echo  >> $readmefile
echo "## Constraints" >> $readmefile
echo  >> $readmefile
echo  >> $readmefile
echo  >> $readmefile
echo "## Solution Thoughts" >> $readmefile
echo  >> $readmefile
echo "### Observations" >> $readmefile
echo  >> $readmefile
echo "### Logic" >> $readmefile
echo  >> $readmefile
echo "### Complexities" >> $readmefile
echo  >> $readmefile
echo "- **Time Complexity**" >> $readmefile
echo  >> $readmefile
echo "- **Space Complexity**" >> $readmefile
echo  >> $readmefile
echo "## Examples" >> $readmefile
for ((i=1;i<=nExamples;i++)); do
    echo  >> $readmefile
    echo "### Example ${i}" >> $readmefile
    echo  >> $readmefile
    echo "> **Input**:" >> $readmefile
    echo ">" >> $readmefile
    echo "> **Output**:" >> $readmefile
    echo ">" >> $readmefile
    echo "> **Explanation**:" >> $readmefile
    echo ">" >> $readmefile
done
