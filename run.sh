#!/bin/sh

CMD="g++ -Wall -fsanitize=address -O1 -fno-omit-frame-pointer -g"

set -e

#$CMD trie.cpp
#./a.out "" apple
#./a.out apple ""
#./a.out apple apple
#./a.out apple appleee
#./a.out apple app
#./a.out apple z

#$CMD kth-largest-element-in-array.cpp
#for i in $(seq 6); do ./a.out $i; done

#$CMD jump-game.cpp
#time ./a.out

#$CMD longest-substring-without-repeating-chars.cpp
#for s in "" "a" "aa" "ab" "aba" "abac" "abcabcbb" "bbbbb" "pwwkew" "1248 fweuhwekqroije" $(pwgen 40000 1)
#do
#	time ./a.out "$s"
#done

#$CMD min-stack.cpp
#$CMD number-of-islands.cpp
#$CMD container-with-most-water.cpp
#$CMD group-anagrams.cpp
#$CMD 2-add-two-numbers.cpp
#$CMD 98-validate-binary-search-tree.cpp
#$CMD 48-rotate-image.cpp

#$CMD 39-combination-sum.cpp
#./a.out 7

#$CMD 34-find-first-and-last-pos-in-sorted-array.cpp
#$CMD 102-level-order.cpp
#$CMD 121-best-time-buy-sell.cpp
#$CMD 62-unique-paths.cpp
#$CMD 207-course-schedule.cpp
#$CMD 128-longest-consecutive-sequence.cpp
#$CMD 347-top-frequent-elements.cpp

#$CMD 19-remove-nth-node-from-end-of-list.cpp
#for i in $(seq 5)
#do
#	./a.out $i
#done

#$CMD 54-spiral-matrix.cpp
#$CMD 438-all-anagrams-in-string.cpp
#$CMD 394-decode-string.cpp
#$CMD 15-3sum.cpp
#$CMD 53-max-subarray.cpp
#$CMD 206-reverse-linked-list.cpp
#$CMD 46-permutations.cpp
#$CMD 74-search-2d-matrix.cpp
$CMD 105-construct-binary-tree-from-preoder-and-inorder-traversal.cpp

./a.out
#time ./a.out

