#include "iostream"
#include "vector"
#include "set"
using namespace std;

class Solution {
public:
    vector<int> moveFromMoveTo(vector<int> locations, vector<int> moveFrom, vector<int> moveTo) {
        set<int> temp;
        vector<int> res;
        for (auto loc : locations) {
            temp.insert(loc);
        }
        for (int i = 0; i < moveFrom.size(); i++) {
            auto iter = temp.find(moveFrom[i]);
            temp.erase(iter);
            temp.insert(moveTo[i]);
        }
        for (auto iter = temp.begin(); iter != temp.end(); iter++) {
            res.push_back(*iter);
        }
        return res;
    }
};

int main() {
    vector<int> res;
    Solution sol;
    std::vector<int> locations = {1,7,6,8};
    vector<int> moveFrom = {1,7,2};
    vector<int> moveTo = {2,9,5};
    res = sol.moveFromMoveTo(locations, moveFrom, moveTo);
    for (auto a : res) {
        cout<<a<<" ";
    }
    cout<<endl;
    return 0;
}