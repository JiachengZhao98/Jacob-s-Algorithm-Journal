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
    TreeNode* traversal(vector<int>& preorder, vector<int>& inorder) {
        if (preorder.size() == 0) {
            return nullptr;
        }
        int rootValue = preorder[0];                      // the first value in preorder vector is root
        TreeNode* root = new TreeNode(rootValue);
        if (preorder.size() == 1) {                      
            return root;                                  // if there is only one value in postorder vector
        }
        int delimiterIndex;
        for (delimiterIndex = 0; delimiterIndex < preorder.size(); delimiterIndex++) {
            if (inorder[delimiterIndex] == rootValue) {
                break;
            }
        }
        vector<int> leftInorder(inorder.begin(), inorder.begin() + delimiterIndex);
        vector<int> rightInorder(inorder.begin() + 1 + delimiterIndex, inorder.end());

        reverse(preorder.begin(), preorder.end());
        preorder.resize(preorder.size() - 1);
        reverse(preorder.begin(), preorder.end());

        vector<int> leftPreorder(preorder.begin(), preorder.begin() + leftInorder.size());
        vector<int> rightPreorder(preorder.begin() + leftInorder.size(), preorder.end());

        root->left = traversal(leftPreorder, leftInorder);
        root->right = traversal(rightPreorder, rightInorder);
    
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        TreeNode* root = traversal(preorder, inorder);
        return root;
    }
};