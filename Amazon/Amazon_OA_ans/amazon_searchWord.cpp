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
    int searchWordResultword(string searchWord, string resultWord) {
        int i = 0, j = 0;
        int remain = -1;
        int count = 0;
        for (; j < searchWord.size(); j++) {
            if (searchWord[j] == resultWord[i]) {
                i++;
                count++;
            }
        }
        remain = resultWord.size() - count;
        return remain;
    }
};

int main() {
    Solution sol;
    string search = "aghgmhghghgahzghghghghghgh";
    string result = "amazon";
    int res = -1;
    res = sol.searchWordResultword(search, result);
    cout<<res<<endl;
    return 0;
}
