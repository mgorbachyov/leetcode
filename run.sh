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

#g++ container-with-most-water.cpp -Wall
#./a.out

#g++ group-anagrams.cpp -Wall
#./a.out

#g++ 2-add-two-numbers.cpp -Wall
#./a.out

#g++ 98-validate-binary-search-tree.cpp -Wall
#./a.out

#g++ 48-rotate-image.cpp -Wall
#./a.out

#g++ 39-combination-sum.cpp -Wall
#./a.out 7

#g++ 34-find-first-and-last-pos-in-sorted-array.cpp -Wall
#./a.out

#g++ 102-level-order.cpp
#./a.out

#g++ 121-best-time-buy-sell.cpp -Wall
#time ./a.out

#g++ 62-unique-paths.cpp -Wall
#./a.out

#g++ 207-course-schedule.cpp -Wall
#./a.out

#g++ 128-longest-consecutive-sequence.cpp
#./a.out

#g++ 347-top-frequent-elements.cpp
#./a.out

#g++ 19-remove-nth-node-from-end-of-list.cpp -fsanitize=address -O1 -fno-omit-frame-pointer -g
#for i in $(seq 5)
#do
#	./a.out $i
#done

#g++ 54-spiral-matrix.cpp -Wall -g
#./a.out

#g++ 438-all-anagrams-in-string.cpp  -fsanitize=address -O1 -fno-omit-frame-pointer -g
#./a.out

g++ 394-decode-string.cpp -Wall
./a.out

