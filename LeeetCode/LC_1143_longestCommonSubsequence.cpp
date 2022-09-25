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
    int longestCommonSubsequence(string text1, string text2) {
        vector<vector<int>> dp(text1.length() + 2, vector<int>(text2.length() + 2, 0));
        int res = 0;
        for (int i = 1; i <= text1.length(); i++) {
            for (int j = 1; j <= text2.length(); j++) {
                if (text1[i - 1] == text2[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                }else {
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
                if (dp[i][j] > res) {
                    res = dp[i][j];
                }
            }
        }
        return res;
    }
};

int main() {
    string text1 = "ezupkr";
    string text2 = "ubmrapg";
    Solution sol;
    int len = sol.longestCommonSubsequence(text1, text2);
    cout<<len<<endl;
    return 0;
}
