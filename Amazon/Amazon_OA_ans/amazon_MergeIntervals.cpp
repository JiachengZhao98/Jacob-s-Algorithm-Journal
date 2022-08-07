#include "iostream"
#include "vector"
using namespace std;

class Solution {
public:
    int merge(vector<vector<int>>& intervals) {
        int size = intervals.size();
        vector<vector<int>> res;
        sort(intervals.begin(), intervals.end());
        for (int i = 0; i < intervals.size(); i++) {
            if (i + 1 < intervals.size() && intervals[i + 1][0] <= intervals[i][1]) {
                intervals[i + 1][0] = min(intervals[i + 1][0], intervals[i][0]);
                intervals[i + 1][1] = max(intervals[i + 1][1], intervals[i][1]);
            }
            else
                res.push_back({intervals[i][0], intervals[i][1]});
            }
        return size - res.size();
        }
    };