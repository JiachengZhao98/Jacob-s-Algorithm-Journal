#include "string"
#include "unordered_map"
#include "iostream"
using namespace std;

class Solution {
public:
    int SinT(string S, string T) {
        unordered_map<char, int> strmap_t;
        unordered_map<char, int> strmap_s;
        for (int i = 0; i < T.size(); i++) {
            if (strmap_t.find(T[i]) == strmap_t.end()) {
                strmap_t.insert(pair<char, int>(T[i], 1));
            }
            else strmap_t.find(T[i])->second++;
        }
        for (int i = 0; i < S.size(); i++) {
            if (strmap_s.find(S[i]) == strmap_s.end()) {
                strmap_s.insert(pair<char, int>(T[i], 1));
            }
            else strmap_s.find(S[i])->second++;
        }
        int res = INT_MAX;
        for (int i = 0; i < T.size(); i++) {
            auto iter = strmap_t.find(T[i]);
            auto iter_2 = strmap_s.find(T[i]);
            int temp = iter_2->second / iter->second;
            res = temp < res ? temp : res;
        }
        return res;
    }
};

int main() {
    string S = "abababab";
    string T = "bba";
    Solution sol;
    int res = sol.SinT(S, T);
    cout<<res<<endl;
    return 0;
}
