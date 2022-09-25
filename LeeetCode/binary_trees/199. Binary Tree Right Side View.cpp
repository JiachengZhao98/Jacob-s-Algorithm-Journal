//
//  main.cpp
//  199. Binary Tree Right Side View
//
//  Created by Jiacheng Zhao on 6/8/22.
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
    vector<int> rightSideView(TreeNode* root) {
        queue<TreeNode*> que;
        if (root != NULL) {
            que.push(root);
        }
        vector<int> res;
        while (!que.empty()) {
            int size = que.size();
            vector<int> vec;
            for (int i = 0; i < size; i++) {
                TreeNode* node = que.front();
                vec.push_back(node->val);
                que.pop();
                if (node->right) {
                    que.push(node->right);
                }
                if (node->left) {
                    que.push(node->left);
                }
            }
            res.push_back(vec[0]); //store the rightest node's value of each level, which is vec[0]: the 1st element in                        //vector
        }
        return res;
    } };
