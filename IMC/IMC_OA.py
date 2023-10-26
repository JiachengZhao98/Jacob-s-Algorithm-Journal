from re import L
from typing import List
from collections import deque
import collections

def findBestPath(n, m, startRow, startColumn, endRow, endColumn, monsterRow, monsterColumn):
    from collections import deque

    # directions for moving up, down, left, and right
    directions = [(0, 1), (1, 0), (0, -1), (-1, 0)]

    # Initialize the grid with infinities
    monster_dist = [[float('inf') for _ in range(m)] for _ in range(n)]

    # Compute distance from each cell to nearest monster
    for x, y in zip(monsterRow, monsterColumn):
        visited = [[False for _ in range(m)] for _ in range(n)]
        queue = deque([(x, y, 0)])
        while queue:
            r, c, dist = queue.popleft()
            if 0 <= r < n and 0 <= c < m and not visited[r][c]:
                visited[r][c] = True
                monster_dist[r][c] = min(monster_dist[r][c], dist)
                for dr, dc in directions:
                    queue.append((r + dr, c + dc, dist + 1))

    # BFS from start to end, trying to maximize the minimum distance to a monster
    visited = [[False for _ in range(m)] for _ in range(n)]
    queue = deque([(startRow, startColumn, monster_dist[startRow][startColumn])])
    while queue:
        r, c, dist = queue.popleft()
        if (r, c) == (endRow, endColumn):
            return dist
        visited[r][c] = True
        for dr, dc in directions:
            nr, nc = r + dr, c + dc
            if 0 <= nr < n and 0 <= nc < m and not visited[nr][nc]:
                queue.append((nr, nc, min(dist, monster_dist[nr][nc])))


    #leetcode 2534
def timeTaken(self, arrivals: list[int], states: list[int]) -> list[int]:
    n = len(arrivals)
    answer = [0] * n

    time, direction = 0, 1
    queues = [collections.deque(), collections.deque()]

    def exhaust_until(end_time: int=2*10**5) -> None:
        nonlocal time, direction
        while end_time > time and any(queues):
            if not queues[direction]:
                direction ^= 1
            answer[queues[direction].popleft()] = time
            time += 1

    for index, (arrival, state) in enumerate(zip(arrivals, states)):
        exhaust_until(arrival)
        if arrival > time:
            time, direction = arrival, 1
        queues[state].append(index)

    exhaust_until()
    return answer


# # Example usage
# n, m = 5, 3
# startRow, startColumn = 1, 1
# endRow, endColumn = 4, 2
# monsterRow = [0, 2]
# monsterColumn = [2, 2]
# print(findBestPath(n, m, startRow, startColumn, endRow, endColumn, monsterRow, monsterColumn))  # Expected output: 1

class Solution:
    def maximumSafenessFactor(self, grid: List[List[int]]) -> int:

        n = len(grid)
        queue, safeness = deque(), [[-1] * n for _ in range(n)]
        unseen = set(product(range(n), range(n)))
        nei = lambda x,y: set(((x-1,y), (x,y-1), (x+1,y), (x,y+1))) & unseen

        for i, j in product(range(n),range(n)):
            if grid[i][j] == 1:
                safeness[i][j] = 0
                queue.append((0, i,j))

        while queue:

            s, x,y = queue.popleft()

            for X, Y in nei(x,y):
                if safeness[X][Y] == -1:
                    safeness[X][Y] = s + 1
                    queue.append((s+1, X,Y))

        heap = [(-safeness[-1][-1], n-1,n-1)]

        while heap:
            s ,x,y = heappop(heap)
            if (x,y) == (0,0): return min(-s,safeness[0][0])
            unseen.discard((x,y))

            for X, Y in nei(x,y):
                safe = max(s,-safeness[X][Y])
                heappush(heap,(safe, X,Y) )
                unseen.discard((X,Y))

        return -1

    def realEstateAnalysis(reqArea: int, area: List[int], price: List[int]) -> int:
        area_price = {}
        for i in range(len(area)):
            area_price

