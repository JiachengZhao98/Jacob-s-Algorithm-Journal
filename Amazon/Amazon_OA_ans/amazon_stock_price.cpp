#include "iostream"
#include "stdio.h"
#include "cmath"
#include "string"
#include "string.h"
#include "array"
#include "set"
#include "map"
#include "vector"
#include "algorithm"
#include "unordered_set"
using namespace std;

class Solution {
public:
    int stockPrice(vector<int>& month, int k){
        int sum = 0;
        int res = 0;
        set<int>::iterator iter;
        set<int> rem;
        if (month.size() < k) {
            return -1;
        }
        for (int i = 0; i <= month.size() - k; i++) {
            for (int j = i; j < i + k; j++) {
                rem.insert(month[j]);
            }
            if (rem.size() == k) {
                for ( iter = rem.begin(); iter != rem.end(); ++iter) {
                    sum += *iter;
                }
                if (sum > res) {
                    res = sum;
                }
            }
            rem.clear();
            sum = 0;
        }
        if (res == 0) {
            return -1;
        } else return res;
    }
};


int main() {
    Solution sol;
    int k = 4;
    vector<int> month = {1,2,7,7,4,3,6};
    int sum = sol.stockPrice(month, k);
    cout<<sum<<endl;
    
    return 0;
}
