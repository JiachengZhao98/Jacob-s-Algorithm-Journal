#include "vector"
#include "iostream"
using namespace std;

class Solution {
public:
    int minMove(vector<int>& nums) {
        int count1 = 0, dis = 0;
        for (auto a : nums) {
            if (a == 1) count1++;
            else dis += count1;
        }
        int count0 = nums.size() - count1;
        return min(dis, count0 * count1 - dis);
    }
};

int main() {
    vector<int> nums = {0, 1 ,0 , 1};
    Solution sol;
    int ans = sol.minMove(nums);
    cout<<ans<<endl;
    return 0;
}