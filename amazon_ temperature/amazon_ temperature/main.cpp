#include "iostream"
#include "cmath"
#include "string"
#include "array"
#include "set"
#include "map"
#include "vector"
#include "algorithm"
using namespace std;

class Solution {
public:
    int temperature(vector<int> weather) {
        int i = 0;
        int sumftb = 0, sumbtf = 0;
        int res = INT_MIN;
        for (; i < weather.size(); i++) {
            sumftb += weather[i];
            sumbtf += weather[weather.size() - 1 - i];
            res = Max(sumbtf, sumftb, res);
        }
        return res;
    }
    
private:
    int Max(int a, int b, int c){
        int temp = max(a, b);
        temp = max(temp, c);
        return temp;
    }
};

int main() {
    vector<int> temp = {-1,2,3};
    Solution sol;
    int res = sol.temperature(temp);
    cout<<res<<endl;
    return 0;
    
}
