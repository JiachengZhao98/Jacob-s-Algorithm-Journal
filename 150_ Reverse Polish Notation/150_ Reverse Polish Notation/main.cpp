//
//  main.cpp
//  150_ Reverse Polish Notation
//
//  Created by Jiacheng Zhao on 3/22/22.
//

#include <iostream>
#include "stack"
#include "vector"
#include "string"
using namespace std;

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> mySta;
        int res = -1;
        for (int i = 0; i < tokens.size(); i++) {
            if (tokens[i] == "+" || tokens[i] == "-" || tokens[i] == "*" || tokens[i] == "/") {
                int temp1 = mySta.top();
                mySta.pop();
                int temp2 = mySta.top();
                mySta.pop();
                char *operator1 = (char *)tokens[i].c_str();
                switch (*operator1) {
                    case '*':
                        res = temp1 * temp2;
                        mySta.push(res);
                        break;
                    case '+':
                        res = temp1 + temp2;
                        mySta.push(res);
                        break;
                    case '-':
                        res = temp2 - temp1;
                        mySta.push(res);
                        break;
                    case '/':
                        res = temp2 / temp1;
                        mySta.push(res);
                        break;
                }
            }
            else mySta.push(stoi(tokens[i]));
        }
        return mySta.top();
    }
};
int main() {
    // insert code here...
    
    return 0;
}
