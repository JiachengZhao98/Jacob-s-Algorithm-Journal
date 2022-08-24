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
        traversal(root->left, res);  // left
        traversal(root->right, res);  // right
        res.push_back(root->val);     // mid
    }
    
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> result;
        traversal(root, result);
        return result;
    }
    
};

