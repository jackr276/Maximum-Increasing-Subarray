# Maximum Increasing Subarray
Author: [Jack Robbins](https://github.com/jackr276)

## Problem Description
Given an unordered array of _k_ integers, find the largest subarray **a** such that **a** is an increasing subarray. That is, that every element in **a** is greater than or equal to the preceeding element. 

>[!Note]
>There are two approaches to this problem: iterative and recursive.

## Iterative Solution
The iterative solution to this problem makes use of 3 for loops, of the traditional variety, to generate subarrays in an iterative manner. The first for loop is used to vary the "start" position, while the middle for loop is used to vary the "end" position. The final for loop simply populates a vector with all of the array elements between the "start" and "end" positions. Both the "start" and "end" values are ranged from 0 to the length of the array, allowed for every possible subarray to be generated. Following this, the generated subarrays are checked to see if they are increasing, and if they are, are added to a set of all subarrays. A set is used to guarantee uniqueness of elements and improve efficiency.

## Recursive Solution
The recursive solution to this problem works by having "start" and "end" paramaters passed as function arguments. There are 3 conditions that are checked by the recursive function upon every call. First, if the "end" value is equal to the length of the array, our base case is considered to be reached and we exit the function. Second, the function will check if "start" is greater than "end", and if this condition is satisified, will recursively call itself with an "end" parameter incremented by 1. Finally, if both of those conditions fail, we have the conditions to generate a subarray. Much in the same mannger as the iterative solution, the subarray will be generated with a for loop that grabs array elements from "start" to "end", places the into a vector, and adds that vector to a set if it satisfies the condition of being an increasing array. After generating the subarray, the function will make a recursive call to itself, incrementing the "start" variable by 1. With this approach, every possible subarray is generated.

Both solutions then make use of some simple logic to iterate over the set and find the largest subarray. Timing is also used in this project, to determine the runtimes of each solution. It is observed that, as expected, the recursive solution is usually slower than the iterative one.
