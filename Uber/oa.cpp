#include <iostream>
#include "vector"
#include "unordered_map"
#include "map"
#include "string"
#include "algorithm"
#include "set"

using namespace std;
// Function to find cycles in the permutation
int countCycles(const std::vector<int>& permutation) {
    int n = permutation.size();
    std::vector<bool> visited(n, false);
    int cycles = 0;

    for (int i = 0; i < n; ++i) {
        if (!visited[i]) {
            ++cycles;
            int current = i;
            while (!visited[current]) {
                visited[current] = true;
                current = permutation[current];
            }
        }
    }
    return cycles;
}

// Function to find the minimum number of operations
int minOperations(const std::vector<int>& nums, const std::vector<int>& target) {
    if (nums.size() != target.size()) return -1; // Safety check

    std::unordered_map<int, int> targetIndex;
    for (int i = 0; i < target.size(); ++i) {
        targetIndex[target[i]] = i;
    }

    std::vector<int> permutation(nums.size());
    for (int i = 0; i < nums.size(); ++i) {
        permutation[i] = targetIndex[nums[i]];
    }

    int cycles = countCycles(permutation);
    return nums.size() - cycles; // Minimum operations is n - number of cycles
}


// balloon explosion

void balloonExplosion(vector<vector<int>>& balloon) {
    bool flag = true;
    while (flag) {
        explode(balloon, flag);
        if (flag) {gravity(balloon);}
    }
}

void explode(vector<vector<int>>& balloon, bool& flag) {
    vector<vector<int>> to_explode;
    vector<vector<int>> dirs = {{1,0}, {-1,0}, {0,1}, {0,-1}};
    for (int i = 0; i < balloon.size(); i++) {
        for (int j = 0; j < balloon[0].size(); j++) {
            if (balloon[i][j] != 0) {
                vector<vector<int>> rec;
                for (auto dir : dirs) {
                    if (i + dir[0] >= 0 && i + dir[0] < balloon.size() && j + dir[1] >= 0 && j + dir[1] < balloon[0].size()) {
                        if (balloon[i + dir[0]][j + dir[1]] == balloon[i][j]) {
                            rec.push_back({i + dir[0], j + dir[1]});
                        }
                    }
                }
                if (rec.size() >= 2) {
                    to_explode.push_back({i,j});
                    for (auto a : rec) {
                        to_explode.push_back(a);
                    }
                }
            }
        }
    }
    if (!to_explode.empty()) {
        flag = 1;
        for (auto a : to_explode) {
            balloon[a[0]][a[1]] = 0;
        }
    }
    else flag = 0;

}

void gravity(vector<vector<int>>& balloon) {
    for (int j = 0; j < balloon[0].size(); j++) {
        int idx = balloon.size() - 1;
        for (int i = balloon.size() - 1; i >= 0; i--) {
            if (balloon[i][j] != 0) {
                balloon[idx][j] = balloon[i][j];
                if (idx != i) balloon[i][j] = 0;
                idx--;
            }
        }
    }
}


// trie

// find the number of pairs of strings in an array that are either equal or where one str‍‍‍‌‌‍‌‍‌‍‍‌‌‍‍‌‌‍‌‍ing is a prefix of the other.
class TrieNode {
public:
    std::unordered_map<char, TrieNode*> children;
    //bool exists;  // To store the number of times a prefix is inserted
    int freq;
    TrieNode() : freq(0) {}
};

class Trie {
private:
    TrieNode* root;

public:
    Trie() {
        root = new TrieNode();
    }

    void insert(const std::string& word) {
        TrieNode* node = root;
        for (char ch : word) {
            if (node->children.find(ch) == node->children.end()) {
                node->children[ch] = new TrieNode();
            }
            node = node->children[ch];
            node->freq += 1;
        }
    }

    int find(string prefix) {
        TrieNode* node = root;
        int res = 0;
        for (char ch : prefix) {
            if (node->children.find(ch) == node->children.end()) {
                break;
            }
            node = node->children[ch];
            res = node->freq;
        }
        return res;
    }

    // bool startsWith(string prefix) {
    //     TrieNode* node = root;
    //     for (auto ch : prefix) {
    //         if (node->children.find(ch) == node->children.end()) {
    //             return 0;
    //         }
    //         node = node->children[ch];
    //     }
    //     return 1;
    // }
};

int countPairs(const std::vector<std::string>& strings) {
    Trie trie;

    // vector<string> strings2;
    // for (auto a : strings) {
    //     reverse(a.begin(), a.end());
    //     strings2.push_back(a);
    // }
    for (const std::string& str : strings) {
        trie.insert(str);
    }

    int pairsCount = 0;
    for (string str : strings) {
        pairsCount += trie.find(str);
    }
    return pairsCount - strings.size();
}

class UnionFind {
private:
    vector<int> root;
    vector<int> rank;
public:
    UnionFind(int sz) : root(sz), rank(sz) {
        for (int i = 0; i < sz; i++) {
            root[i] = i;
            rank[i] = 1;
        }
    }

    int find(int x) {
        if (x == root[x]) {
            return x;
        }
	// Some ranks may become obsolete so they are not updated
        return root[x] = find(root[x]);
    }

    void unionSet(int x, int y) {
        int rootX = find(x);
        int rootY = find(y);
        if (rootX != rootY) {
            if (rank[rootX] > rank[rootY]) {
                root[rootY] = rootX;
            } else if (rank[rootX] < rank[rootY]) {
                root[rootX] = rootY;
            } else {
                root[rootY] = rootX;
                rank[rootX] += 1;
            }
        }
    }

    bool connected(int x, int y) {
        return find(x) == find(y);
    }
};

/*

Given an array with intergers nums, count the number of distinct pairs where 0 <= i < j < length of array
and nums[i] == nums[j] where you're allowed to swap two positions of nums[j] to make it equal to nums[i].

Example:
[1, 23, 156, 4738, 321, 72992, 231, 651, 32]
Result = 3
Explanation:
i = 1, nums[i] = 23, j = 8, nums[j] = 32, you can get 23 by swaping 3 and 2 postions in 32 (remeber only two swaps allowed)
i = 2, nums[i] = 156, j = 7, nums[j] = 651, you can get 156 by swaping 1 and 6 postions in 651(remeber only two swaps allowed)
i = 4, nums[i] = 321, j = 6, nums[j] = 231, you can get 321 by swaping 3 and 2 postions in 231(remeber only two swaps allowed)

*/

bool checkS(string str1, string str2) {
    if (str1.size() != str2.size()) return false;

    std::vector<int> diffIndices;
    for (int i = 0; i < str1.size(); ++i) {
        if (str1[i] != str2[i]) {
            diffIndices.push_back(i);
        }
    }

    // There must be exactly 2 differences for one swap to be possible
    if (diffIndices.size() == 2) {
        int i = diffIndices[0];
        int j = diffIndices[1];
        return (str1[i] == str2[j] && str1[j] == str2[i]);
    }

    return false;
}

int numOfDistinctPairs(vector<int>& nums) {
    unordered_map<string, vector<string>> myMap;
    for (auto a : nums) {
        string num = to_string(a);
        if (num.size() == 1) {
            num = '0' + num;
        }
        string dul_num = num;
        sort(dul_num.begin(), dul_num.end());
        myMap[dul_num].push_back(num);
    }
    int res = 0;
    for (auto pair : myMap) {
        if (pair.first.size() == 2) {
            res += pair.second.size() * (pair.second.size() - 1) / 2;
        }
        for (int i = 0; i < pair.second.size(); i++) {
            for (int j = i + 1; j < pair.second.size(); j++) {
                if (checkS(pair.second[i], pair.second[j])) {
                    res++;
                }
            }
        }
    }
    return res;
}


// 3043. Find the Length of the Longest Common Prefix

class TrieNode {
public:
    unordered_map<char, TrieNode*> children;
    //int length;
    TrieNode(){}
};

class Trie {
public:
    TrieNode* root;

    Trie() {
        root = new TrieNode();
    }

    void insert(string word) {
        TrieNode* node = root;
        for (auto ch : word) {
            if (node->children.find(ch) == node->children.end()) {
                node->children[ch] = new TrieNode();
            }
            node = node->children[ch];
        }
    }

    int startsWith(string prefix) {
        int res = 0;
        TrieNode* node = root;
        for (auto ch : prefix) {
            if (node->children.find(ch) == node->children.end()) {
                break;
            }
            res++;
            node = node->children[ch];
        }
        return res;
    }
};

class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        Trie trie;
        int res = 0;
        for (auto num : arr1) {
            trie.insert(to_string(num));
        }
        for (auto num : arr2) {
            res = max(res, trie.startsWith(to_string(num)));
        }
        return res;
    }
};


// create Y in a matrix

int minNumOfCells(int n, vector<vector<int>>& cells) {
    int mid = n / 2;
    unordered_map<int, int> y;
    unordered_map<int, int> others;
    set<pair<int, int>> yCell;
    for (int i = 0; i < n; i++) {
        if (i <= mid) {
            yCell.insert({i,i});
            yCell.insert({i, n - 1 - i});
        }
        else {
            yCell.insert({i, mid});
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (yCell.count({i, j}) != 0) {
                y[cells[i][j]]++;
            }
            else others[cells[i][j]]++;
        }
    }
    int res = INT_MAX;
    int sum = y[0] + y[1] + y[2] + others[0] + others[1] + others[2];
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (i != j) {
                res = min(res, sum - y[i] - others[j]);
            }
        }
    }
    return res;
}

// meeting schedule

vector<vector<int>> meet(vector<vector<int>>& slot1, vector<vector<int>>& slot2, int duration) {
    sort(slot1.begin(), slot1.end());
    sort(slot2.begin(), slot2.end());
    int m = slot1.size(), n = slot2.size();
    int i = 0, j = 0;
    vector<vector<int>> res;
    while (i < m and j < n) {
        int s = max(slot1[i][0], slot2[j][0]);
        int e = min(slot1[i][1], slot2[j][1]);
        if (e - s >= duration) {
            res.push_back({s,e});
        }
        if (slot1[i][1] < slot2[j][1]) {
            i++;
        }
        else j++;
    }
    return res;
}

vector<vector<int>> mergeInterval(vector<vector<int>>& interval) {
    sort(interval.begin(), interval.end());
    vector<vector<int>> res;
    for (int i = 0; i < interval.size() - 1; i++) {
        if (interval[i+1][0] <= interval[i][1]) {
            interval[i + 1][0] = min(interval[i + 1][0], interval[i][0]);
            interval[i + 1][1] = max(interval[i + 1][1], interval[i][1]);
        }
        else res.push_back({interval[i][0], interval[i][1]});
    }
    res.push_back(interval.back());
    return res;
}

vector<int> meetingSchedule(vector<vector<vector<int>>>& freeTime, int k) {
    // vector<vector<vector<int>>> free;
    // for (auto employee : freeTime) {
    //     free.push_back(mergeInterval(employee));
    // }
    vector<vector<int>> time;
    time = meet(freeTime[0], freeTime[1], k);
    for (int i = 2; i < freeTime.size(); i++) {
        vector<vector<int>> temp = meet(time, freeTime[i], k);
        time = temp;
    }
    return {time[0][0], time[0][0] + k};
}


int main() {
    std::vector<std::string> strings = {"abc", "ab", "abcd", "xyz", "xy", "a"};
    int result = countPairs(strings);
    std::cout << "Number of pairs: " << result << std::endl;

    return 0;
}

