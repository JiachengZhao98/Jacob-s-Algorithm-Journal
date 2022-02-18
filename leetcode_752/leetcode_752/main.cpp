#include "iostream"
#include "stdio.h"
#include "cmath"
#include "string"
#include "string.h"
#include "array"
#include "set"
#include "map"
#include "vector"
#include "algorithm"
#include "stack"
#include "queue"
#include "unordered_set"
using namespace std;

class Solution {
public:
    string plus_One(string str, int digit) {
        str[digit] = (str[digit] + 1 > '9') ? '0' : (str[digit] + 1);
        return str;
    }
    
    string minus_One(string str, int digit) {
        str[digit] = (str[digit] - 1 < '0') ? '9' : (str[digit] - 1);
        return str;
    }
    
    int openLock(vector<string>& deadends, string target) {
        
        // Init : Add deadends & 0000 to visited
        
        unordered_set<string> visited ={deadends.begin(), deadends.end()};
        if (visited.find("0000") != visited.end()) {
            return -1;
        }
        visited.insert("0000");
        int step = 0;
        if (target == "0000") {
            return step;
        }
        queue<string> q;
        q.push("0000");
        
        while (!q.empty()) {
            step += 1;
            int size = q.size();
            for (int i = 0; i < size; i++) {
                string cur = q.front();
                for (int digit = 0; digit < 4; digit++) {
                    string str1 = cur;
                    string str2 = cur;
                    str1 = plus_One(str1, digit);
                    str2 = minus_One(str2, digit);
                    if (str1 == target || str2 == target) {
                        return step;
                    }
                    if (visited.find(str1) == visited.end()) {
                        visited.insert(str1);
                        q.push(str1);
                    }
                    if (visited.find(str2) == visited.end()) {
                        visited.insert(str2);
                        q.push(str2);
                    }
                }
                q.pop();
                }
        }
        return -1;
    }
};


