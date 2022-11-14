from logging import root
from operator import imod
from typing import List
import math
from numpy import product
import sympy
from collections import deque
import queue



class Solution:

    # LC 769. Max Chunks To Make Sorted

    # The basic idea is to use max[] array to keep track of the max value until the current position,
    # and compare it to the sorted array (indexes from 0 to arr.length - 1).
    # If the max[i] equals the element at index i in the sorted array, then the final count++.

    def maxChunksToSorted(self, arr: List[int]) -> int:
        max_Collected = [arr[0]]
        count = 0
        for i in range(1, len(arr)):
            max_Collected.append(max(max_Collected[i - 1], arr[i]))
        for i in range(len(arr)):
            if i == max_Collected[i]:
                count += 1
        return count
    # time and space complexity are both O(n)

    # here is the solution with the space complexity of O(1)
    # time complexity is still O(n)
    def maxChunksToSorted_space_O_1(self, arr: List[int]) -> int:
        Max = -1
        count = 0
        for i in range(0, len(arr)):
            Max = max(Max, arr[i])
            if Max == i:
                count += 1
        return count

    # LC 13. Roman to Integer
    def romanToInt(self, s: str) -> int:
        values = {
            "I": 1,
            "V": 5,
            "X": 10,
            "L": 50,
            "C": 100,
            "D": 500,
        }
        num = 0
        for i in range(len(s) - 1, -1, -1):
            num += values[s[i]]
            if i > 0 and values[s[i - 1]] < values[s[i]]:
                num -=  2 * values[s[i - 1]]
        return num

    #LC 254. Factor Combinations
    def getFactors(self, n: int) -> List[List[int]]:
        res = []
        def factor(n, path):
            if path:
                res.append(path + [n])
            for i in range(2, math.isqrt(n) + 1):
                if n % i == 0:
                    if path and i < path[-1]:  # pay attention to this
                        continue
                    factor(n // i, path + [i])
        factor(n, [])
        return res


    # LC 1099. Two Sum Less Than K

    #idea: two pointers

    def twoSumLessThanK(self, nums: List[int], k: int) -> int:
        nums.sort()
        i, j = 0, len(nums) - 1
        ans = -1
        while i != j:
            if nums[i] + nums[j] < k:
                ans = max(ans, nums[i] + nums[j])
                i += 1
            else:
                j -= 1
        return ans

    # time complexity: O(nlogn)
    # space complexity: O(logn) to O(n), depending on the implementation of the sorting algorithm


    # LC 1352. Product of the Last K Numbers
    def __init__(self):
        self.ans_1352 = [1]

    def add(self, num: int) -> None:
        if num == 0:
            self.ans_1352 = [1]
            return
        product = self.ans_1352[-1] * num
        self.ans_1352.append(product)

    def getProduct(self, k: int) -> int:
        if k >= len(self.ans_1352):
            return 0
        return self.ans_1352[-1] // self.ans_1352[-k - 1]

    # LC 268. Missing Number
    def missingNumber(self, nums: List[int]) -> int:
        expetct_num = len(nums) * (len(nums) + 1) // 2
        real_sum = sum(nums)
        return real_sum - expetct_num

    # LC 207. Course Schedule
    def canFinish(self, numCourses: int, prerequisites: List[List[int]]) -> bool:
        courseDependency = [0] * numCourses
        courseList = [[] for i in range(numCourses)]
        for after, before in prerequisites:
            courseList[before].append(after)
            courseDependency[after] += 1
        q = deque()
        for i in range(numCourses):
            if courseDependency[i] == 0:
                q.append(i)
        nodesPopped = 0
        while len(q):
            temp = q.pop()
            nodesPopped += 1
            for i in courseList[temp]:
                courseDependency[i] -= 1
                if courseDependency[i] == 0:
                    q.append(i)
        return nodesPopped == numCourses


sol = Solution()
print(sol.getFactors(12))



