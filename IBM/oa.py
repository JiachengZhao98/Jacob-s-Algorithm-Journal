from typing import List
import string

def circlerealtions(circlePairs: List[str]) -> List[str]:
    res = []
    for i in range(len(circlePairs)):
        circle = circlePairs[i].split()
        if circle[0] == '0':
            centerA = int(circle[1])
            centerB = int(circle[4])
        else:
            centerA = int(circle[0])
            centerB = int(circle[3])
        ra = int(circle[2])
        rb = int(circle[5])
        if centerA == centerB:
            res.append("Concentric")
        elif abs(centerB - centerA) == ra + rb or abs(centerB - centerA) == abs(ra - rb):
            res.append("Touching")
        elif abs(centerB - centerA) > ra + rb:
            res.append("Disjoint-Outside")
        elif abs(centerB - centerA) < abs(ra - rb):
            res.append("Disjoint-Inside")
        else:
            res.append("Intersecting")
    return res

def main():
    circlePairs = ['0 5 9 0 9 7', '0 15 11 0 20 16', '26 0 10 39 0 23', '37 0 5 30 0 11', '41 0 0 28 0 13']
    res = circlerealtions(circlePairs)
    print(res)

if __name__ == "__main__":
    main()
