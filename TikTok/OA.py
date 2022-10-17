from functools import lru_cache
from mmap import mmap
import string
from typing import List
import numpy as np

class Solution:
    # LC 322. Coin Change
    def coinChange(self, coins: List[int], amount: int) -> int:
        if amount == 0:
            return 0
        dp = [amount + 1] * (amount + 1)
        dp[0] = 0
        for i in range(amount + 1):
            for j in range(len(coins)):
                if coins[j] <= i:
                    dp[i] = min(dp[i], dp[i - coins[j]] + 1)
        if (dp[-1] > amount):
            return -1
        else:
            return dp[-1]

    # LC 1444. Number of Ways of Cutting a Pizza
    def ways(self, pizza: List[str], K: int) -> int:
        m, n, MOD = len(pizza), len(pizza[0]), 10 ** 9 + 7
        presum = np.zeros((m + 1, n + 1))
        for r in range(m-1, -1, -1):
            for c in range(n-1, -1, -1):
                presum[r][c] = presum[r][c + 1] + presum[r + 1][c] - presum[r + 1][c + 1] + (pizza[r][c] == 'A')

        @lru_cache(None)
        def dp(k, r, c) -> int:
            if presum[r][c] == 0:
                return 0
            if k == 0:
                return 1
            ans = 0
            for nr in range(r + 1, m):
                if presum[r][c] > presum[nr][c]:
                    ans = (ans + dp(k - 1, nr, c)) % MOD
            for nc in range(c + 1, n) :
                if presum[r][c] > presum[r][nc]:
                    ans = (ans + dp(k - 1, r, nc)) % MOD
            return ans
        return dp(K - 1, 0, 0)

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

sol = Solution()
A = "23401"
B = "2453"
print(sol.boringArray(A, B, 4))
