//
//  main.cpp
//  637. Average of Levels in Binary Tree
//
//  Created by Jiacheng Zhao on 6/13/22.
//
#include <iostream>
#include "vector"
#include "queue"
#include "stack"
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
    vector<double> averageOfLevels(TreeNode* root) {
        queue<TreeNode*> que;
        if (root != NULL) {
            que.push(root);
        }
        vector<double> res;
        while (!que.empty()) {
            int size = que.size();
            vector<double> vec;
            for (int i = 0; i < size; i++) {
                TreeNode* node = que.front();
                que.pop();
                vec.push_back(node->val);
                if (node->left != NULL) {
                    que.push(node->left);
                }
                if (node->right != NULL) {
                    que.push(node->right);
                }
            }
            double avg = 0;
            for (auto a: vec) {
                avg += a;
            }
            res.push_back(avg / vec.size());
        }
        return res;
    }
};

