#include "vector"
#include "map"
#include "iostream"
using namespace std;

class Sloution {
public:
    int delivery(vector<int>& cargo) {
        map<int, int> myMap;
        int res = 0;
        for (int i = 0; i < cargo.size(); i++) {
            if (myMap.find(cargo[i]) == myMap.end()) {
                myMap.insert(pair<int, int>(cargo[i], 1));
            }
            else myMap.find(cargo[i])->second++;
        }
        for (auto iter = myMap.begin(); iter != myMap.end(); iter++) {
            if (iter->second == 1) {
                return -1;
            }
            else {
                if (iter->second % 3 == 0) {
                    res += iter->second / 3;
                }
                else {
                    res += (iter->second / 3 + 1);
                }
            }
        }
        return res;
    }
};

int main() {
    Sloution sol;
    vector<int> cargo = {7,7,7,7,7,7,7};
    int ans = sol.delivery(cargo);
    cout<<ans<<endl;
    return 0;
}