//
//  main.cpp
//  102. Binary Tree Level Order Traversal
//
//  Created by Jiacheng Zhao on 6/7/22.
//

#include <iostream>
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
        queue<TreeNode*> que;  // in fact level order travrsal use the idea of BFS, in this case we use queue to store the node we
                             // encounter and pop them
        if (root != NULL) {
            que.push(root);
        }
        vector<vector<int>> res;
        while (!que.empty()) {
            int size = que.size();
            vector<int> vec;
            for (int i = 0; i < size; i++) {
                vec.push_back(que.front()->val);
                TreeNode* node = que.front();
                que.pop();
                if (node->left) {
                    que.push(node->left);
                }
                if (node->right) {
                    que.push(node->right);
                }
            }
            res.push_back(vec);
        }
        return res;
    }
};
