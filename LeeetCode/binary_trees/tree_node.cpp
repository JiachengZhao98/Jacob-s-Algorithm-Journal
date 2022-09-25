#include "iostream"
using namespace std;

struct tree_node {
    int val;
    tree_node *left;
    tree_node *right;
    tree_node (int x): val(x), left(nullptr), right(nullptr) {};
};
