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
#include "bitset"
#include "cmath"
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

    // LC 780. Reaching Points

    // isPossible

    // recursive approach

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
            int sumDigits;
            if (i == 10000) {
                sumDigits = 1;
            }
            else {
                int thousands = i / 1000;
                i %= 1000;
                int hundreds = i / 100;
                i %= 100;
                int tens = i / 10;
                int ones = i % 10;
                sumDigits = thousands + hundreds + tens + ones;
            }
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

    // LC 1209

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
        ListNode* dummyHead = new ListNode();
        dummyHead->next = head;
        unordered_map<int, int> myMap;
        while (head != nullptr) {
            if (myMap.find(head->val) == myMap.end()) {
                myMap.insert(pair<int, int> (head->val, 1));
            }
            else myMap[head->val]++;
            head = head->next;
        }
        head = dummyHead;
        while (head->next != nullptr) {
            if (myMap.find(head->next->val)->second >= 2) {
                head->next = head->next->next;
                continue;
            }
            head = head->next;
        }
        return dummyHead->next;
    }


    // LC 647. Palindromic Substrings
    int  countPalindromesAroundCenter(string s, int lo, int hi) {
        int ans = 0;
        while (lo >= 0 && hi < s.size()) {
            if (s[lo] != s[hi]) {
                break;
            }
            lo--;
            hi++;
            ans++;
        }
        return ans;
    }
    int countSubstrings(string s) {
        int ans = 0;
        for (int i = 0; i < s.size(); i++) {
            ans += countPalindromesAroundCenter(s, i, i);
            ans += countPalindromesAroundCenter(s, i, i + 1);
        }
        return ans;
    }



    // LC 696. Count Binary Substrings
    int countStrings(string s, int lo, int hi) {
        int ans = 0;
        while (lo >= 0 && hi < s.size()) {
            ans++;
            lo--;
            hi++;
            if (lo < 0 || hi > s.size() - 1 || s[lo] != s[lo + 1] || s[hi] != s[hi - 1]) {
                break;
            }
        }
        return ans;
    }
    int countBinarySubstrings(string s) {
        int ans = 0;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] != s[i + 1]) {
                ans += countStrings(s, i, i + 1);
            }
        }
        return ans;
    }


    // LC 1010. Pairs of Songs With Total Durations Divisible by 60
    // Whole Minute Dilemma

    // within 15 lines of code

    int numPairsDivisibleBy60(vector<int>& time) {
        int ans = 0;
        unordered_map<int, int> myMap;
        for (int i = 0; i < time.size(); i++) {
            int mod = time[i] % 60;
            if (mod == 0) {
                ans += myMap[mod];
                myMap[mod]++;
                continue;
            }
            ans += myMap[60 - mod];
            myMap[mod]++;
        }
        return ans;
    }


    // Lc 1356. Sort Integers by The Number of 1 Bits
    // Cardinality Sorting
    vector<int> sortByBits(vector<int>& arr) {
        vector<vector<int>> a;
		for(int i=0;i<arr.size();i++) {
			int x=arr[i],c=0;
			while(x) {
				if(x&1) c++;
				x>>=1;
			}
			a.push_back({c,arr[i]});
		}
		sort(a.begin(),a.end());
		for(int i=0;i<a.size();i++) {
			arr[i]=a[i][1];
		}
		return arr;
    }

    // the perfect team
    int thePerfectTeam(string skills) {
        map<char, int> myMap;
        for (auto skill : skills) {
            myMap[skill]++;
        }
        return myMap.begin()->second;
    }


    //  Cutting Metal Surplus
    int  CuttingMetalSurplus(int costPerCut, int salePrice, vector<int>& lengths) {
        int maxProfit = 0;
        int maxLength = INT_MIN;
        for (auto length : lengths) {
            maxLength = max(length, maxLength);
        }
        for (int i = 1; i <= maxLength; i++) {
            int sale_price_per_rod = salePrice * i;
            int profit = 0;
            for (auto length : lengths) {
                int uniform_rods = length / i;
                if (uniform_rods > 0) {
                    int extra_cut;
                    if (length % i > 0) {
                        extra_cut = 1;
                    }
                    else extra_cut = 0;
                    int total_cuts = uniform_rods - 1 + extra_cut;
                    int costs = total_cuts * costPerCut;
                    int revenues = uniform_rods * sale_price_per_rod;
                    if (revenues > costs)
                        profit += revenues - costs;
                }
            }
            maxProfit = max(profit, maxProfit);
        }
        return maxProfit;
    }


    // good array
    vector<int> goodArray(int N, vector<vector<int>>& queries) {
        deque<int> goodArray;
        vector<int> ans;
        while (N) {
            int power = log2(N);
            goodArray.push_front(pow(2, power));
            N -= pow(2, power);
        }
        for (auto query : queries) {
                int temp = 1;
                for (int i = query[0] - 1; i <= query[1] - 1; i++) {
                    temp *= goodArray[i];
                }
                ans.push_back(temp % query[2]);
        }
        return ans;
    }



    // Palindrome Subsequences
    long PalindromeSubsequences(string s) {
        long ans = 0;
        int len = s.size();
        vector<vector<int>> dp(len, vector<int>(len, 0));

      for(int i = len - 2;i >= 0; --i){
        for(int j = i + 2; j < len; ++j){
          dp[i][j] = dp[i][j-1] + (dp[i + 1][j] == dp[i + 1][j-1] ? 0 : dp[i + 1][j] - dp[i + 1][j - 1]);
          if(s[i] == s[j]){
            dp[i][j] += j - i - 1;
          }
        }
      }

      for(int i = 0; i < len; ++i){
        for(int j = i + 4; j < len; ++j){
          if(s[i] == s[j]){
            ans += dp[i + 1][j - 1];
          }
        }
      }
      ans = ans % (1000000000 + 7);

      return ans;
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

    // vector<string> wordSet = {"the", "bats", "tabs", "in", "cat", "act"};
    // vector<string> sentences = {"cat the bats", "in the act", "act tabs in"};
    // vector<int> ans = sol.howManySentences(wordSet, sentences);
    // for (auto a : ans) {
    //     cout<<a<<endl;
    // }


    // string skills = "pcmbzpcmbz";
    // int ans = sol.thePerfectTeam(skills);
    // cout<<ans<<endl;

    // vector<int> lengths = {26, 103, 59};
    // int ans = sol.CuttingMetalSurplus(1, 10, lengths);
    // cout<<ans<<endl;

    // vector<vector<int>> queries = {{1,2,84},{2,2,3}};
    // vector<int> ans = sol.goodArray(12, queries);
    // for (auto a : ans) {
    //     cout<<a<<endl;
    // }

    cout<<sol.PalindromeSubsequences("11111")<<endl;
    return 0;
}
