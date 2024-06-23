#include <iostream>
#include <vector>
#include <unordered_set>
#include <utility>
#include <tuple>
#include "map"

using namespace std;

// valid square 给平面上四个点，判断是否能组成一个正方形。每个点是由（x，y）坐标表示。
// follow up是给n个点，问可以组成多少个valid square，要求先O(n^4)，再改进到O(n^3)，最后改进到 O(n^2)

// basic question

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

    int getLength(vector<int> p1, vector<int> p2) {
        return pow(p1[0] - p2[0], 2) + pow(p1[1] - p2[1], 2);
    }
    // time: O(1), space: O(1)

// follow up question: find the number of 4-point combinations in 2D space which could form a square

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
