from re import L
from typing import List


class Solution:
    def getResult(self, arrival: List[int], street: List[int]) -> List[int]:
        length = len(arrival)


# def getResult(arrival, street, n):
#     # creating a list of tuples of street, arrival, and index
#     # and sorting in reverse order based on street
#     queue = sorted(zip(street, arrival, range(n)),
#                        key= lambda item: item[0], reverse=True)

#     # passing time of cars initialized to 0
#     time = [0] * n

#     # previous street initialized to 0
#     prev = None

#     # time taken by cars to through previous street is 0
#     ptime = 0

#     # iterating through queue
#     for street, arrival, index in queue:
#         # updating arrival time of the car
#         time[index] = arrival

#         # if no car passed in the previous second
#         if prev is None:
#             # initializing prev and incrementing count by 1
#             prev = street
#             ptime += 1

#         else:
#             # if previous street and current street is different
#             if prev != street:
#                 # adding the time taken by the cars passed through previous street
#                 time[index] += ptime

#                 # updating count to 0
#                 ptime = 0

#             # updating prev and count by 1
#             prev = street
#             ptime += 1

#     return time


# # reading n and arrival times
# n = int(input())
# arrival = [int(input()) for time in range(n)]

# # reading n and streets
# n = int(input())
# street = [int(input()) for street_ in range(n)]

# # calling getResult()
# print(getResult(arrival, street, n))
