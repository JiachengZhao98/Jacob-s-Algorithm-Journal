#include "vector"
#include "queue"
#include "climits"
#include "stack"
#include "set"
#include "map"
#include "unordered_map"
#include "unordered_set"
#include "iostream"
#include "deque"
using namespace::std;

class Solution {
public:
    bool dfs(int sx, int sy, int tx, int ty) {
        if (sx >tx or sy > ty) {
            return 0;
        }
        if (sx == tx and sy == ty) {
            return 1;
        }
        bool temp1 = dfs(sx, sx + sy, tx, ty);
        bool temp2 = dfs(sx + sy, sy, tx, ty);
        return temp1 || temp2;
    }

    // LC 780. Reaching Points

    // isPossible

    // recursive approach
    bool reachingPoints_recursive(int sx, int sy, int tx, int ty) {
       return dfs(sx, sy, tx, ty);
    }

    // module approach
    bool reachingPoints(int sx, int sy, int tx, int ty) {
        if (sx > tx || sy > ty) {
            return 0;
        }
        else if (sx == tx && sy == ty) {
            return 1;
        }
        while (tx > sx && ty > sy) {
            if (tx > ty) {
                tx = tx % ty;
            }
            else {
                ty = ty % tx;
            }
        }
        if ((tx == sx && (ty - sy ) % sx == 0) || (ty == sy && (tx - sx) % sy == 0)) {
            return 1;
        }
        else return 0;
    }


    // Lottery Coupons
    int lotteryCoupons(int n) {
        unordered_map<int, int> myMap;
        for (int i = 1; i <= n; i++) {
            int sumDigits = i / 10 + i % 10;
            if (myMap.find(sumDigits) == myMap.end()) {
                myMap.insert(pair<int, int>(sumDigits, 1));
            }
            else myMap.find(sumDigits)->second++;
        }
        map<int, int> record;
        for (auto iter = myMap.begin(); iter != myMap.end(); iter++) {
            if (record.find(iter->second) == record.end()) {
                record.insert(pair<int, int>(iter->second, 1));
            }
            else record.find(iter->second)->second++;
        }
        return record.rbegin()->second;
    }


private:

};
