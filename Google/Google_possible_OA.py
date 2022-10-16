from inspect import stack
from multiprocessing import heap
from sys import flags
import string
from typing import List
import queue
import heapq

# LC 690. Employee Importance
# Definition for Employee.
class Employee:
    def __init__(self, id: int, importance: int, subordinates: List[int]):
        self.id = id
        self.importance = importance
        self.subordinates = subordinates

    def getImportance(self, employees: List['Employee'], id: int) -> int:
        employee_map = {employee.id: employee for employee in employees}
        importance = 0
        que = []
        que.append(employee_map[id])
        while que:
            cur_emp = que.pop()
            importance += cur_emp.importance
            que.extend(employee_map[new_id] for new_id in cur_emp.subordinates)
        return importance

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

    # LC 253. Meeting Rooms II
    def minMeetingRooms(self, intervals: List[List[int]]) -> int:
        if not intervals:
            return 0
        freeRoom = []
        intervals.sort(key= lambda x: x[0])
        heapq.heappush(freeRoom, intervals[0][1])
        for i in intervals[1:]:
            if freeRoom[0] <= i[0]:
                heapq.heappop(freeRoom)
            heapq.heappush(freeRoom, i[1])
        return len(freeRoom)




# main function

sol = Solution()
ans = sol.decodeString("2[fa]")
print(ans)
