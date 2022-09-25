#include "iostream"
#include "queue"
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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        queue<TreeNode*> que;
        queue<TreeNode*> que2; 
        if (p == NULL && q == NULL)
        {
            return true;
        }   
        que.push(p);
        que2.push(q);
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
                    que2.push(node2->left);
                
                    que.push(node->right);
                    que2.push(node2->right);
            
        }
        return true;
    }
};