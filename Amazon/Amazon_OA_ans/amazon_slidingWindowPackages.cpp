#include "vector"
#include "iostream"
using namespace std;

class Solution{
public:
    int slidingWindowPackage(vector<int>& packages) {
        int res = packages[packages.size() - 1];
        for (int i = packages.size() - 1; i >= 1; i--) {
            if (packages[i] > packages[i - 1]) {
                packages[i - 1] = packages[i] + packages[i - 1];
            }
            res = res < packages[i - 1] ? packages[i - 1] : res;
        }
        return res;
    }
};

int main() {
    Solution sol;
    vector<int> packages = {2,9,10,3,7};
    int ans = sol.slidingWindowPackage(packages);
    cout<<ans<<endl;
    return 0;
}