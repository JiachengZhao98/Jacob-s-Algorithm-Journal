#include "queue"
using namespace std;

 // Definition for a binary tree node.
  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  };
 
class Solution {
public:
    TreeNode* searchParentOfKeyNode(TreeNode* root, int key) {
        if (root->val < key && root->right != nullptr) {
            if (root->right->val == key) {
                return root;
            }
            else return searchParentOfKeyNode(root->right, key);
        }
        if (root->val > key && root->left != nullptr) {
            if (root->left->val == key) {
                return root;   
            }
            else return searchParentOfKeyNode(root->left, key);
        }
        return nullptr;
    }

    void transplant(TreeNode* parentNode, int key) {
        TreeNode* deleteNode;
        if (parentNode->left != NULL && parentNode->left->val == key) {
            deleteNode = parentNode->left;
            if (deleteNode->left == nullptr && deleteNode->right == nullptr) {
                parentNode->left = nullptr;
                delete deleteNode;
            }
            else if (deleteNode->left == nullptr) {
                parentNode->left = deleteNode->right;
                delete deleteNode;
            }
            else if (deleteNode->right == nullptr){
                parentNode->left = deleteNode->left;
                delete deleteNode;
            }
            else {
                if (deleteNode->right->left == nullptr) {
                    TreeNode* replace = deleteNode->right;
                    parentNode->left = replace;
                    replace->left = deleteNode->left;
                    delete deleteNode;
                }
                else {
                    TreeNode* replaceParent = deleteNode->right;
                    while (replaceParent->left->left != nullptr) {
                        replaceParent = replaceParent->left;
                    }
                    TreeNode* replace = replaceParent->left;
                    replaceParent->left = replace->right;
                    parentNode->left = replace;
                    replace->right = deleteNode->right;
                    replace->left = deleteNode->left;
                    delete deleteNode;
                }
            }
        }
        else {
            deleteNode = parentNode->right;
            if (deleteNode->left == nullptr && deleteNode->right == nullptr) {
                parentNode->right = nullptr;
                delete deleteNode;
            }
            else if (deleteNode->left == nullptr) {
                parentNode->right = deleteNode->right;
                delete deleteNode;
            }
            else if (deleteNode->right == nullptr) {
                parentNode->right = deleteNode->left;
                delete deleteNode;
            }
            else {
                if (deleteNode->right->left == nullptr) {
                    TreeNode* replace = deleteNode->right;
                    parentNode->right = replace;
                    replace->left = deleteNode->left;
                    delete deleteNode;
                }
                else {
                    TreeNode* replaceParent = deleteNode->right;
                    while (replaceParent->left->left != nullptr) {
                        replaceParent = replaceParent->left;
                    }
                    TreeNode* replace = replaceParent->left;
                    replaceParent->left = replace->right;
                    parentNode->right = replace;
                    replace->right = deleteNode->right;
                    replace->left = deleteNode->left;
                    delete deleteNode;
                }
            }
        }
    }

    TreeNode* deleteNode(TreeNode* root, int key) {
        if (root == nullptr)  return nullptr;
        if (root->val == key) {
            if (root->left == nullptr && root->right == nullptr) {
                return nullptr;
            }
            if (root->left == nullptr) {
                return root->right;
            }
            else if (root->left != nullptr) {
                TreeNode* newNode = root->right;
                if (newNode == nullptr) return root->left;
                if (newNode->left == nullptr) {
                    newNode->left = root->left;
                    delete root;
                    return newNode;
                }
                else if (newNode->left != nullptr) {
                    while (newNode->left->left != nullptr) {
                        newNode = newNode->left;
                    }
                    TreeNode* newRoot = newNode->left;
                    newNode->left = newRoot->right;
                    newRoot->left = root->left;
                    newRoot->right = root->right;
                    delete root;
                    return newRoot;
                }
            }
        }
        TreeNode* parentNode = searchParentOfKeyNode(root, key);
        if (parentNode == nullptr) return root;
        transplant(parentNode, key);
        return root;
    }
};