#include "iostream"
#include "vector"
#include "stack"
using namespace std;

// definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

int main(int argc, char const *argv[])
{
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    stack<TreeNode*> sta;
    sta.push(root);
    sta.push(NULL);
    TreeNode* node = sta.top();
    sta.pop();
    if (node == NULL)
    {
        cout << "NULL" << endl;
    }
    else
    {
        cout << node->val << endl;
    }
    return 0;
}
