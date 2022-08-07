#include "vector"
#include "queue"
using namespace std;

class Solution {
public:
    int triangularSum(vector<int>& nums) {
        if (nums.size() == 1) {
            return nums[0];
        }
        vector<int> ans;
        for(int i = 0; i < nums.size() - 1; i++) {
            int v = nums[i] + nums[i+1];
            if (v > 9) {
                v %= 10;
            }
            ans.push_back(v);
        }
        return triangularSum(ans);
    }
};