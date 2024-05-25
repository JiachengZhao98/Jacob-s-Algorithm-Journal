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


int main() {
    vector<int> temp = {4,2,3,1,1};
    vector<int> vec = findServerVulnerability(3, 4, temp);
    for (auto a : vec) {
        cout<<a<<" ";
    }
    cout<<endl;
    return 0;
}
