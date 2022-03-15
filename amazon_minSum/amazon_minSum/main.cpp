//
//  main.cpp
//  amazon_minSum
//
//  Created by Jiacheng Zhao on 3/15/22.
//

#include <iostream>
#include "vector"
#include "algorithm"
#include "queue"
using namespace std;

class Solution {
public:
    int minSum(vector<int>& nums, int k) {
        int sumAll = 0;
        int sum = 0;
        int count = 0;
        int res = INT_MIN;
        queue<int> q;

        for(auto a : nums) {
            count++;
            q.push(a);
            sum += a;
            sumAll += a; // calculate the sum of all elements in nums
            if (count > k) {
                sum -= q.front(); // remove the first element of queue
                q.pop();          // move the slide window to next position
                count--;
            }
            res = sum > res ? sum : res;  // memorize the biggest sum of elements in the slide window
        }
        return sumAll - res;
    }
};


int main() {
    Solution sol;
    vector<int> nums = {7,3,6,1};
    int k = 1;
    int res;
    res = sol.minSum(nums, k);
    cout<<res<<endl;
    return 0;
}
