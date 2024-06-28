#include <iostream>
#include "vector"
#include "unordered_map"
#include "map"
#include "string"
#include "algorithm"

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
        
    }
}




int main() {
    std::vector<std::string> strings = {"abc", "ab", "abcd", "xyz", "xy", "a"};
    int result = countPairs(strings);
    std::cout << "Number of pairs: " << result << std::endl;

    return 0;
}

