#include "vector"
#include "iostream"
#include "climits"
using namespace std;

class Solution {
public:
    long int Min(long x, long y) {
        if (x < y) return x;
        else return y;
    }
    int minNetStock(vector<int>& nums) {
        if (nums.size() == 1) {
            return 0;
        }
        long tempSum = 0;
        long count;
        long sum = 0;
        long Minimum = INT_MAX;
        for (auto a : nums) {
            tempSum += a;
        }
        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];
            tempSum -= nums[i];
            int temp;
            if (i < nums.size() - 1) {
                temp = sum / (i + 1) - tempSum / (nums.size() - i - 1);
            }
            else temp = sum / (i + 1);
            temp = abs(temp);
            long tempMin = Min(Minimum, temp);
            if (tempMin < Minimum) {
                Minimum = tempMin;
                count = i + 1;
            }
        }
        return count - 1;
    }
};

int main() {
    Solution sol;
    vector<int> stock = {1,3,2,3};
    int res = sol.minNetStock(stock);
    cout<<res<<endl;
    return 0;
}