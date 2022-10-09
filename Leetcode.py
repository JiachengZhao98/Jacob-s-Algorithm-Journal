from typing import List


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
