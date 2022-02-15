#include "iostream"
#include "stdio.h"
#include "cmath"
#include "string"
#include "string.h"
#include "array"
#include "set"
#include "map"
#include "vector"
#include "algorithm"
using namespace std;


class Solution {
public:
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        vector<vector<int>> dp (nums1.size() + 1, vector<int>(nums2.size() + 1, 0));
        int res = 0;
        for (int i = 1; i <= nums1.size(); i++) {
            for (int j = 1; j <= nums2.size(); j++) {
                if (nums1[i - 1] == nums2[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                    dp[i][j + 1] = dp[i][j]; // line 23 is particularly for CSCE 629 HW4 Prob 5. Leetcode 718 does not need it.
                }
                if (dp[i][j] > res) {
                    res = dp[i][j];
                }
            }
        }
        return res;
    }
};

int main(){
    Solution sol;
    vector<int> nums1 = {0,0,0,0,0};
    vector<int> nums2 = {0,0,0,0,1};
    int LCS = 0;
    LCS = sol.findLength(nums1, nums2);
    cout<<LCS<<endl;
    return 0;
    
}
