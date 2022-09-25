from sys import flags


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






# main function

sol = Solution()
ans = sol.isHappy(19)
print(ans)

