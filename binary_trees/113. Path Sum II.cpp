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
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> res;
        if (root == nullptr) {
            return res;
        }
        stack<int> sum;
        stack<pair<TreeNode*, vector<int>>> treeSta;
        sum.push(root->val);
        vector<int> temp;
        temp.push_back(root->val);
        treeSta.push(pair<TreeNode*, vector<int>>(root, temp));
        while (!treeSta.empty()) {
            pair<TreeNode*, vector<int>> nodeP = treeSta.top();
            treeSta.pop();
            int tempSum = sum.top();
            sum.pop();
            if (nodeP.first->left == nullptr && nodeP.first->right == nullptr && tempSum == targetSum) {
                res.push_back(nodeP.second);
            }
            if (nodeP.first->left) {
                vector<int> temp = nodeP.second;
                temp.push_back(nodeP.first->left->val);
                treeSta.push(pair<TreeNode*, vector<int>>(nodeP.first->left, temp));
                sum.push(tempSum + nodeP.first->left->val);
            }
            if (nodeP.first->right) {
                vector<int> temp = nodeP.second;
                temp.push_back(nodeP.first->right->val);
                treeSta.push(pair<TreeNode*, vector<int>>(nodeP.first->right, temp));
                sum.push(tempSum + nodeP.first->right->val);
            }
        }
        return res;
    }
};