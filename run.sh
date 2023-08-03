#!/bin/sh

set -e

#g++ trie.cpp
#./a.out "" apple
#./a.out apple ""
#./a.out apple apple
#./a.out apple appleee
#./a.out apple app
#./a.out apple z

#g++ kth-largest-element-in-array.cpp -Wall
#for i in $(seq 6); do ./a.out $i; done

#g++ jump-game.cpp
#time ./a.out

g++ longest-substring-without-repeating-chars.cpp -Wall
time ./a.out ""
time ./a.out "a"
time ./a.out "aa"
time ./a.out "ab"
time ./a.out "aba"
time ./a.out "abac"
time ./a.out "abcabcbb"
time ./a.out "bbbbb"
time ./a.out "pwwkew"
time ./a.out "1248 fweuhwekqroije"
STR=$(pwgen 40000 1)
time ./a.out "$STR"

