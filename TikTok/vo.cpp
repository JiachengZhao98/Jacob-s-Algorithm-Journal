#include "vector"
#include "queue"
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
};
