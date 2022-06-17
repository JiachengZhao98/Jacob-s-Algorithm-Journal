//
//  main.cpp
//  116. Populating Next Right Pointers in Each Node
//
//  Created by Jiacheng Zhao on 6/15/22.
//

#include <iostream>
#include "vector"
#include "queue"
using namespace std;


// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};


class Solution {
public:
    Node* connect(Node* root) {
        queue<Node*> que;
        if (root != NULL) {
            que.push(root);
        }
        while (!que.empty()) {
            int size = que.size();
            Node* node;
            for (int i = 0; i < size; i++) {
                if (que.front() == NULL) {
                    break;
                }
                node = que.front();
                que.pop();
                if (!que.empty()) {
                    node->next = que.front();
                }
                if (node->left) {
                    que.push(node->left);
                }
                if (node->right) {
                    que.push(node->right);
                }
            }
              node->next = NULL;
        }
        return root;
    }
};

