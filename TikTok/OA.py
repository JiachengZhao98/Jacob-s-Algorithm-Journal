from functools import lru_cache
import imp
from importlib.resources import path
from mmap import mmap
from operator import imod
from os import pathsep
import string
from typing import List
import numpy as np
import sys
import imp


class Solution:
    # original: LC 322. Coin Change
    def umbrella(self, size: List[int], requirement: int) -> int:
        if requirement == 0:
            return 0
        dp = [requirement + 1] * (requirement + 1)
        dp[0] = 0
        for i in range(requirement + 1):
            for j in range(len(size)):
                if size[j] <= i:
                    dp[i] = min(dp[i], dp[i - size[j]] + 1)
        if (dp[-1] > requirement):
            return -1
        else:
            return dp[-1]

    # origianl: LC 1444. Number of Ways of Cutting a Pizza
    def ways(self, forest: List[int], num: int) -> int:
        m, n, MOD = len(forest), len(forest[0]), 10 ** 9 + 7
        presum = [[0] * (n + 1) for i in range(m + 1)]
        for r in range(m-1, -1, -1):
            for c in range(n-1, -1, -1):
                presum[r][c] = presum[r][c + 1] + presum[r + 1][c] - presum[r + 1][c + 1] + (forest[r][c] == 2)

        @lru_cache(None)
        def dp(k, r, c) -> int:
            if presum[r][c] == 0:
                return 0
            if k == 0:
                return 1
            ans = 0
            # cut horizontally
            for nr in range(r + 1, m):
                if presum[r][c] > presum[nr][c]:
                    ans = (ans + dp(k - 1, nr, c)) % MOD
            # cut vertically
            for nc in range(c + 1, n) :
                if presum[r][c] > presum[r][nc]:
                    ans = (ans + dp(k - 1, r, nc)) % MOD
            return ans
        return dp(num - 1, 0, 0)

    # boring array
    def boringArray(self, A: string, B: string, k: int) -> bool:
        B = list(B)
        a = []
        count = 0
        for i in range(len(A)):
            a.append(int(A[i]))
        a.sort()
        #print(a)
        for i in range(len(a)):
            index = i
            temp = a[index] + 1
            if str(a[index]) in B:
                B.remove(str(a[index]))
                count += 1
            elif str(temp) in B:
                B.remove(str(temp))
                #print(B)
                count += 1
            if count >= k:
                break
        return len(B) == 0

    # LC 945. Minimum Increment to Make Array Unique
    def minIncrementForUnique(self, nums: List[int]) -> int:
        res = need = 0
        nums.sort()
        for i in nums:
            res += max(need - i, 0)
            need = max(i + 1, need +1)
        return res

    # tiktok OA for Oct 17, 2022
    def minIncrementForUnique_sum(self, nums: List[int]) -> int:
        need = 0
        nums.sort()
        ans = 0
        for i in nums:
            ans += max(i, need)
            #print(max(i, need))
            need = max(i + 1, need +1)
        return ans

    # LC 62. Unique Path
    def uniquePaths(self, m: string, n: string) -> string:
        pathSum = [[1] * (int(n) + 1)] * (int(m) + 1)
        for i in range(int(m) - 1, -1, -1):
            for j in range(int(n) - 1, -1, -1):
                pathSum[i][j] = pathSum[i + 1][j] + pathSum[i][j + 1]
        return str(pathSum[0][0])

    # OA for Oct 17, 2022, which originates from LC 323
    def socialNetwork(self, n: int, edges: List[List[int]]) -> int:
        record = count = ans = 0
        visited = [False] * n
        adj = {x:[] for x in range(n)}
        for x, y in edges:
            adj[x].append(y)
            adj[y].append(x)

        def dfs(adj, visited: List[bool], i: int) -> int:
            count = 0
            if visited[i]:
                return count
            visited[i] = True
            count += 1
            for index in adj[i]:
                count += dfs(adj, visited, index)
            return count

        for i in range(n):
            if not visited[i]:
                count += 1
                temp = dfs(adj, visited, i)
                print(temp)
                if temp > record:
                    record = temp
                    ans = count
        return ans


    # LC 993. Cousins in Binary Tree









sol = Solution()
A = "23401"
B = "2453"
#print(sol.minIncrementForUnique_sum([3,2,1,2,7]))
#print(sol.uniquePaths('2','2'))
print(sol.socialNetwork(8, [[0,1],[1,2],[2,3],[5,4],[7,6]]))
