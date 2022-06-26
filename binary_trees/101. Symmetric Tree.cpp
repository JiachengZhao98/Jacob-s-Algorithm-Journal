#include "iostream"
#include "queue"
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
 
 // solution 1
class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        queue<TreeNode*> que;
        queue<TreeNode*> que2;    
        que.push(root);
        que2.push(root);
        if (root->left == NULL && root->right == NULL)
        {
            return true;
        }
        while (!que.empty())
        {
                TreeNode* node = que.front();
                que.pop();
                TreeNode* node2 = que2.front();
                que2.pop();
                if (node == NULL && node2 == NULL) continue;
                if ( (node == NULL && node2 != NULL) || (node != NULL && node2 == NULL) || (node->val != node2->val))
                {
                    return false;
                }
                    que.push(node->left);
                    que2.push(node2->right);
                
                    que.push(node->right);
                    que2.push(node2->left);
            
        }
        return true;
    }
};

// solution 2
class solution2
{
public:
    bool compare(TreeNode* left, TreeNode* right) {
        if (left == NULL && right != NULL) return false;
        if (left != NULL && right == nullptr) return false;
        if (left == nullptr && right == nullptr) return true;
        if (left->val != right->val) return false;

        bool outside = compare(left->left, right->right);
        bool inside = compare(left->right, right->left);
        bool isSame = outside && inside;
        return isSame;
    }
    bool isSymmetric(TreeNode* root) {
        if (root->left == nullptr && root->right == nullptr) return true;
        return compare(root->left, root->right);    
    }
};

