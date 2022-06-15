//
//  main.cpp
//  429. N-ary Tree Level Order Traversal
//
//  Created by Jiacheng Zhao on 6/14/22.
//

#include <iostream>
#include "vector"
#include "queue"
#include "stack"
using namespace std;


// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};


class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        queue<Node*> que;
        if (root != NULL) {
            que.push(root);
        }
        vector<vector<int>> res;
        while (!que.empty()) {
            int size = que.size();
            vector<int> vec;
            for (int i = 0; i < size; i++) {
                Node* node;
                node = que.front();
                que.pop();
                vec.push_back(node->val);
                for (int j = 0; j < node->children.size(); j++) {
                    if (node->children[j] != NULL ) {
                        que.push(node->children[j]);
                    }
                }
            }
            res.push_back(vec);
        }
        return res;
    }
};
