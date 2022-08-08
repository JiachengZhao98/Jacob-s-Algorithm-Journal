#include "vector"
#include "climits"
#include "cmath"
#include "iostream"
using namespace std;

class solution {
public:
    long findEarliestMonth(vector<int>& stock) {
        long leftSum = 0, rightSum = 0, res = LONG_MAX;
        int index;
        for (auto a : stock) {
            rightSum += a;
        }
        for (int i = 0; i < stock.size() - 1; i++) {
            leftSum += stock[i];
            rightSum -= stock[i];
            long temp = abs((long)(leftSum / (i + 1) - rightSum / (stock.size() - i - 1)));
            if (res >= temp) {
                res = temp;
                index = i;
            }
        }
        return (index + 1);
    }
};

int main() {
    solution sol;
    vector<int> stock = {1,4,4,5,4,4,1};
    int res = sol.findEarliestMonth(stock);
    cout<<res<<endl;
    return 0;
}