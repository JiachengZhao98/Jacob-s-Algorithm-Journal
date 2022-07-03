//
//  main.cpp
//  amazon_subArray
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
    vector<int> longestOnes(vector<int>& nums, int k) {
        vector<int> pos;
        vector<int> pos_res;
        queue<int> subArray;
        int count = 0;
        int res = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == 0) {
                count++;
                pos.push_back(i);
            }
            subArray.push(nums[i]); // push elements of nums into queue
            if (count > k) {
                while (subArray.front() == 1) {
                    subArray.pop(); // the number of zeros is greater than K, so we need to pop out one zero. It is possible that the first a few elements of                       queue are ones, in this case we need to pop out the first a few ones.
                }
                subArray.pop(); // pop out one 0
                pos.erase(pos.begin());
                count--;  // the number of zeros minus one
            }
            if(res < subArray.size()) {
                res = subArray.size(); // record the biggest length of queue
                pos_res.clear();
                for (auto iter = pos.begin(); iter != pos.end(); ++iter) {
                    pos_res.push_back(*iter);
                }
            }
        }
        return pos_res;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {0, 0, 0, 1};
    int k = 4;
    vector<int> res;
    res = sol.longestOnes(nums, k);
    for (auto a : res) {
        cout<<a<<" ";
    }
    cout<<endl;
    return 0;
}

