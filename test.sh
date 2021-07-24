#!/bin/bash

# File: test.sh
# Description: Does unit testing on osm class.

SRC="./src"     # Source code dir.
TEST="./tests"   # Unit tests dir.

# Do Class Functionality Testing
for file in $TEST/*.cpp; do
   prefix=${file%*.cpp}
   g++ --std=c++11 $file $SRC/osm.cpp -o $prefix 2>/dev/null
   $prefix 2>/dev/null
   if [ $? -ne 0 ]; then
      echo "$prefix failed <---"
   else
      echo "$prefix passed"
   fi
   rm $prefix
done

