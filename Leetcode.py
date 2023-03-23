from functools import lru_cache
from importlib.resources import path
from mmap import mmap
from os import pathsep
import string
from typing import List
import numpy as np


class Solution:
    # LC 283 move zeroes
    def moveZeroes(self, nums: List[int]) -> None:
        record = 0
        length = len(nums)
        i = 0
        while (i < length):
            if (nums[i] == 0):
                record += 1
                length -= 1
                nums.pop(i)
                i -= 1
            i += 1
        for i in range (0, record):
            nums.append(0)


    # LC 5. Longest Palindromic Substring
    def countPalindromeAroundCenter(self, lo: int, hi: int, s: str) -> str:
        while lo >= 0 and hi < len(s):
            if s[lo] != s[hi]:
                break
            lo -= 1
            hi += 1
        res = s[(lo+1):hi]
        return res

    def longestPalindrome(self, s: str) -> str:
        ans = ""
        for i in range (len(s)):
            s1 = self.countPalindromeAroundCenter(i, i, s)
            s2 = self.countPalindromeAroundCenter(i, i + 1, s)
            if len(s1) > len(ans):
                ans = s1
            if len(s2) > len(ans):
                ans = s2
        return ans

    # LC 63. Unique Paths II
    def uniquePathsWithObstacles(self, obstacleGrid: List[List[int]]) -> int:
        pathSum = [[0] * len(obstacleGrid[0]) for _ in range(len(obstacleGrid))]
        for i in range(len(obstacleGrid) - 1, -1, -1):
            if obstacleGrid[i][len(obstacleGrid[0]) - 1]:
                break
            pathSum[i][len(obstacleGrid[0]) - 1] = 1      # change the value on the border(bottom), the value shoudl be
                                                          # 1 if there is no obstacle ahead
        for i in range(len(obstacleGrid[0]) - 1, -1, -1):
            if obstacleGrid[len(obstacleGrid) - 1][i]:
                break
            pathSum[len(obstacleGrid) - 1][i] = 1         # change the value on the right border, the value shoudl be
                                                          # 1 if there is no obstacle ahead
        for i in range(len(obstacleGrid) - 2, -1, -1):
            for j in range(len(obstacleGrid[0]) - 2, -1, -1):
                if obstacleGrid[i][j]:
                    pathSum[i][j] = 0
                    continue
                pathSum[i][j] = pathSum[i + 1][j] + pathSum[i][j + 1]
        return pathSum[0][0]

    # LC 323. Number of Connected Components in an Undirected Graph
    def countComponents(self, n: int, edges: List[List[int]]) -> int:
        count = 0
        visited = [False] * n
        adj = {x:[] for x in range(n)}
        for x, y in edges:
            adj[x].append(y)
            adj[y].append(x)

        def dfs(adj, visited: List[bool], i: int) -> None:
            if visited[i]:
                return
            visited[i] = True
            for index in adj[i]:
                dfs(adj, visited, index)

        for i in range(n):
            if not visited[i]:
                dfs(adj, visited, i)
                count += 1
        return count

    # LC 2279. Maximum Bags With Full Capacity of Rocks
    def maximumBags(self, capacity: List[int], rocks: List[int], additionalRocks: int) -> int:
        remain = []
        for i in range(len(rocks)):
            remain.append(capacity[i] - rocks[i])
        remain.sort()
        i = 0
        ans = 0
        while (i < len(remain)):
            additionalRocks -= remain[i]
            ans += 1
            i += 1
            if additionalRocks < 0:
                ans -= 1
                break
        return ans
