#include "vector"
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
 
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
         vector<vector<int>> res;
        if (root == nullptr) {
            return res;
        }
        queue<TreeNode*> myQue;
        myQue.push(root);
        while (!myQue.empty()) {
            int size = myQue.size();
            vector<int> tempRes;
            for (int i = 0; i< size; i++) {
                TreeNode* temp = myQue.front();
                myQue.pop();
                tempRes.push_back(temp->val);
                if (temp->left) myQue.push(temp->left);
                if (temp->right) myQue.push(temp->right);
            }
            res.push_back(tempRes);
        }
        return res;
    }
};