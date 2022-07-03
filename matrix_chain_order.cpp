#include "iostream"
#include "stdio.h"
#include "cmath"
#include "string"
#include "string.h"
#include "array"
#include "set"
#include "map"
#include "vector"
using namespace std;

class Solution {
public:
    void matrixChainOrder (vector<int>& p){
        int n = 6;
        vector<vector<int>> s(7, vector<int>(7, 0));
        vector<vector<int>> m(7, vector<int>(7, 0));
        for (int i = 1; i <= n; i++) {
            m[i][i] = 0;
        }
        for (int l = 2; l <= n; l++) {
            for (int i = 1; i <= (n - l + 1); i++) {
                int j = i + l - 1;
                m[i][j] = INT_MAX;
                for (int k = i; k <= (j - 1); k++) {
                    int q = m[i][k] + m[k + 1][j] + p[i - 1]*p[k]*p[j];
                    if (q < m[i][j]) {
                        m[i][j] = q;
                        s[i][j] = k;
                    }
                }
            }
        }
    }
};
