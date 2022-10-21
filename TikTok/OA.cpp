#include "vector"
#include "string"
#include "iostream"
using namespace std;

// class Solution {
// public:
//     int ways(vector<string>& pizza, int k) {
//         int m = pizza.size(), n = pizza[0].size();
//         vector<vector<vector<int>>> dp(k, vector<vector<int>>(m, vector<int>(n, -1)));
//         vector<vector<int>> preSum(m+1, vector<int>(n+1, 0)); // preSum[r][c] is the total number of apples in pizza[r:][c:]
//         for (int r = m - 1; r >= 0; r--)
//             for (int c = n - 1; c >= 0; c--)
//                 preSum[r][c] = preSum[r][c+1] + preSum[r+1][c] - preSum[r+1][c+1] + (pizza[r][c] == 'A');
//         return dfs(m, n, k-1, 0, 0, dp, preSum);
//     }
//     int dfs(int m, int n, int k, int r, int c, vector<vector<vector<int>>>& dp, vector<vector<int>>& preSum) {
//         if (preSum[r][c] == 0) return 0; // if the remain piece has no apple -> invalid
//         if (k == 0) return 1; // found valid way after using k-1 cuts
//         if (dp[k][r][c] != -1) return dp[k][r][c];
//         int ans = 0;
//         // cut in horizontal
//         for (int nr = r + 1; nr < m; nr++)
//             if (preSum[r][c] - preSum[nr][c] > 0) // cut if the upper piece contains at least one apple
//                 ans = (ans + dfs(m, n, k - 1, nr, c, dp, preSum)) % 1000000007;
//         // cut in vertical
//         for (int nc = c + 1; nc < n; nc++)
//             if (preSum[r][c] - preSum[r][nc] > 0) // cut if the left piece contains at least one apple
//                 ans = (ans + dfs(m, n, k - 1, r, nc, dp, preSum)) % 1000000007;
//         return dp[k][r][c] = ans;
//     }
// };

class Solution {
public:
    int ways(vector<string>& pizza, int k) {
        int m = pizza.size(), n = pizza[0].size(), Mod = 1000000007;
        vector<vector<int>> preSum(m + 1, vector<int>(n + 1, 0));
        for (int i = m - 1; i >= 0; i--) {
            for (int j = n - 1; j >= 0; j--) {
                preSum[i][j] = preSum[i + 1][j] + preSum[i][j + 1] - preSum[i + 1][j + 1] + (pizza[i][j] == 'A');
            }
        }
        return dp(k - 1, 0, 0, preSum, m, n, Mod);
    }
    int dp(int k, int r, int c, vector<vector<int>>& preSum, int m, int n, int Mod) {
        if (preSum[r][c] == 0) return 0;
        if (k == 0) return 1;
        int ans = 0;
        for (int nr = r + 1; nr < m; nr++) {
            if (preSum[r][c] > preSum[nr][c]) {
                ans = (ans + dp(k - 1, nr, c, preSum, m, n, Mod)) % 1000000007;
            }
        }
        for (int nc = c + 1; nc < n; nc++) {
            if (preSum[r][c] > preSum[r][nc]) {
                ans = (ans + dp(k - 1, r, nc, preSum, m, n, Mod)) % 1000000007;
            }
        }
        return ans;
    }

};

int main() {
    Solution sol;
    vector<string> pizza = {"..A.A.AAA...AAAAAA.AA..A..A.A......A.AAA.AAAAAA.AA","A.AA.A.....AA..AA.AA.A....AAA.A........AAAAA.A.AA.","A..AA.AAA..AAAAAAAA..AA...A..A...A..AAA...AAAA..AA","....A.A.AA.AA.AA...A.AA.AAA...A....AA.......A..AA.","AAA....AA.A.A.AAA...A..A....A..AAAA...A.A.A.AAAA..","....AA..A.AA..A.A...A.A..AAAA..AAAA.A.AA..AAA...AA","A..A.AA.AA.A.A.AA..A.A..A.A.AAA....AAAAA.A.AA..A.A",".AA.A...AAAAA.A..A....A...A.AAAA.AA..A.AA.AAAA.AA.","A.AA.AAAA.....AA..AAA..AAAAAAA...AA.A..A.AAAAA.A..","A.A...A.A...A..A...A.AAAA.A..A....A..AA.AAA.AA.AA.",".A.A.A....AAA..AAA...A.AA..AAAAAAA.....AA....A....","..AAAAAA..A..A...AA.A..A.AA......A.AA....A.A.AAAA.","...A.AA.AAA.AA....A..AAAA...A..AAA.AAAA.A.....AA.A","A.AAAAA..A...AAAAAAAA.AAA.....A.AAA.AA.A..A.A.A...","A.A.AA...A.A.AA...A.AA.AA....AA...AA.A..A.AA....AA","AA.A..A.AA..AAAAA...A..AAAAA.AA..AA.AA.A..AAAAA..A","...AA....AAAA.A...AA....AAAAA.A.AAAA.A.AA..AA..AAA","..AAAA..AA..A.AA.A.A.AA...A...AAAAAAA..A.AAA..AA.A","AA....AA....AA.A......AAA...A...A.AA.A.AA.A.A.AA.A","A.AAAA..AA..A..AAA.AAA.A....AAA.....A..A.AA.A.A...","..AA...AAAAA.A.A......AA...A..AAA.AA..A.A.A.AA..A.",".......AA..AA.AAA.A....A...A.AA..A.A..AAAAAAA.AA.A",".A.AAA.AA..A.A.A.A.A.AA...AAAA.A.A.AA..A...A.AAA..","A..AAAAA.A..A..A.A..AA..A...AAA.AA.A.A.AAA..A.AA..","A.AAA.A.AAAAA....AA..A.AAA.A..AA...AA..A.A.A.AA.AA",".A..AAAA.A.A.A.A.......AAAA.AA...AA..AAA..A...A.AA","A.A.A.A..A...AA..A.AAA..AAAAA.AA.A.A.A..AA.A.A....","A..A..A.A.AA.A....A...A......A.AA.AAA..A.AA...AA..",".....A..A...A.A...A..A.AA.A...AA..AAA...AA..A.AAA.","A...AA..A..AA.A.A.AAA..AA..AAA...AAA..AAA.AAAAA...","AA...AAA.AAA...AAAA..A...A..A...AA...A..AA.A...A..","A.AA..AAAA.AA.AAA.A.AA.A..AAAAA.A...A.A...A.AA....","A.......AA....AA..AAA.AAAAAAA.A.AA..A.A.AA....AA..",".A.A...AA..AA...AA.AAAA.....A..A..A.AA.A.AA...A.AA","..AA.AA.AA..A...AA.AA.AAAAAA.....A.AA..AA......A..","AAA..AA...A....A....AA.AA.AA.A.A.A..AA.AA..AAA.AAA","..AAA.AAA.A.AA.....AAA.A.AA.AAAAA..AA..AA.........",".AA..A......A.A.AAA.AAAA...A.AAAA...AAA.AAAA.....A","AAAAAAA.AA..A....AAAA.A..AA.A....AA.A...A.A....A..",".A.A.AA..A.AA.....A.A...A.A..A...AAA..A..AA..A.AAA","AAAA....A...A.AA..AAA..A.AAA..AA.........AA.AAA.A.","......AAAA..A.AAA.A..AAA...AAAAA...A.AA..A.A.AA.A.","AA......A.AAAAAAAA..A.AAA...A.A....A.AAA.AA.A.AAA.",".A.A....A.AAA..A..AA........A.AAAA.AAA.AA....A..AA",".AA.A...AA.AAA.A....A.A...A........A.AAA......A...","..AAA....A.A...A.AA..AAA.AAAAA....AAAAA..AA.AAAA..","..A.AAA.AA..A.AA.A...A.AA....AAA.A.....AAA...A...A",".AA.AA...A....A.AA.A..A..AAA.A.A.AA.......A.A...A.","...A...A.AA.A..AAAAA...AA..A.A..AAA.AA...AA...A.A.","..AAA..A.A..A..A..AA..AA...A..AA.AAAAA.A....A..A.A"
};
    int ans = sol.ways(pizza, 3);
    cout<<ans<<endl;
}
