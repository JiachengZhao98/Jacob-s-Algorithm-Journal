//
//  main.cpp
//  Leetcode_1047
//
//  Created by Jiacheng Zhao on 3/20/22.
//

#include <iostream>
#include "stack"
#include "queue"
using namespace std;
class Solution {
public:
    string removeDuplicates(string s) {
        stack<char> mySta;
        for (int i = 0; i < s.size(); i++) {
            if (mySta.empty() || s[i] != mySta.top()) {
                mySta.push(s[i]);
            }
            else mySta.pop();  // when the top element of mySta is same to the next element of string s, it means we find two adjacent duplicate elements
        }
        string res;
        while (!mySta.empty()) {
            res.push_back(mySta.top());
            mySta.pop();
        }
        reverse(res.begin(), res.end());  // reverse the order of string res, because the original order of res is opposite to the relative order of s
        return res;
    }
};

