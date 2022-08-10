#include "vector"
#include "iostream"
using namespace std;

class Solution {
public:
    int slidingWindow(vector<int>& memory, int k) {
        int maxSum = 0, allSum = 0;
        for (int i = 0; i < k; i++) {
            maxSum += memory[i];
            allSum += memory[i];
        }
        int max = maxSum;
        for (int i = k; i < memory.size(); i++) {
            allSum += memory[i];
            maxSum = maxSum - memory[i - k] + memory[i];
            max = max < maxSum ? maxSum : max;
        }
        return (allSum - max);
    }
};

int main() {
    Solution sol;
    vector<int> memory = {1,4,4,6,9,4};
    int ans = sol.slidingWindow(memory, 2);
    cout<<ans<<endl;
    return 0;
}