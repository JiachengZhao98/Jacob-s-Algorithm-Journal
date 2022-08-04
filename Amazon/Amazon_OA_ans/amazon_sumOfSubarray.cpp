#include "set"
#include "iostream"
#include "algorithm"
#include "vector"
using namespace std;

// this solution exceeds time limit
class Solution {
public:
    long long subArrayRanges(vector<int>& nums) {
        long long res = 0;
        multiset<int> mySet;
        for (auto a : nums) {
            mySet.insert(a);
        }
        int i = 0;
        while (i < nums.size()) {
            for (int j = nums.size() - 1; j >= i; j--) {
                res += (*mySet.rbegin() - *mySet.begin());
                mySet.erase(mySet.find(nums[j]));
            }
            i++;
            if (i < nums.size()) {
                mySet.insert(nums.begin() + i, nums.end());
            }
        }
        return res;
    }
};
class Solution_2 {
public:
    long long subArrayRanges(vector<int>& nums) {
        
        long sum=0;
        
        for(int l=0; l<nums.size(); l++){
            int minnum = nums[l];
            int maxnum = nums[l];
            for(int r=l; r<nums.size(); r++){
                // key: min and max can be reuse!
                maxnum = max(maxnum, nums[r]);
                minnum = min(minnum, nums[r]);
                sum += maxnum - minnum;
            }
        }
        return sum;
    }   
};