#include "vector"
#include "queue"
#include "set"
#include "unordered_set"
#include "map"
#include "unordered_map"
#include "string"
using namespace std;

class Solution {
public:
    struct TreeNode {
    int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  };
    bool isCousins(TreeNode* root, int x, int y) {
        vector<int> rec(2, -1);
        if (root == nullptr){
            return false;
        }
        int depth = 0;
        queue<pair<TreeNode*, int>> que;
        que.push({root, depth});
        while (!que.empty()) {
            auto temp = que.front();
            que.pop();
            if (temp.first->val == x) {
                rec[0] = temp.second;
            }
            if (temp.first->val == y) {
                rec[1] = temp.second;
            }
            if (rec[0] != -1 && rec[1] != -1) break;
            if (temp.first->left) {
                int de = temp.second;
                de++;
                que.push(pair<temp.first->left, de>);
            }
            if (temp.first->right) {
                int fe = temp.second;
                fe++;
                que.push(pair<temp.first->right, fe>);
            }
        }
        return (rec[0] == rec[1]);
    }

    // LC 127. Word Ladder
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> s;
        for (auto a : wordList) {
            s.insert(a);
        }
        if (s.find(endWord) == s.end()) return 0;

        unordered_set<string> visited;
        visited.insert(beginWord);
        queue<string> q;
        q.push(beginWord);

        int step = 1;

        while (!q.empty()) {
            int size = q.size();
            for (int i = 0; i < size; i++) {
                string front = q.front();
                q.pop();
                if (front == endWord) {
                    return step;
                }
                for (int j = 0; j < beginWord.size(); j++) {
                    char temp = front[j];
                    for (char k = 'a'; k <= 'z'; k++) {
                        front[j] = k;
                        if (s.find(front) != s.end() && visited.find(front) == visited.end()) {
                            q.push(front);
                            visited.insert(front);
                        }
                    }
                    front[j] = temp;
                }
            }
            step++;
            if (q.empty()) step = 0;
        }
        return step;
    }

    // LC 103. Binary Tree Zigzag Level Order Traversal
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if (root == nullptr) return res;
        int counter = 0;
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            int size = q.size();
            vector<int> vec;
            for (int i = 0; i < size; i++) {
                TreeNode* node = q.front();
                q.pop();
                vec.push_back(node->val);
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }
            if (counter % 2) reverse(vec.begin(), vec.end());
            res.push_back(vec);
            counter++;
        }
        return res;
    }
};
