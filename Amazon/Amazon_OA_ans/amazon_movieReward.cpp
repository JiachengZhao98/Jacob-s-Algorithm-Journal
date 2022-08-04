#include "vector"
#include "iostream"
#include "algorithm"
using namespace std;

class Solution {
public:
    int movieReward(vector<int>& awards, int k) {
        int i = 0, j = 0, count = 1;
        sort(awards.begin(), awards.end());
        while (j < awards.size()) {
            if (awards[j] - awards[i] <= k){
                j++;
                continue;
            }
            else {
                i = j;
                j++;
                count++;
            }
        }
        return count;
    }
};

int main() {
    Solution sol;
    vector<int> awards = {1,5,4,6,8,9,2};
    int res = sol.movieReward(awards, 3);
    cout<<res<<endl;
    return 0;
}