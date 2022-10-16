#include "iostream"
#include "string"
#include "vector"
#include "unordered_set"

using namespace std;

vector<int> getNum(vector<int>& arr) {
    unordered_set<int> mySet;
    vector<int> res;
    for (auto a : arr) {
        mySet.insert(a);
    }
    res.push_back(mySet.size());
    for (int i = 0; i <= (arr.size() + 1); i++) {
        if (mySet.find(i) == mySet.end()) {
            res.push_back(i);
        }
    }
    return res;
}
vector<int> getMaxArray(vector<int>& arr) {
    vector<int> ans;
    vector<int> vec = getNum(arr);
    ans.push_back(vec[1]);
    unordered_set<int> s;
    for (int i = 0; i < vec[1]; i++) {
        s.insert(i);
    }
    int index = 0;
    while (!s.empty()) {
        if (s.find(arr[index]) != s.end()) {
            s.erase(arr[index]);
        }
        index++;
    }
    if (index >= arr.size()) return ans;
    vector<int> newArr(arr.begin() + index, arr.end());
    vector<int> res2 = getMaxArray(newArr);
    for (int i = 0; i < res2.size(); i++) {
        ans.push_back(res2[i]);
    }
    return ans;
}

int main()
{
    vector<int> arr = {6,1,2,3,4,6};
    vector<int> ans = getMaxArray(arr);
    for (auto a : ans) {
        cout<<a<<endl;
    }
    return 0;
}
