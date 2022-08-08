#include "vector"
#include "set"
#include "iostream"
using namespace std;

class Solution {
public:
    int maxSubarrrayWithK(vector<int>& nums, int k) {
        int res = INT_MIN;
        for (int i = 0; i < nums.size() - k; i++) {
            int j = i;
            int temp = 0;
            set<int> mySet;
            while (j < i + k) {
                mySet.insert(nums[j]);
                temp += nums[j];
                j++;
            }
            if (mySet.size() == k) {
                res = res < temp ? temp : res;
            }
        }
        return res;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {1,2,7,7,4,3,6};
    int ans = sol.maxSubarrrayWithK(nums, 3);
    cout<<ans<<endl;
    return 0;
}