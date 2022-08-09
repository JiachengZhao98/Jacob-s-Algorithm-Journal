#include "vector"
#include "iostream"
using namespace std;

class Solution{
public:
    int router(vector<int> buildingCount, vector<int> routerLoc, vector<int> routerRange) {
        int count = 0;
        for (int i = 0; i < routerLoc.size(); i++) {
            int begin = routerLoc[i] - 1 - routerRange[i];
            if (begin < 0) begin = 0;
            int end = routerLoc[i] - 1 + routerRange[i];
            if (end >= buildingCount.size()) end = buildingCount.size() - 1;
            while (begin <= end) {
                buildingCount[begin]--;
                begin++;
            }
        }
        for (auto a : buildingCount) {
            if (a <= 0) {
                count++;
            }
        }
        return count;
    }
};

int main() {
    vector<int> bldgCount = {1,2,1,2,2};
    vector<int> routerLoc = {3,1};
    vector<int> routerRange = {1,2};
    Solution sol;
    int ans = sol.router(bldgCount, routerLoc, routerRange);
    cout<<ans<<endl;
}