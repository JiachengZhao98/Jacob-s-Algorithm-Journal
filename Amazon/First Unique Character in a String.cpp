#include "iostream"
#include "string"
#include "unordered_map"
#include "vector"
using namespace std;

class Solution {
public:
    int firstUniqChar(string s) {
        vector<int> record(s.size());
        unordered_map<char, int> myMap;
        for (int i = 0; i < s.size(); i++) {
            auto iter = myMap.find(s[i]);
            if ( iter == myMap.end()) {
                myMap.insert(pair<char, int>(s[i], i));
                record[i]++;
            }
            else {
                record[iter->second]++;
            }
        }
        int result;
        for (int i = 0; i < record.size(); i++) {
            if (record[i] == 1) {
                return i;
            }
        }
        return -1;
    }
};