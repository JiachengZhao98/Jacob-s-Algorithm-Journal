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
using namespace std;


class Solution {
public:
    int keypadClickCount (string text) {
        vector<char> letter(26, 0);
        vector<int> freq(26, 0);
        char input = 'a';
        for (int i = 0; i < 26; i++) {
            letter[i] = input;
            input++;
        }
        for (int i = 0; i < text.length(); i++) {
            for (int j = 0; j < 26; j++) {
                if (text[i] == letter[j]) {
                    freq[j]++;
                }
            }
        }
        sort(freq.begin(), freq.end());
        reverse(freq.begin(), freq.end());
        int count = 0;
        for (int i = 0; i < 26; i++) {
            count += freq[i] * ((i / 9) + 1);
        }
        return count;
    }
};


int main () {
    string text = "abacadefghibj";
    Solution sol;
    int count = sol.keypadClickCount(text);
    cout<<count<<endl;
    return 0;
}
