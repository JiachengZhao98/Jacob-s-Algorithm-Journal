#include "vector"
#include "queue"
#include "iostream"
using namespace std;

class Solution{
public:
    int res = 0;
    void dfs(vector<vector<int>>& lot, int i, int j, vector<vector<bool>>& visited, int step) {
        int m = lot.size(), n = lot[0].size();
        if (i < 0 || j < 0 || i >= m || j >= n) {
            return ;
        }
        if (lot[i][j] == 0) {
            return;
        }
        if (visited[i][j]) {
            return ;
        }
        visited[i][j] = true;
        step++;
        if (lot[i][j] == 9) {
            res = step;
            return;
        }
        dfs(lot, i - 1, j, visited, step);
        dfs(lot, i + 1, j, visited, step);
        dfs(lot, i, j - 1, visited, step);
        dfs(lot, i, j + 1, visited, step);
    }

    int shortestPath(vector<vector<int>>& lot) {
        vector<vector<bool>> visited(lot.size(), vector<bool>(lot[0].size(), false));
        dfs(lot, 0, 0, visited, 0);
        return res - 1;
    }
};

int main() {
    Solution sol;
    int ans;
    vector<vector<int>> lot {{1,0,0}, {1,0,0}, {1,9,1}};
    ans = sol.shortestPath(lot);
    cout<<ans<<endl;

}