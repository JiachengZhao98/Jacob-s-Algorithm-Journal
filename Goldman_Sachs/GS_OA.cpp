#include "vector"
#include "queue"
#include "climits"
#include "stack"
#include "set"
#include "map"
#include "unordered_map"
#include "unordered_set"
#include "iostream"
#include "deque"
#include "sstream"
using namespace::std;


struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
  };

class Solution {
public:
    bool dfs(int sx, int sy, int tx, int ty) {
        if (sx >tx or sy > ty) {
            return 0;
        }
        if (sx == tx and sy == ty) {
            return 1;
        }
        bool temp1 = dfs(sx, sx + sy, tx, ty);
        bool temp2 = dfs(sx + sy, sy, tx, ty);
        return temp1 || temp2;
    }

    // LC 780. Reaching Points

    // isPossible

    // recursive approach
    bool reachingPoints_recursive(int sx, int sy, int tx, int ty) {
       return dfs(sx, sy, tx, ty);
    }

    // module approach
    bool reachingPoints(int sx, int sy, int tx, int ty) {
        if (sx > tx || sy > ty) {
            return 0;
        }
        else if (sx == tx && sy == ty) {
            return 1;
        }
        while (tx > sx && ty > sy) {
            if (tx > ty) {
                tx = tx % ty;
            }
            else {
                ty = ty % tx;
            }
        }
        if ((tx == sx && (ty - sy ) % sx == 0) || (ty == sy && (tx - sx) % sy == 0)) {
            return 1;
        }
        else return 0;
    }


    // Lottery Coupons
    int lotteryCoupons(int n) {
        unordered_map<int, int> myMap;
        for (int i = 1; i <= n; i++) {
            int sumDigits = i / 10 + i % 10;
            if (myMap.find(sumDigits) == myMap.end()) {
                myMap.insert(pair<int, int>(sumDigits, 1));
            }
            else myMap.find(sumDigits)->second++;
        }
        map<int, int> record;
        for (auto iter = myMap.begin(); iter != myMap.end(); iter++) {
            if (record.find(iter->second) == record.end()) {
                record.insert(pair<int, int>(iter->second, 1));
            }
            else record.find(iter->second)->second++;
        }
        return record.rbegin()->second;
    }

    // football games
    int findIndex(vector<int>& teamA, int a) {
        int left = 0, right = teamA.size() - 1;
        while (right - left > 1) {
            int middle = (right + left) / 2;
            if (a >= teamA[middle]) {
                left = middle;
                continue;
            }
            else {
                right = middle;
                continue;
            }
        }
        return right;
    }
    vector<int> footballGames(vector<int>& teamA, vector<int>& teamB) {
        sort(teamA.begin(), teamA.end());
        vector<int> ans;
        for (auto a : teamB) {
            if (a >= teamA[teamA.size() - 1]) {
                ans.push_back(teamA.size());
                continue;
            }
            int num = findIndex(teamA, a);
            ans.push_back(num);
        }
        return ans;
    }

    // How Many Sentences

    vector<int> howManySentences(vector<string>& wordSet, vector<string>& sentences) {
        unordered_map<string, vector<string>> myMap;
        vector<int> ans;
        for (auto word : wordSet) {
            string sortedWord = word;
            sort(sortedWord.begin(), sortedWord.end());
            myMap[sortedWord].push_back(word);
        }
        for (int i = 0; i < sentences.size(); i++) {
            stringstream ss(sentences[i]);
            string word;
            int sum = 1;
            while (ss >> word) {
                sort(word.begin(), word.end());
                if (myMap.find(word) != myMap.end()) {
                    sum *= myMap[word].size();
                }
            }
            ans.push_back(sum);
        }
        return ans;
    }


    // Remove All Adjacent Duplicates in String II / Word Compression

    // exceed time limit
    string removeDuplicates(string s, int k) {
        if (s.size() < k) {
            return s;
        }
        string s1 = s;
        while (s1 == s) {
            s1 = "";
            int count = 1;
            for (int i = 1; i < s.size(); i++) {
                if (s[i] != s[i - 1]) {
                    count = count % k;
                    string temp(count, s[i - 1]);
                    s1 += temp;
                    count = 1;
                }
                else {
                    count++;
                }
            }
            count %= k;
            string temp(count, s[s.size() - 1]);
            s1 += temp;
            if (s1 == s) {
                break;
            }
            s = s1;
        }
        return s;
    }

    string removeDuplicates_2(string s, int k) {
        int n = s.size(), i = 0, j = 0;
        vector<int> count(n, 0);
        for(; i < n; i++, j++) {
            s[j] = s[i];
            if(j > 0 && s[j] == s[j - 1]) {
                count[j] = count[j - 1] + 1;
            }
            else count[j] = 1;
            if(count[j] == k) j -= k;
        }
        return s.substr(0, j);
    }



    // LC 1328. Break a Palindrome
    string breakPalindrome(string palindrome) {
        string dul = palindrome;   // dulplicate string, INTACT
        if (palindrome.size() == 1) {
            return "";       // we can not break it if the length of this palindrome is 1
        }
        vector<int> record(26, 0);
        for (int i = 0; i <= palindrome.size() / 2; i++) {
            record[palindrome[i] - 'a']++;     // see if this string contains letter 'a'
        }
        if (record[0] == 0 || palindrome[0] != 'a') {   // if this string does NOT contain 'a' or the first letter is NOT 'a'
            palindrome[0] = 'a';    // just change the fitst one to 'a', that's enough to break this palindrome
            return palindrome;
        }
        else {
            for (int i = 0; i < palindrome.size(); i++) {  // if this string contains 'a' and the first one is 'a'
                if (palindrome[i] != 'a') {             // find the first letter that is NOT 'a' and change it to 'a'
                    palindrome[i] = 'a';
                    break;
                }
            }
            string rev = palindrome;
            reverse(rev.begin(), rev.end());
            if (rev == palindrome) {   // two possible special situations: 1. like "aa", we can not find a letter that is not 'a';
			//2. like "aba", when we change 'b' to 'a', we get "aaa", which is a parlindrome again! We do NOT break it !
			//We check it if it's still a parlindrome by reverse it
                dul[dul.size() - 1] = 'b';  // for these two situations, we simply change the last letter to 'b', that's enough
                return dul;
            }
            else return palindrome;
        }
    }


    // LC 1836. Remove Duplicates From an Unsorted Linked List
    ListNode* deleteDuplicatesUnsorted(ListNode* head) {

    }
private:

};

int main () {
    Solution sol;
    // vector<int> teamA = {1,2,3};
    // vector<int> teamB = {2,3};
    // vector<int> ans = sol.footballGames(teamA, teamB);
    // for (auto a : ans) {
    //     cout<<a<<endl;
    // }
    // cout<<sol.lotteryCoupons(12)<<endl;

    vector<string> wordSet = {"the", "bats", "tabs", "in", "cat", "act"};
    vector<string> sentences = {"cat the bats", "in the act", "act tabs in"};
    vector<int> ans = sol.howManySentences(wordSet, sentences);
    for (auto a : ans) {
        cout<<a<<endl;
    }
    return 0;
}
