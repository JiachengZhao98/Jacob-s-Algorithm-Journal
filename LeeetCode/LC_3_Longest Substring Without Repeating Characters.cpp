//
//  main.cpp
//  LC3_Longest Substring Without Repeating Characters
//
//  Created by Jiacheng Zhao on 3/24/22.
//

#include <iostream>
#include "set"
#include "string"
#include "unordered_map"
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> myMap;
        int left = 0, right = 0;
        int res = 0;
        while (right < s.size()) {
            char c = s[right];
            right++;
            myMap[c]++;
            while (myMap[c] > 1) { // we should use while loop here, 'cause there may be several repeated s[right],                         // like "aaaasb...". We shuold eliminate all the repeated ones
                myMap[s[left]]--;
                left++;
            }
            res = max(res, right - left);
        }
        return res;
    }
};
