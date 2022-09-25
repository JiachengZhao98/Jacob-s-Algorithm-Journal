#include "iostream"
#include "queue"
#include "stack"
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
    int sumOfLeftLeaves(TreeNode* root) {
        stack<TreeNode*> treeSta;
        int res = 0;
        if (root == nullptr) {
            return res;
        }
        treeSta.push(root);
        while (!treeSta.empty()) {
            TreeNode* node = treeSta.top();
            treeSta.pop();
            if (node->left != NULL && node->left->left == NULL && node->left->right == NULL) {
                res += node->left->val;
            }
            if (node->left) {
                treeSta.push(node->left);
            }
            if (node->right) {
                treeSta.push(node->right);
            }
        }
        return res;
    }
};