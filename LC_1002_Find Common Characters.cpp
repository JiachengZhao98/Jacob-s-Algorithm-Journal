//
//  main.cpp
//  LC_1002_Find Common Characters
//
//  Created by Jiacheng Zhao on 4/3/22.
//

#include <iostream>
#include "vector"
#include "string"

using namespace std;

class Solution {
public:
    vector<string> commonChars(vector<string>& words) {
        vector<string> result;
        if (words.size() == 0) {
            return result;
        }
        int hash[26] = {0};
        for (int i = 0; i < words[0].size(); i++) {
            hash[words[0][i] - 'a']++;
        }
                
        int hashOtherStr[26] = {0};
        for (int i = 1; i < words.size(); i++) {
            memset(hashOtherStr, 0, 26 * sizeof(int));
            for (int j = 0; j < words[i].size(); j++) {
                hashOtherStr[words[i][j] - 'a']++;
            }
            for (int k = 0; k < 26; k++) {
                hash[k] = min(hash[k], hashOtherStr[k]);
            }
        }
        for (int k = 0; k < 26; k++) {
            while (hash[k] > 0) {
                string s(1, 'a' + k);
                result.push_back(s);
                hash[k]--;
            }
        }
        return result;
    }
};
