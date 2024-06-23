#include "iostream"
#include "vector"
#include "set"
#include "unordered_set"
#include "map"
#include "unordered_map"
#include "string"

using namespace std;

// problem url: https://leetcode.com/discuss/interview-question/5043451/Amazon-OA/

vector<int> findServerVulnerability(int k, int m, vector<int>& vulnerability) {
    vector<int> res;
    multiset<int> myset;
    for (int i = 0; i < m; i++) {
        myset.insert(vulnerability[i]);
    }
    res.push_back(*next(myset.begin(), k - 1));
    for (int i = m; i < vulnerability.size(); i++) {
        myset.insert(vulnerability[i]);
        myset.erase(myset.find(vulnerability[i - m]));
        res.push_back(*next(myset.begin(), k - 1));
    }
    return res;
}

// problem url: https://leetcode.com/discuss/interview-question/4754212/amazon

vector<int> tasksInQueus(vector<int>& waitTime) {
    int n = waitTime.size();
    int time = 0, idx = 0;
    vector<int> res;
    unordered_map<int, vector<int>> mp;
    for (int i = 0; i < n; i++) {
        mp[waitTime[i]].push_back(i);
    }
    while (n > 0) {
        if (waitTime[idx] == -1) {
            idx++;
            continue;
        }
        res.push_back(n);
        n--;
        idx++;
        time++;
        if (mp.find(time) != mp.end()) {
            vector<int> cur = mp[time];
            int count = 0;
            for (auto a : cur) {
                if (a > time) {
                    count++;
                    waitTime[a] = -1;
                }
            }
            n -= count;
        }
    }
    res.push_back(0);
    return res;
}


int main() {
    vector<int> temp = {2,2,3,1};
    vector<int> vec = tasksInQueus(temp);
    for (auto a : vec) {
        cout<<a<<" ";
    }
    cout<<endl;
    return 0;
}
