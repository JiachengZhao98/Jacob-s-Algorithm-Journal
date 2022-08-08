#include "vector"
#include "iostream"
using namespace std;

class Solution {
public:
    vector<int> chooseWheels(vector<int>& wheels) {
        vector<int> res;
        for (int i = 0; i < wheels.size(); i++) {
            if (wheels[i] % 2) {
                res.push_back(0);
            }
            else {
                res.push_back(wheels[i] / 4 + 1);
            }
        }
        return res;
    }
};

int main() {
    Solution sol;
    vector<int> wheels = {4,5,6};
    vector<int> ans = sol.chooseWheels(wheels);
    for (auto a : ans) {
        cout<<a<<" ";
    }
    cout<<endl;
    return 0;
}