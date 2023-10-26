from functools import lru_cache
from importlib.resources import path
from logging import root
from mmap import mmap
from os import pathsep
import string
from typing import List
import numpy as np
import math
from numpy import roots
import numpy


# class Solution:
#     def numIslands(self, grid: List[List[str]]) -> int:
#         def dfs(grid, i, j) -> None:
#             if i >= len(grid) or j >= len(grid[0]) or i < 0 or j < 0 or (i, j) in visited or grid[i][j] != '1':
#                 return
#             visited.add((i, j))
#             dfs(grid, i + 1, j)
#             dfs(grid, i - 1, j)
#             dfs(grid, i, j + 1)
#             dfs(grid, i, j - 1)
#         result = 0
#         visited = set()
#         for i in range(len(grid)):
#             for j in range(len(grid[0])):
#                 if grid[i][j] == '1' and ((i, j) not in visited):
#                     result += 1
#                     dfs(grid, i, j)
#         return result

# sol = Solution()
# result = sol.numIslands([["0","1","0"],["1","0","1"],["0","1","0"]])
# print(result)

from collections import defaultdict, deque
# class Solution:
#     def findOrder(self, numCourses: int, prerequisites: List[List[int]]) -> List[int]:
#         courseDependency = [0] * numCourses
#         adjCourse = defaultdict(list)

#         for prereq in prerequisites:
#             courseDependency[prereq[0]] += 1
#             adjCourse[prereq[1]].append(prereq[0])

#         res = []
#         visited = [False] * numCourses
#         q = deque()

#         for i in range(numCourses):
#             if courseDependency[i] == 0:
#                 q.append(i)
#                 visited[i] = True

#         while q:
#             course = q.popleft()
#             res.append(course)
#             for dependentCourse in adjCourse[course]:
#                 if visited[dependentCourse] == False:
#                     courseDependency[dependentCourse] -= 1
#                     if courseDependency[dependentCourse] == 0:
#                         visited[dependentCourse] = True
#                         q.append(dependentCourse)

#         for visit in visited:
#             if visit == False:
#                 return []

#         return res

def minTotalCost(n, price):
    # Calculate the total cost without using the special offer
    original_cost = sum(abs(price[i] - price[i+1]) for i in range(n-1))

    max_reduction = 0
    for i in range(n):
        reduction = 0
        # Calculate the reduction in cost for the left neighbor
        if i > 0:
            reduction += abs(price[i] - price[i-1]) - abs(price[i] // 2 - price[i-1])
        # Calculate the reduction in cost for the right neighbor
        if i < n-1:
            reduction += abs(price[i] - price[i+1]) - abs(price[i] // 2 - price[i+1])
        max_reduction = max(max_reduction, reduction)

    return original_cost - max_reduction

# # Example
# n = 3
# price = [1,4,1]
# print(minTotalCost(n, price))

def check(data, mid, k):
    s = 0
    n = len(data)
    for i in range(mid):
        s += data[n - i - 1]

    for i in range(mid, n - mid, 2):
        s += data[i]
    return s >= k

def minimumCost(data, k):
    data.sort()
    capacity = 0
    n = len(data)
    for i in range(n // 2):
        capacity += data[n - i - 1]

    if capacity < k:
        return -1

    l = 0
    r = n // 2

    while l < r:
        mid = (l + r) //2
        if check(data, mid, k):
            r = mid
        else:
            l= mid + 1
    return l


