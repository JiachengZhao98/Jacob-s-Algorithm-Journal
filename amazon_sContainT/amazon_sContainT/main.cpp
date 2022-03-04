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
    int SinT(string S, string T) {
        map<char, int> strmap;
        map<char, int>::iterator iter;
        for (int i = 0; i < T.size(); i++) {
            strmap.insert(pair<char, int>(T[i], 0));
        }
        for (int i = 0; i < S.size(); i++) {
            if (strmap.find(S[i]) != strmap.end()) {
                strmap[S[i]]++;
            }
        }
        vector<int> res;
        for(iter = strmap.begin(); iter != strmap.end(); ++iter) {
            res.push_back(iter->second);
        }
        sort(res.begin(), res.end());
        return res[0];
    }
};

int main() {
    string S = "ab";
    string T = "bca";
    Solution sol;
    int res = sol.SinT(S, T);
    cout<<res<<endl;
    return 0;
}
