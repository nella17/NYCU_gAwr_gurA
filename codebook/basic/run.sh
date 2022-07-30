#!/bin/bash
f=${1?"fn"}
o=.${f%.*}
s=""
if [ $# = 1 ] || [ $2 = 1 ]; then
  ARGS="-DDEBUG -I$HOME/include_debug"
  s="$s.d"
else
  ARGS="-I$HOME/include"
fi
s="$s.$(md5sum $f | awk '{ print $1 }')"
if [ -e $o$s ]; then
  time 2>&1 echo cached
else
  rm $o* || true
  set -eux
  time g++ -std=c++17 -Wall -Wextra -Wshadow \
    -D_GLIBCXX_DEBUG -D_GLIBCXX_DEBUG_PEDANTIC -D_GLIBCXX_DEBUG_PEDANTIC_ASSERT \
    -Wconversion $ARGS $f -o $o$s
  # -fsanitize=address -fsanitize=undefined
fi
time ./$o$s
