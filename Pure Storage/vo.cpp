#include <iostream>
#include <vector>
#include <utility>
#include <tuple>
#include "map"
#include "cmath"
#include "unordered_map"
#include "unordered_set"
#include "map"
#include "set"
#include "mutex"
#include "condition_variable"
#include "stack"
#include "queue"

using namespace std;

//.substr() syntax:
// string substr(size_t pos = 0, size_t len = npos) const;
// PAY ATTENTION !!!

// VO 准备请参见 https://docs.google.com/document/d/1wHGs135aODXjuyEN5-tz8sCDb0iCefyQX2HHbToAz8c/edit

// Valid Square
// 给平面上四个点，判断是否能组成一个正方形。每个点是由（x，y）坐标表示。
// follow up是给n个点，问可以组成多少个valid square，要求先O(n^4)，再改进到O(n^3)，最后改进到 O(n^2)

// basic question

    int getLength(vector<int> p1, vector<int> p2) {
        return pow(p1[0] - p2[0], 2) + pow(p1[1] - p2[1], 2);
    }

    bool validSquare(vector<int>& p1, vector<int>& p2, vector<int>& p3, vector<int>& p4) {
        int l1 = 0, l2 = 0, l3 = 0, l4, l5, l6;
        l1 = getLength(p1, p2);
        l2 = getLength(p1, p3);
        l3 = getLength(p2, p3);
        l4 = getLength(p1, p4);
        l5 = getLength(p2, p4);
        l6 = getLength(p4, p3);
        map<int, int> mp;
        mp[l1]++;
        mp[l2]++;
        mp[l3]++;
        mp[l4]++;
        mp[l5]++;
        mp[l6]++;
        if (mp.size() == 2 && mp.begin()->second == 4 && mp.rbegin()->second == 2) {
            if (mp.begin()->first * 2 == mp.rbegin()->first) {
                return 1;
            }
        }
        return 0;
    }


    // time: O(1), space: O(1)
    // reason for not using sqrt() to calculate the distance:
    // 1. it's a float type operation, and it will increase the cost. Since not using sqrt() will not effect the result of comparisons, we prefer achieve the result without the extra computational overhead
    // 2. using the square of distance to do the comparsion is stable and stable. Floating-point calculations can cause slight inaccuracies due to the way number are represented in computer memory.

// follow up question: if there are N points, find the number of 4-point combinations in 2D space which could form a square

    int findSquares(vector<vector<int>>& points) {
        unordered_set<string> pointSet;
        for (auto a : points) {
            string temp = to_string(a[0]) + '_' + to_string(a[1]);
            pointSet.insert(temp);
        }
        int count = 0;
        for (int i = 0; i < points.size(); i++) {
            for (int j = 0; j < points.size(); j++) {
                if (i != j) {
                    if (points[i][0] == points[j][0] && points[i][1] == points[j][1]) continue;
                    int dx = points[j][0] - points[i][0];
                    int dy = points[j][1] - points[i][1];

                    string p3 = to_string(points[i][0] - dy) + "_" + to_string(points[i][1] + dx);
                    string p4 = to_string(points[j][0] - dy) + "_" + to_string(points[j][1] + dx);
                    if (pointSet.find(p3) != pointSet.end() && pointSet.find(p4) != pointSet.end()) {
                        count++;
                    }
                }
            }
        }
        count /= 4;
        return count;
    }
    // time: O(N^2), space: O(N)
    // Coordinate Calculation: For each pair p1 and p2,
    // it calculates two other points p3 and p4 that would form a square.
    // The calculations for p3 and p4 use the vector properties of squares:
    // p3: Rotate vector p2-p1 by 90 degrees counterclockwise to get p1-p3.
    // p4: Similarly, apply the rotation to get p2-p4.


    // Another follow up question: calculate the number of 4-point combinations which could form a rectangle

    // Approach: use the midpoint of the side of a rectangle
    // one rectangle property: any two points that are diagonally opposite each other in a rectangle, the midpoint and the distances to the midpoint are the same
    int findRectangles(vector<vector<int>>& points) {
        int n = points.size();
        map<vector<double>, int> midpointCount;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (i != j) {
                    double pixel_x = (points[j][0] + points[i][0]) / 2;
                    double pixel_y = (points[j][1] + points[j][1]) / 2;
                    midpointCount[{pixel_x, pixel_y}]++;
                }
            }
        }
        int rectangles = 0;
        for (auto iter : midpointCount) {
            if (iter.second <= 1) continue;
            rectangles += (iter.second * (iter.second - 1)) / 2;
        }
        return rectangles;
    }

    // time: O(N^2 logN)

// O(1) set

// reference: https://www.geeksforgeeks.org/design-a-data-structure-that-supports-insert-delete-search-and-getrandom-in-constant-time/
class myO1Set {
private:
    vector<int> num;
    unordered_map<int, int> Map;

public:
    myO1Set() {}

    void insert(int x) {
        if (Map.find(x) != Map.end()) {
            return;
        }
        int size = num.size();
        num.push_back(x);
        Map[x] = size;
    }

    void remove(int x) {
        if (Map.find(x) == Map.end()) {
            return;
        }
        int index_x = Map[x];
        int last = num.back();
        num[index_x] = last;
        Map[last] = index_x;
        num.pop_back();
        Map.erase(x);
    }

    int search(int x) {
        if (Map.find(x) == Map.end()) {
            return -1;
        }
        return Map[x];
    }

    int getRandom() {
        srand(time(NULL));
        int index = rand() % num.size();
        return num[index];
    }
};

// another O(1) set
// design a new map with the following operation time complexity: add: O(1) deletion: O(1) lookup: O(1) clear (1) iterate: O(number of elements)

// approach: use the idea of version control. when the clear() function is called, all elements of previous version will be invalid.

class myO1Set2 {
private:
    int curVersion;
    unordered_map<int, unordered_set<int>> Map;
public:
    myO1Set2() {
        this->curVersion = 0;
    }

    void add(int x) {
        Map[curVersion].insert(x);
    }

    void remove(int x) {
        if (Map[curVersion].find(x) != Map[curVersion].end()) {
            Map[curVersion].erase(x);
        }
    }

    void clear() {
        curVersion++;
    }

    bool look_up(int x) {
        if (Map[curVersion].find(x) == Map[curVersion].end()) {
            return 0;
        }
        return 1;
    }
};

// leetcode 75 https://leetcode.com/problems/sort-colors/description/

    // first approach: traverse the vector once, memorize the number of red, white and blue objects. Then traverse the vector again to change the number of the vector in place.

    // second approach

    void sortColors(vector<int>& nums) {
        int red = 0, blue = nums.size() - 1;
        int index = 0;
        while (index <= blue) {
        if (nums[index] == 0) {
            while (index > red && nums[red] == 0) {
                red++;
            }
            if (index == red) {
                index++; continue;
            }
            swap(nums[red], nums[index]);
            red++;
            continue;
        }
        if (nums[index] == 2) {
            while (index < blue && nums[blue] == 2) {
                blue--;
            }
            if (index == blue) {
                break;
            }
            swap(nums[blue], nums[index]);
            blue--;
            continue;
        }
        index++;
        }
    }

// Buddy System
/*
    problem and data structure definition: https://massivealgorithms.blogspot.com/2016/06/buttercola-buddy-system.html
*/
    void set_bit(vector<vector<int>>& bits, int& offset, int& length) {
        int curLevel = bits.size()-1;
        int left = offset;
        int right = offset + length - 1;
        while (curLevel >= 0) {
            for (int i = left; i <= right; i++) {
                if(curLevel == bits.size() - 1) {
                    bits[curLevel][i] = 1;
                }
                else {
                    if (bits[curLevel + 1][i * 2] && bits[curLevel + 1][i * 2 + 1]) {
                        bits[curLevel][i] = 1;
                    }
                }
            }
            curLevel--;
            left /= 2;
            right /= 2;
        }
    }

    void clear_bit(vector<vector<int>>& bits, int& offset, int& length) {
        int curLevel = bits.size()-1;
        int left = offset;
        int right = offset + length - 1;
        while (curLevel >= 0) {
            for (int i = left; i <= right; i++) {
                bits[curLevel][i] = 0;
            }
            curLevel--;
            left /= 2;
            right /= 2;
        }
    }
    // BFS is more memory efficient and better on memory access localoty.



// Leetcode 202 Happy Number
int sumOfSquaresOfDigits(int n) {
    string str = to_string(n);
    int res = 0;
    for (auto a : str) {
        res += pow(a - '0', 2);
    }
    return res;
}

bool isHappy(int n) {
    if (n == 1) return 1;
    unordered_set<int> Set;
    Set.insert(n);
    while (n != 1) {
        n = sumOfSquaresOfDigits(n);
        if (n == 1) return true;
        if (Set.find(n) != Set.end()) break;
        Set.insert(n);
    }
    return false;
}

// thread-safe stack with pop and push functions

class threadSafeStack {
private:
    mutex mtx;
    condition_variable cv;
    stack<int> sta;

public:
    threadSafeStack() {

    }
};


int main() {
    myO1Set ds;
    ds.insert(10);
    ds.insert(20);
    ds.insert(30);
    ds.insert(40);
    cout << ds.search(30) << endl;
    ds.remove(40);
    ds.insert(50);
    cout << ds.search(50) << endl;
    cout << ds.getRandom() << endl;
    return 0;
}
