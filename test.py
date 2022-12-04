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
from collections import deque

class Solution:
    def numIslands(self, grid: List[List[str]]) -> int:
        def dfs(grid, i, j) -> None:
            if i >= len(grid) or j >= len(grid[0]) or i < 0 or j < 0 or (i, j) in visited or grid[i][j] != '1':
                return
            visited.add((i, j))
            dfs(grid, i + 1, j)
            dfs(grid, i - 1, j)
            dfs(grid, i, j + 1)
            dfs(grid, i, j - 1)
        result = 0
        visited = set()
        for i in range(len(grid)):
            for j in range(len(grid[0])):
                if grid[i][j] == '1' and ((i, j) not in visited):
                    result += 1
                    dfs(grid, i, j)
        return result

sol = Solution()
result = sol.numIslands([["0","1","0"],["1","0","1"],["0","1","0"]])
print(result)
