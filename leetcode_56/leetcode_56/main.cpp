#include "iostream"
#include "map"
#include "vector"
#include "string"
#include "set"
#include "algorithm"
using namespace std;

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> res;
        for (int i = 0; i < intervals.size(); i++) {
            if ((i + 1) < intervals.size() && (intervals[i][1] >= intervals[i + 1][0])) {
                intervals[i + 1][0] = min(intervals[i][0], intervals[i + 1][0]);
                intervals[i + 1][1] = max(intervals[i + 1][1], intervals[i][1]);
            }
            else {
                res.push_back({intervals[i][0],intervals[i][1]});
            }
        }
        return res;
    }
};


int main() {
    
    // test for vector.erase() function
    vector<vector<int>> test = {{1,2}, {3,4}};
    vector<vector<int>>::iterator iter;
    iter = test.begin();
    test.erase(iter + 1);

    for(int i = 0; i < test.size(); i++) {
        for(int j = 0; j < test[0].size(); j++) {
            cout<<test[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<test.size()<<" "<<test[0].size()<<endl;
    return 0;
}
