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
        for (; j < searchWord.size(); j++) {
            if (searchWord[j] == resultWord[i]) {
                i++;
            }
        }
        remain = resultWord.length() - i;
        return remain;
    }
};

int main() {
    Solution sol;
    string search = "mdfdafcdfdfbodfdffdodfdf";
    string result = "macbookpro";
    int res = -1;
    res = sol.searchWordResultword(search, result);
    cout<<res<<endl;
    return 0;
}
