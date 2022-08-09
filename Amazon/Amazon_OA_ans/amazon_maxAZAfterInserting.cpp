#include "string"
#include "iostream"
#include "vector"
using namespace std;

class Solution {
public:
    int amazon_maxAZAfterInserting(string s) {
        int countA = 0, countZ = 0, res = 0;
        vector<int> record;
        for (int i = s.size() - 1; i >= 0; i--) {
            if (s[i] == 'Z') countZ++;
            if (s[i] == 'A') {
                countA++;
                res += countZ;
            }
        } 
        return (res + max(countA, countZ));
    }
};


int main() {
    Solution sol;
    string s = "Z";
    int ans = sol.amazon_maxAZAfterInserting(s);
    cout<<ans<<endl;
    return 0;
}