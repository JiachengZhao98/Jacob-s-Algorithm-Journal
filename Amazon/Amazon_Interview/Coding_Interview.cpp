#include "vector"
#include "queue"
#include "climits"
#include "stack"
#include "set"
#include "map"
#include "unordered_map"
#include "unordered_set"
#include "iostream"
using namespace::std;


 // Definition for a binary tree node.
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

    // LC 103 Zigzag level order traversal
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if (root == NULL) {
            return res;
        }
        queue<TreeNode*> myQue;
        myQue.push(root);
        int count = 0;                      // put count as a global variable in this function
        while (!myQue.empty()) {
            vector<int> vec;
            int size = myQue.size();
            for (int i = 0; i < size; i++) {
                TreeNode* temp = myQue.front();
                vec.push_back(temp->val);
                myQue.pop();
                if (temp->left) {
                    myQue.push(temp->left);  // remember to push "temp->left"!!!
                }
                if (temp->right) {
                    myQue.push(temp->right); // remember to push "temp->right"!!!
                }
            }
            count++;
            if (count % 2 == 0) {
                reverse(vec.begin(), vec.end());
            }
            res.push_back(vec);
        }
        return res;
    }
    
    // 242. Valid Anagram
    bool isAnagram(string s, string t) {
        unordered_map<char, int> myMap;
        for (int i = 0; i < s.size(); i++) {
            if (myMap.find(s[i]) == myMap.end()) {
                myMap.insert(pair<char, int>(s[i], 1));
            }
            else myMap.find(s[i])->second++;
        }
        for (int i = 0; i < t.size(); i++) {
            if (myMap.find(t[i]) == myMap.end()) {
                return false;
            }
            else myMap.find(t[i])->second--;
            if (myMap.find(t[i])->second == 0) {
                myMap.erase(t[i]);
            }
        }
        if (myMap.empty()) {
            return true;
        }
        else return false;
    }
    
    bool isAnagram_2(string s, string t) {
        int record[26] = {0};
        
        for (int i =0; i < s.size(); i++) {
            record[s[i] - 'a']++;
        }
        for (int i = 0; i < t.size(); i++) {
            record[t[i] - 'a']--;
        }
        for (int i = 0; i < 26; i++) {
            if(record[i] != 0) {
                return false;
            }
        }
        return true;
    }
    
    //LC 64 Min Path Sum
    // DFS exceeds time limit
    int res = INT_MAX;
    void dfs(vector<vector<int>>& grid, int i, int j, int sum) {
        if (i < 0 || j < 0 || i >= grid.size() || j >= grid[0].size()) {
            return;
        }
        sum += grid[i][j];
        if (i == grid.size() - 1 && j == grid[0].size() - 1) {
            res = res > sum ? sum : sum;
            return;
        }
        dfs(grid, i + 1, j, sum);
        dfs(grid, i, j + 1, sum);
    }
    
    int minPathSum_notPass(vector<vector<int>>& grid) {
        dfs(grid, 0, 0, 0);
        return res;
    }

    // Dynamic Programming
    int minPathSum(vector<vector<int>>& grid) {
        vector<vector<int>> dp (grid.size(), vector<int>(grid[0].size(), 0));
        for (int i = grid.size() - 1; i >= 0; i--) {
            for (int j = grid[0].size() - 1; j >= 0; j--) {
                if (i != grid.size() - 1 && j == grid[0].size() - 1) {
                    dp[i][j] = grid[i][j] + dp[i + 1][j];
                }
                else if (i == grid.size() - 1 && j != grid[0].size() - 1) {
                    dp[i][j] = grid[i][j] + dp[i][j + 1];
                }
                else if (i != grid.size() - 1 && j != grid[0].size() - 1) {
                    dp[i][j] = grid[i][j] + min(dp[i][j + 1], dp[i + 1][j]);
                }
                else dp[i][j] = grid[i][j];
            }
        }
        return dp[0][0];
    }


};

int main() {
    
}


