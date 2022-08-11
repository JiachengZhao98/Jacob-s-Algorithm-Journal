#include "vector"
#include "set"
#include "iostream"
#include "unordered_map"
using namespace std;

class Solution {
public:
    int maxSubarrrayWithK(vector<int>& nums, int k) {
        int res = INT_MIN;
        for (int i = 0; i < nums.size() - k; i++) {
            int j = i;
            int temp = 0;
            set<int> mySet;
            while (j < i + k) {
                mySet.insert(nums[j]);
                temp += nums[j];
                j++;
            }
            if (mySet.size() == k) {
                res = res < temp ? temp : res;
            }
        }
        return res;
    }
};

class Solution_2 {
public:
    int maxSubarrrayWithK(vector<int>& nums, int k) {
        unordered_map<int, int> myMap;
        int res = INT_MIN, sum = 0;
        for (int i = 0; i < k; i++) {
            sum += nums[i];
            if (myMap.find(nums[i]) == myMap.end()) {
                myMap.insert(pair<int, int>(nums[i], 1));
            }
            else {
                myMap.find(nums[i])->second++;
            }
        }
        if (myMap.size() == k) {
            res = sum;
        }
        for (int i = k; i < nums.size(); i++) {
            sum = sum + nums[i] - nums[i - k];
            if (myMap.find(nums[i]) == myMap.end()) {
                myMap.insert(pair<int, int>(nums[i], 1));
            }
            else if (myMap.find(nums[i]) != myMap.end()) {
                myMap.find(nums[i])->second++;
            }
            myMap.find(nums[i - k])->second--;
            if (myMap.find(nums[i - k])->second == 0) {
                myMap.erase(myMap.find(nums[i - k]));
            }
            if (myMap.size() == k) {
                res = res < sum ? sum : res;
            }
        }
        return res;
    }
};

int main() {
    Solution_2 sol;
    vector<int> nums = {1,2,7,7,4,3,6};
    int ans = sol.maxSubarrrayWithK(nums, 3);
    cout<<ans<<endl;
    return 0;
}