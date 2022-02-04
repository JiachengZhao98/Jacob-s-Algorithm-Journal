#include "iostream"
#include "stdio.h"
#include "cmath"
#include "string"
#include "string.h"
#include "array"
#include "set"
#include "map"
#include "vector"
#include "algorithm"
using namespace std;

bool sortAbs(int a, int b) {
    return abs(a) > abs(b);
}
class Solution {
   
public:
    int largestSumAfterKNegations(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end(), sortAbs);
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] < 0 && k > 0) {
                nums[i] *= -1;
                k--;
            }
        }
        if (k % 2 == 1) {
            nums[nums.size() - 1] *= -1;
        }
        int sum = 0;
        for (auto a : nums){
            sum += a;
        }
        return sum;
    }
};
int main()
{
    Solution sol;
    vector<int> myNums = {1,2,4,7,34,12,56,234,23,31};
    int sum = 0;
    sum = sol.largestSumAfterKNegations(myNums, 0);
    cout<<sum<<endl;
    
}

