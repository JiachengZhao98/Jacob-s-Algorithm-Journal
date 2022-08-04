#include "iostream"
#include "cmath"
#include "string"
#include "array"
#include "set"
#include "map"
#include "vector"
using namespace std;

class Solution {
public:
    int maxGrey(vector<vector<int>>& grey) {
        vector<int> col(grey[0].size(), 0);
        vector<int> row(grey.size(), 0);
        int max = INT_MIN;
        for (int i = 0; i < grey.size(); i++) {
            for (int j = 0; j < grey[0].size(); j++) {
                row[i] += grey[i][j] == 1 ? 1 : -1;
            }
        }
        for (int j = 0; j < grey[0].size(); j++) {
            for (int i = 0; i < grey.size(); i++) {
                col[j] += grey[i][j] == 1 ? 1 : -1;
            }
        }
        for (int i = 0; i < grey.size(); i++) {
            for(int j = 0; j < grey[0].size(); j++) {
                int temp = grey[i][j] == 1 ? (row[i] + col[j] - 1) : (row[i] + col[j] + 1);
                max = temp > max ? temp : max;
            }
        }
        return max;
    }
};

int main() {
    Solution sol;
    vector<vector<int>> grey = {{1,0,0}, {1,0,0}, {1,1,1}};
    int res = sol.maxGrey(grey);
    cout<<res<<endl;
    return 0;
}
