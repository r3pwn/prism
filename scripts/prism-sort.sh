#!/bin/bash
FILES=~/prism/rtgen/*.rt
cd ~/prism/rtgen
for f in $FILES
do
  echo "Processing $f file..."
  # take action on each file. $f store current file name
  rtsort $f
done
