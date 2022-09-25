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
    TreeNode* traversal(vector<int>& inorder, vector<int>& postorder) {
        if (postorder.size() == 0) {
            return nullptr;
        }
        int rootValue = postorder[postorder.size() - 1];  // the last value in postorder vector is root
        TreeNode* root = new TreeNode(rootValue);
        if (postorder.size() == 1) {                      
            return root;                                  // if there is only one value in postorder vector
        }
        int delimiterIndex;
        for (delimiterIndex = 0; delimiterIndex < postorder.size(); delimiterIndex++) {
            if (inorder[delimiterIndex] == rootValue) {
                break;
            }
        }
        vector<int> leftInorder(inorder.begin(), inorder.begin() + delimiterIndex);
        vector<int> rightInorder(inorder.begin() + 1 + delimiterIndex, inorder.end());

        postorder.resize(postorder.size() - 1);

        vector<int> leftPostorder(postorder.begin(), postorder.begin() + leftInorder.size());
        vector<int> rightPostorder(postorder.begin() + leftInorder.size(), postorder.end());

        root->left = traversal(leftInorder, leftPostorder);
        root->right = traversal(rightInorder, rightPostorder);
    
        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        TreeNode* root = traversal(inorder, postorder);
        return root;
    }
};