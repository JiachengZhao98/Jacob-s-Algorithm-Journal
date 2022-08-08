#include "vector"
#include "iostream"
#include "climits"
#include "queue"
#include "set"
using namespace std;

class Solution {
public:
    vector<int> maxConsecutiveNumber(vector<int>& nums, int k) {
        vector<int> res;
        if (nums.size() == 0 || k == 0) {
            return res;
        }
        int maxLength = 0;
        queue<int> recordSubarrayLength;
        set<int> recordIndex;
        int j = 0;
        int count = 0;
        for (; j < nums.size(); j++) {
                recordSubarrayLength.push(nums[j]);
                if (nums[j] == 0) {
                    count++;
                    recordIndex.insert(j);
                }
                if (count > k) {
                    while (recordSubarrayLength.front() == 1) {
                    recordSubarrayLength.pop();
                    }
                    recordSubarrayLength.pop();
                    recordIndex.erase(recordIndex.begin());
                    count--;
                }
                if (maxLength < recordSubarrayLength.size()) {
                res.clear();
                for (auto iter = recordIndex.begin(); iter != recordIndex.end(); iter++) {
                    res.push_back(*iter);
                }
                maxLength = recordSubarrayLength.size();
                }
            }
        return res;
    }
};  

int main() {
    Solution sol;
    vector<int> nums = {0,0,0,1};
    vector<int> res;
    res = sol.maxConsecutiveNumber(nums, 4);
    for (auto a : res) {
        cout<<a<<" ";
    }
    cout<<endl;
    return 0;
}