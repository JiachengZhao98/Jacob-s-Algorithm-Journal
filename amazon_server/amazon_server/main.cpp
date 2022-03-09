#include "iostream"
#include "map"
#include "vector"
#include "string"
#include "set"
#include "algorithm"
using namespace std;

class Solution {
public:
    vector<int> moveServer (vector<int>& locations, vector<int>& moveFrom, vector<int>& moveTo) {
        set<int> newLocations;
        set<int>::iterator iter;
        vector<int> newlocations;
        int j = 0;
        for (int i = 0; i < locations.size(); i++) {
            newLocations.insert(locations[i]);
        }
        for (int i = 0; i < moveFrom.size(); i++) {
            newLocations.erase(moveFrom[i]);
            newLocations.insert(moveTo[i]);
        }
        for(iter = newLocations.begin(); iter != newLocations.end(); ++iter) {
            newlocations.push_back(*iter);
        }
        return newlocations;
    }
};
int main() {
    vector<int> locations = {1,7,6,8};
    vector<int> moveFrom = {1,7,2};
    vector<int> moveTo = {2,9,5};
    Solution sol;
    vector<int> res = sol.moveServer(locations, moveFrom, moveTo);
    for (auto a : res) {
        cout<<a<<" ";
    }
    return 0;
}
