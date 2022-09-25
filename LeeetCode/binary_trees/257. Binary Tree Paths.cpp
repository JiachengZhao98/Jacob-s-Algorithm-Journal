#include "iostream"
#include "string"
#include "stack"
#include "vector"
using namespace std;

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
    vector<string> binaryTreePaths(TreeNode* root) {
        stack<TreeNode*> TNsta;
        vector<string> res;
        stack<string> path;
        if (root == nullptr) {
            return res;
        }
        TNsta.push(root);
        path.push(to_string(root->val));  // push root->val to path, not res! because at this time the entire path is not yet calculated 
        while (!TNsta.empty()) {
            TreeNode* node = TNsta.top(); 
            TNsta.pop();
            string sPath = path.top(); 
            path.pop();
            if (node->left == nullptr && node->right == nullptr) {
                res.push_back(sPath);
            }
            if (node->left) {
                TNsta.push(node->left);
                path.push(sPath + "->" + to_string(node->left->val));
            }
            if (node->right) {
                TNsta.push(node->right);
                path.push(sPath + "->" + to_string(node->right->val));
            }   
        }
        return res;
    }
};