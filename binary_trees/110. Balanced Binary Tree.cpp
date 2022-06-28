#include "iostream"
#include "queue"
#include "algorithm"
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
    int subtreeDepth(TreeNode* node) {
        int depth = 0;
        queue<TreeNode*> que;
        if (node == nullptr) {
            return depth;
        }
        que.push(node);
        while (!que.empty()) {
            int size = que.size();
            for (int i = 0; i < size; i++) {
                TreeNode* Node = que.front();
                que.pop();
                if (Node->left) {
                    que.push(Node->left);
                }
                if (Node->right) {
                    que.push(Node->right);
                }
            }
            depth++;
        }
        return depth;
    }
    bool isBalanced(TreeNode* root) {
        if (root == nullptr) {
            return true;
        }
        queue<TreeNode*> que;
        que.push(root);
        while (!que.empty()) {
            TreeNode* node = que.front();
            que.pop();
            int left = subtreeDepth(node->left);
            int right = subtreeDepth(node->right);
            if (abs(left - right) > 1) return false;
            if (node->left) que.push(node->left);
            if (node->right) que.push(node->right); 
        }
        return true;
    }
};