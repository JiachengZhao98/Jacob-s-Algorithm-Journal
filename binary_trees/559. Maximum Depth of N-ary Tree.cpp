#include "iostream"
#include "vector"
#include "queue"
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

// similiar idea and alg with LC104
class Solution {
public:
    int maxDepth(Node* root) {
        queue<Node*> que;
        if (root == nullptr) {
            return 0;
        }
        que.push(root);
        int count = 0;
        while (!que.empty()) {
            int size = que.size();
            for (int i = 0; i < size; i++) {
                Node* node = que.front();
                que.pop();
                for (int j = 0; j < node->children.size(); j++) {
                    if (node->children[j] != nullptr) {
                        que.push(node->children[j]);
                    }
                }
            }
            count++;  
        }
        return count;
        
    }
};