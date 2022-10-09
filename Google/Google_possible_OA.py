from inspect import stack
from sys import flags
import string

class Solution:
    # LC 202. Happy Number
    def getSum(self, n: int) -> int:
        sum = 0
        while (n):
            sum += pow(n % 10, 2)
            n = n // 10
        return sum

    def isHappy(self, n: int) -> bool:
        seen = set()
        while (1):
            sum = self.getSum(n)
            if (sum == 1):
                return True
            if (sum in seen):
                return False
            else : seen.add(sum)
            n = sum

    # LC 394. Decode String
    def decodeString(self, s: str) -> str:
        stack = []
        for i in range(len(s)):
            if s[i] != ']':
                stack.append(s[i])
            else:
                substr = ""
                num = ""
                while stack[-1] != '[':
                    substr = stack.pop() + substr
                stack.pop()
                while stack and stack[-1].isdigit():
                    num = stack.pop() + num
                stack.append(int(num) * substr)
        return "".join(stack)







# main function

# sol = Solution()
# ans = sol.isHappy(19)
# print(ans)
