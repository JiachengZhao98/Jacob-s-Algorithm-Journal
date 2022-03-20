//
//  main.cpp
//  Leetcode_20
//
//  Created by Jiacheng Zhao on 3/20/22.
//

#include <iostream>
#include "stack"
#include "string"
using namespace std;


class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(') {
                st.push(')');
            }
            else if (s[i] == '{') {
                st.push('}');
            }
            else if (s[i] == '[') {
                st.push(']');
            }
            else if (st.empty() || st.top() != s[i]) { // when we finish traverse all the elements of left-side brackets, the first element in stack is
                                                     // actually the first element in the right-side brackets. 
                return false;
            }
            else st.pop();
        }
        return st.empty();
    }
};

