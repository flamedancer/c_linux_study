#! /bin/bash

touch "./tmfile.txt"

if [ -f "./tmfile.txt" ] && echo "get here" && [ -f "./tmfile2.txt" ] && echo "get another"; then
    echo "both get"
else
    echo "only one" 
fi
rm -f "./tmfile.txt"

if [ -f "./tmfile.txt" ] || echo "tmfile is here" || echo "will never execute me"; then
    echo "now tmfile has removed"
fi

exit 0
