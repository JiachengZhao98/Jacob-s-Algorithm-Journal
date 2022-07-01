#include "iostream"
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
    bool hasPathSum(TreeNode* root, int targetSum) {
        if (root == nullptr) {
            return false;
        }
        stack<TreeNode*> treeSta;
        treeSta.push(root);
        stack<int> res;
        res.push(root->val);
        while (!treeSta.empty()) {
            TreeNode* node = treeSta.top();
            treeSta.pop();
            int temp = res.top();
            res.pop();
            if (node->left == nullptr && node->right == nullptr && temp == targetSum) {
                return true;
            }
            if (node->left) {
                treeSta.push(node->left);
                res.push(temp + node->left->val);
            }
            if (node->right) {
                treeSta.push(node->right);
                res.push(temp + node->right->val);
            }
        }
        return false;
    }
};