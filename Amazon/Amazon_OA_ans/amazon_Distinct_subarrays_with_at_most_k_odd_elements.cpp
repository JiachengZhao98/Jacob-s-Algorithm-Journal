#include "vector"
#include "string"
#include "unordered_set"
#include "iostream"
using namespace std;

class Solution {
public:
    int isOdd(int num) {
        return num % 2;
    }
    int Distinct_subarrays_with_at_most_k_odd_elements(vector<int>& nums, int k) {
        if (k == 0) {
            return 0;
        }
        unordered_set<string> mySet;
        for (int i = 0; i < nums.size(); i++) {
            int count = 0;
            string subarray;
            for (int j = i; j < nums.size(); j++) {
                if (isOdd(nums[j])) {
                    count++;
                    if (count > k) {
                        break;
                    }
                }
                subarray += char(nums[j]) + ",";
                mySet.insert(subarray);
            }
        }
        return mySet.size();
    }
};

int main () {
    Solution sol;
    vector<int> nums = {3,2,3,2};
    int res = sol.Distinct_subarrays_with_at_most_k_odd_elements(nums, 1);
    cout<<res<<endl;
    return 0;
}