//
//  main.cpp
//  LC_121_ Best Time to Buy and Sell Stock
//
//  Created by Jiacheng Zhao on 4/3/22.
//

#include <iostream>
#include "vector"
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int low = INT_MAX;
        int res = 0;
        for (auto a : prices) {
            low = min(a, low);
            res = max(res, a - low);
        }
        return res;
    }
};

