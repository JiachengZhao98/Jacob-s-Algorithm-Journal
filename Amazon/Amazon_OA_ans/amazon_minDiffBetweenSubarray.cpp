#include "vector"
#include "iostream"
#include "climits"
using namespace std;

class Solution {
public:
    int minNetStock(vector<int>& stock) {
        int tempSum = 0;
        int count;
        int sum = 0;
        int Min = INT_MAX;
        for (auto a : stock) {
            tempSum += a;
        }
        for (int i = 0; i < stock.size() - 1; i++) {
            sum += stock[i];
            tempSum -= stock[i];
            int temp = sum / (i + 1) - tempSum / (stock.size() - i - 1);
            temp = abs(temp);
            int tempMin = min(Min, temp);
            if (tempMin < Min) {
                Min = tempMin;
                count = i + 1;
            }
        }
        return count;
    }
};

int main() {
    Solution sol;
    vector<int> stock = {1,3,2,3};
    int res = sol.minNetStock(stock);
    cout<<res<<endl;
    return 0;
}