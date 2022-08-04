#include "iostream"
#include "vector"
#include "map"
using namespace std;


class Solution {
public:
    int keypadClickCount_1 (string text) {
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
    
    int keypadClickCount_2 (string text) {
        map<char, int> letterCount;
        vector<int> count;
        int res = 0;
        for (int i = 0; i < text.size(); i++) {
            if (letterCount.find(text[i]) == letterCount.end()) {
                letterCount.insert(pair<char, int>(text[i], 1));
            }
            else {
                letterCount.find(text[i])->second++;
            }
        }
        int i = 0;
        for (auto iter = letterCount.begin(); iter != letterCount.end(); iter++) {
            count.push_back(iter->second);
        }
        sort(count.begin(), count.end());
        reverse(count.begin(), count.end());
        for (int i = 0; i < count.size(); i++) {
            res += count[i] * (i / 9 + 1);
        }
        return res;
    }
};



int main () {
    string text = "abacadefghibj";
    Solution sol;
    int count = sol.keypadClickCount_2(text);
    cout<<count<<endl;
    return 0;
}
