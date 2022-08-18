#include "string"
#include "map"
using namespace std;

class Solution {
public:
    int findHowManyWays(string A, string B, int N) {
        int count = 0;
        for (int i = 0; i + (B.size() - 1) * N < A.size(); i++) {  // 不能越界
            map<char, int> myMap;
            int j = i;
            while (j <= i + (B.size() - 1) * N) {
                if (myMap.find(A[j]) == myMap.end()) {
                    myMap.insert(pair<char, int>(A[j], 1));   // 第一次插入
                }
                else myMap.find(A[j])->second++;              // 不是第一次插入，频率加一
                j += N;
            }
            for (int k = 0; k < B.size(); k++) {
                if (myMap.find(B[k]) == myMap.end()) {
                    break;
                }
                else myMap.find(B[k])->second--;
                if (myMap.find(B[k])->second == 0) {
                    myMap.erase(myMap.find(B[k]));
                }
            }
            if (myMap.empty()) count++;
        }
        return count;
    }
};


