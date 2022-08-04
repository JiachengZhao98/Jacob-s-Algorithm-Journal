#include "vector"
#include "climits"
#include "iostream"
using namespace std;

class Solution {
public:
    int minAfterMinusK(vector<int>& nums, int k) {
        int sum = 0;
        int partSum = 0;
        for (int i = 0; i < k; i++) {
            partSum += nums[i];
        }
        int Max = partSum;
        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];
            if (i + k < nums.size()) {
                partSum = partSum + nums[i + k] - nums[i];
                Max = max(Max, partSum);
            }  
        }
        return (sum - Max);
    }
};

int main() {
    Solution sol;
    vector<int> nums = {7,3,6,1};
    int res = sol.minAfterMinusK(nums, 2);
    cout<<res<<endl;
    return 0;
}