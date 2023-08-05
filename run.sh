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

#g++ longest-substring-without-repeating-chars.cpp -Wall
#for s in "" "a" "aa" "ab" "aba" "abac" "abcabcbb" "bbbbb" "pwwkew" "1248 fweuhwekqroije" $(pwgen 40000 1)
#do
#	time ./a.out "$s"
#done

#g++ min-stack.cpp -Wall
#./a.out

#g++ number-of-islands.cpp -Wall
#./a.out

g++ container-with-most-water.cpp -Wall
./a.out

