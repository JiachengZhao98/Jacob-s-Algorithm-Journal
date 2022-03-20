//
//  main.cpp
//  leetcode_225
//
//  Created by Jiacheng Zhao on 3/20/22.
//

#include <iostream>
#include "queue"
#include "stack"
using namespace std;

class MyStack {
public:
    queue<int> qOut;
    MyStack() {
        
    }
    
    void push(int x) {
        qOut.push(x);
    }
    
    int pop() {
        int i = 0;
        while (i < (qOut.size() - 1)) { // this loop will change the order of queue, putting the last element in the front of this queue. This element is also the first
                                      // one in stack.
            int temp = qOut.front();
            qOut.pop();
            qOut.push(temp);
        }
        int res = qOut.front();
        qOut.pop();                    // now the last element in this queue is the first element in stack.
        return res;
    }
    
    int top() {
        return qOut.back();
    }
    bool empty() {
        if (qOut.empty()) {
            return true;
        }
        else return false;
    }
};
