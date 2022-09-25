#include <iostream>
#include "vector"

using namespace std;

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int res = INT_MAX;
        int sum = 0;
        int i = 0;
        for (int j = 0; j < nums.size(); j++) {
            sum += nums[j];
            
            while (sum >= target) {
                int subLength = j - i + 1;
                res = res > subLength ? subLength : res;
                sum -= nums[i++];
            }
        }
        return res == INT_MAX ? 0 : res;
    }
};


int main(int argc, const char * argv[]) {
}
