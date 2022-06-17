//
//  main.cpp
//  117. Populating Next Right Pointers in Each Node II
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


// the same code as answer to prob 116
class Solution {
public:
    Node* connect(Node* root) {
        
    }
};
