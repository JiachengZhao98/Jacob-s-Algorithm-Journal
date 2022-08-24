#include "iostream"
#include "vector"
using namespace std;


//Definition for a binary tree node.
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
    void traversal(TreeNode* root, vector<int>& res) {
        if (root == NULL) {
            return;
        }
        res.push_back(root->val);  // mid
        traversal(root->left, res);  // left
        traversal(root->right, res); // right
    }
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> res;
        traversal(root, res);
        return res;
    }
};
