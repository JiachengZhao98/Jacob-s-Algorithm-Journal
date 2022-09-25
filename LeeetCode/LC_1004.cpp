//
//  main.cpp
//  Leetcode_1004
//
//  Created by Jiacheng Zhao on 3/13/22.
//

#include <iostream>
#include "vector"
#include "algorithm"
#include "queue"

using namespace std;

class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        if (nums.size() == 0) {
            return 0;
        }
        queue<int> subArray;
        int count = 0;
        int res = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == 0) {
                count++;
            }
            subArray.push(nums[i]); // push elements of nums into queue
            if (count > k) {
                while (subArray.front() == 1) {
                    subArray.pop(); // the number of zeros is greater than K, so we need to pop out one zero. It is possible that the first a few elements of                       queue are ones, in this case we need to pop out the first a few ones.
                }
                subArray.pop(); // pop out one 0
                count--;  // the number of zeros minus one
            }
            if(res < subArray.size()) {
                res = subArray.size(); // record the biggest length of queue
            }
        }
        return res;
    }
};
