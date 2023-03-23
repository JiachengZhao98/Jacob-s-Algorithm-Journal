#include "vector"
#include "queue"
#include "set"
#include "unordered_set"
#include "map"
#include "unordered_map"
#include "string"
#include "iostream"
using namespace std;


struct TreeNode {
    int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  };
class Solution {
public:
    // bool isCousins(TreeNode* root, int x, int y) {
    //     vector<int> rec(2, -1);
    //     if (root == nullptr){
    //         return false;
    //     }
    //     int depth = 0;
    //     queue<pair<TreeNode*, int>> que;
    //     que.push({root, depth});
    //     while (!que.empty()) {
    //         auto temp = que.front();
    //         que.pop();
    //         if (temp.first->val == x) {
    //             rec[0] = temp.second;
    //         }
    //         if (temp.first->val == y) {
    //             rec[1] = temp.second;
    //         }
    //         if (rec[0] != -1 && rec[1] != -1) break;
    //         if (temp.first->left) {
    //             int de = temp.second;
    //             de++;
    //             que.push(pair<temp.first->left, de>);
    //         }
    //         if (temp.first->right) {
    //             int fe = temp.second;
    //             fe++;
    //             que.push(pair<temp.first->right, fe>);
    //         }
    //     }
    //     return (rec[0] == rec[1]);
    // }

    // LC 127. Word Ladder
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> s;
        for (auto a : wordList) {
            s.insert(a);
        }
        if (s.find(endWord) == s.end()) return 0;

        unordered_set<string> visited;
        visited.insert(beginWord);
        queue<string> q;
        q.push(beginWord);

        int step = 1;

        while (!q.empty()) {
            int size = q.size();
            for (int i = 0; i < size; i++) {
                string front = q.front();
                q.pop();
                if (front == endWord) {
                    return step;
                }
                for (int j = 0; j < beginWord.size(); j++) {
                    char temp = front[j];
                    for (char k = 'a'; k <= 'z'; k++) {
                        front[j] = k;
                        if (s.find(front) != s.end() && visited.find(front) == visited.end()) {
                            q.push(front);
                            visited.insert(front);
                        }
                    }
                    front[j] = temp;
                }
            }
            step++;
            if (q.empty()) step = 0;
        }
        return step;
    }

    // LC 103. Binary Tree Zigzag Level Order Traversal
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if (root == nullptr) return res;
        int counter = 0;
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            int size = q.size();
            vector<int> vec;
            for (int i = 0; i < size; i++) {
                TreeNode* node = q.front();
                q.pop();
                vec.push_back(node->val);
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }
            if (counter % 2) reverse(vec.begin(), vec.end());
            res.push_back(vec);
            counter++;
        }
        return res;
    }


    // LC 200. Number of Islands

    void dfs(vector<vector<char>>& grid, int i, int j, vector<vector<bool>>& visited) {
        if (i < 0 || j < 0 || i >= grid.size() || j >= grid[0].size()) {
            return;
        }
        if (visited[i][j]) return;
        if (grid[i][j] == '0') return;
        visited[i][j] = true;
        dfs(grid, i + 1, j, visited);
        dfs(grid, i - 1, j, visited);
        dfs(grid, i, j + 1, visited);
        dfs(grid, i, j - 1, visited);
    }
    int numIslands(vector<vector<char>>& grid) {
        int result = 0;
        vector<vector<bool>> visited(grid.size(), vector<bool>(grid[0].size(), false));
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] == '1' && visited[i][j] == false) {
                    dfs(grid, i, j, visited);
                    result++;
                }
            }
        }
        return result;
    }

    // LC 386. Lexicographical Numbers
    vector<int> lexicalOrder(int n) {
        vector<int> order = {1};
        while (order.size() < n) {
            int next = order[order.size() - 1] * 10;
            while (next > n) {
                next /= 10;
                next++;
                while (next % 10 == 0) {
                    next /= 10;
                }
            }
            order.push_back(next);
        }
        return order;
    }

    // DFS approach
    void dfs_for_386(int target, int n, vector<int>& res) {
        if (target > n) return;
        res.push_back(target);
        dfs_for_386(target * 10, n, res);
        if (target % 10 != 9) dfs_for_386(target + 1, n, res);
    }
    vector<int> lexicalOrder_dfs(int n) {
        vector<int> res;
        dfs_for_386(1, n, res);
        return res;
    }


    // LC 983. Minimum Cost For Tickets

    // approach: Dynamic programming
    // transition equation:
    // totalcost[i] = totalCost[i - 1] + cost[0] + totalCost[i - 7] + cost[1] + totalCost[i - 30] + cost[2]


    int MIN_3(int a, int b, int c) {
        int res;
        res = min(a, b);
        res = min(res, c);
        return res;
    }
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        vector<int> totalCost(days[days.size() - 1] + 1, 0);
        unordered_set<int> mySet;
        for (auto a : days) {
            mySet.insert(a);
        }
        for (int i = 1; i <= days[days.size() - 1]; i++) {
            if (mySet.find(i) == mySet.end()) {
                totalCost[i] = totalCost[i - 1];   // the cost remains unchanged if we don't need to travel
            }
            else {
                totalCost[i] = MIN_3(  // the cost for "travel and/or rest to day i" is decided by the 3 following costs
                totalCost[max(0, i - 1)] + costs[0],    // if we buy one-day pass
                totalCost[max(0, i - 7)] + costs[1],    // if we buy one-week pass
                totalCost[max(0, i - 30)] + costs[2]);  // if we buy one-month pass
            }
        }
        return totalCost[days[days.size() - 1]];
    }


    // LC 694. Number of Distinct Islands
    void dfs_for_694(vector<vector<int>>& grid, int i, int j,vector<vector<bool>>& visited, string& ds, string dir) {
        if (i < 0 || j < 0 || i >= grid.size() || j >= grid[0].size()) {
            return;
        }
        if (visited[i][j]) return;
        if (grid[i][j] == 0) return;
        visited[i][j] = true;
        ds += dir;
        dfs_for_694(grid, i + 1, j, visited, ds, "E");
        dfs_for_694(grid, i - 1, j, visited, ds, "W");
        dfs_for_694(grid, i, j + 1, visited, ds, "N");
        dfs_for_694(grid, i, j - 1, visited, ds, "S");
        ds += "B";
    }
    int numDistinctIslands(vector<vector<int>>& grid) {
        set<string> mySet;
        vector<vector<bool>> visited(grid.size(), vector<bool>(grid[0].size(), false));
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] == 1 && visited[i][j] == false) {
                    string ds = "";
                    dfs_for_694(grid, i, j, visited, ds, "o");
                    cout<<ds<<endl;
                    mySet.insert(ds);
                }
            }
        }
        return mySet.size();
    }

};

int main() {
    Solution sol;
    vector<vector<int>> grid{{1,1,0,0,0},{1,1,0,0,0},{0,0,0,1,1},{0,0,0,1,1}};
    int ans = sol.numDistinctIslands(grid);
    cout<<ans<<endl;
}
