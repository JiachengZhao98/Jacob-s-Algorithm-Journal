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

    // football games
    int findIndex(vector<int>& teamA, int a) {
        int left = 0, right = teamA.size() - 1;
        while (right - left > 1) {
            int middle = (right + left) / 2;
            if (a >= teamA[middle]) {
                left = middle;
                continue;
            }
            else {
                right = middle;
                continue;
            }
        }
        return right;
    }
    vector<int> footballGames(vector<int>& teamA, vector<int>& teamB) {
        sort(teamA.begin(), teamA.end());
        vector<int> ans;
        for (auto a : teamB) {
            if (a >= teamA[teamA.size() - 1]) {
                ans.push_back(teamA.size());
                continue;
            }
            int num = findIndex(teamA, a);
            ans.push_back(num);
        }
        return ans;
    }


private:

};

int main () {
    Solution sol;
    // vector<int> teamA = {1,2,3};
    // vector<int> teamB = {2,3};
    // vector<int> ans = sol.footballGames(teamA, teamB);
    // for (auto a : ans) {
    //     cout<<a<<endl;
    // }
    cout<<sol.lotteryCoupons(12)<<endl;
    return 0;
}
