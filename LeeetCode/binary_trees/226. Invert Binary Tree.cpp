//
//  main.cpp
//  226. Invert Binary Tree
//
//  Created by Jiacheng Zhao on 6/20/22.
//

#include <iostream>
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
 
// Solution 1 
class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
       stack<TreeNode*> sta;
       if (root != NULL)
       {
            sta.push(root);
       }
       while (!sta.empty())
       {
        int size = sta.size();
        for (int i = 0; i < size; i++)
            {
                TreeNode* node;
                node = sta.top();
                sta.pop();
                swap(node->right, node->left);
                if (node->left)
                {
                    sta.push(node->left);
                }
                if (node->right)
                {
                    sta.push(node->right);
                }
            }
       }
       return root;
    }
};

// solution 2
class Solution2 {
public:
        TreeNode* invertTree(TreeNode* root) {
            stack<TreeNode*> sta;
            if (root != nullptr)
            {
                sta.push(root);
            }
            while (!sta.empty())
            {
                TreeNode* node = sta.top();
                if (node != NULL) 
                {
                    sta.pop();
                    if (node->right) sta.push(node->right);
                    if (node->left) sta.push(node->left);
                    sta.push(node);
                    sta.push(nullptr); // push NULL to the stack, in order to reduce the duplicate usafe of parent node
                 }
                 else 
                 {
                    sta.pop();
                    node = sta.top();
                    swap(node->left, node->right);
                    sta.pop();
                 }
            }
            return root;
    }
};
