//
//  main.cpp
//  515. Find Largest Value in Each Tree Row
//
//  Created by Jiacheng Zhao on 6/14/22.
//

#include "iostream"
#include "vector"
#include "queue"
#include "set"
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
    vector<int> largestValues(TreeNode* root) {
        queue<TreeNode*> que;
        if (root != NULL) {
            que.push(root);
        }
        vector<int> res;
        while (!que.empty()) {
            int size = que.size();
            set<int> mySet;                  // use set to automatically sort all the elements we get from the tree
            for (int i = 0; i < size; i++) {
                TreeNode* node;
                node = que.front();
                que.pop();
                mySet.insert(node->val);
                if (node->left) {
                    que.push(node->left);
                }
                if (node->right) {
                    que.push(node->right);
                }
            }
            int a = *mySet.rbegin();  // the order of set is from small to big
            res.push_back(a);
        }
        return res;
    }
};
