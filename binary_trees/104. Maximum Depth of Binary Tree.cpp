//
//  main.cpp
//  104. Maximum Depth of Binary Tree
//
//  Created by Jiacheng Zhao on 6/16/22.
//

#include <iostream>
#include "vector"
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
    int maxDepth(TreeNode* root) {
        queue<TreeNode*> que;
        if (root == NULL) {
            return 0;
        }
        else que.push(root);
        int res = 0;
        while (!que.empty()) {
            int size = que.size();
            for (int i = 0; i < size; i++) {
                TreeNode* node = que.front();
                que.pop();
                if (node->left) {
                    que.push(node->left);
                }
                if (node->right) {
                    que.push(node->right);
                }
            }
            res++; // use res to record the number of level of this binary tree. This alg use the idea of level-order traversal. The biggest number of level of this binary tree is the length.
        }
        return res;
    }
};
