#include "vector"
#include "queue"
#include "climits"
#include "stack"
#include "set"
#include "map"
#include "unordered_map"
#include "unordered_set"
#include "iostream"
#include "deque"
using namespace::std;


 // Definition for a binary tree node.
  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  };


// LC 133. Clone Graph
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};


class Solution {
public:

    // LC 103 Zigzag level order traversal
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if (root == NULL) {
            return res;
        }
        queue<TreeNode*> myQue;
        myQue.push(root);
        int count = 0;                      // put count as a global variable in this function
        while (!myQue.empty()) {
            vector<int> vec;
            int size = myQue.size();
            for (int i = 0; i < size; i++) {
                TreeNode* temp = myQue.front();
                vec.push_back(temp->val);
                myQue.pop();
                if (temp->left) {
                    myQue.push(temp->left);  // remember to push "temp->left"!!!
                }
                if (temp->right) {
                    myQue.push(temp->right); // remember to push "temp->right"!!!
                }
            }
            count++;
            if (count % 2 == 0) {
                reverse(vec.begin(), vec.end());
            }
            res.push_back(vec);
        }
        return res;
    }
    // time and space complexity: O(N), N is the number of nodes
    
    // LC 242. Valid Anagram
    bool isAnagram(string s, string t) {
        unordered_map<char, int> myMap;
        for (int i = 0; i < s.size(); i++) {
            if (myMap.find(s[i]) == myMap.end()) {
                myMap.insert(pair<char, int>(s[i], 1));
            }
            else myMap.find(s[i])->second++;
        }
        for (int i = 0; i < t.size(); i++) {
            if (myMap.find(t[i]) == myMap.end()) {
                return false;
            }
            else myMap.find(t[i])->second--;
            if (myMap.find(t[i])->second == 0) {
                myMap.erase(t[i]);
            }
        }
        return myMap.empty();
    }
    
    
    // for possible follow up: optimization
    
    bool isAnagram_2(string s, string t) {
        int record[26] = {0};
        
        for (int i =0; i < s.size(); i++) {
            record[s[i] - 'a']++;
        }
        for (int i = 0; i < t.size(); i++) {
            record[t[i] - 'a']--;
        }
        for (int i = 0; i < 26; i++) {
            if(record[i] != 0) {
                return false;
            }
        }
        return true;
    }
    
    //LC 64 Min Path Sum
    // DFS exceeds time limit
    int res = INT_MAX;
    void dfs(vector<vector<int>>& grid, int i, int j, int sum) {
        if (i < 0 || j < 0 || i >= grid.size() || j >= grid[0].size()) {
            return;
        }
        sum += grid[i][j];
        if (i == grid.size() - 1 && j == grid[0].size() - 1) {
            res = res > sum ? sum : sum;
            return;
        }
        dfs(grid, i + 1, j, sum);
        dfs(grid, i, j + 1, sum);
    }
    
    int minPathSum_notPass(vector<vector<int>>& grid) {
        dfs(grid, 0, 0, 0);
        return res;
    }

    // Dynamic Programming
    int minPathSum(vector<vector<int>>& grid) {
        vector<vector<int>> dp (grid.size(), vector<int>(grid[0].size(), 0));
        for (int i = grid.size() - 1; i >= 0; i--) {
            for (int j = grid[0].size() - 1; j >= 0; j--) {
                if (i != grid.size() - 1 && j == grid[0].size() - 1) {
                    dp[i][j] = grid[i][j] + dp[i + 1][j];
                }
                else if (i == grid.size() - 1 && j != grid[0].size() - 1) {
                    dp[i][j] = grid[i][j] + dp[i][j + 1];
                }
                else if (i != grid.size() - 1 && j != grid[0].size() - 1) {
                    dp[i][j] = grid[i][j] + min(dp[i][j + 1], dp[i + 1][j]);
                }
                else dp[i][j] = grid[i][j];
            }
        }
        return dp[0][0];
    }

    //LC 78. Subsets

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res = {};
        for (int num : nums) {
            vector<vector<int>> temp = res;
            if (temp.size() != 0) {
                for (vector<int> r : temp) {
                r.push_back(num);
                res.push_back(r);
                }
            }
            res.push_back({num});
        }
        res.push_back({});
        return res;
    }
        /*
            Time complexity: O(N * 2^N) to generate all subsets and then copy them into output list.
            Space complexity: O(N * 2^N) This is exactly the number of solutions for subsetscmultiplied by
            the number N of elements to keep for each subset.
        */

    // LC 133. Clone Graph
    // BFS approach

    Node* cloneGraph_BFS(Node* node) {
        if (node == NULL) {
            return node;
        }
        unordered_map<Node*, Node*> myMap;
        queue<Node*> myQ;
        myQ.push(node);
        myMap.insert(pair<Node*, Node*>(node, new Node(node->val)));
        while (!myQ.empty()) {
            Node* n = myQ.front();
            myQ.pop();
            for (auto neighbor : n->neighbors) {
                if (myMap.find(neighbor) == myMap.end()) {
                    myMap.insert(pair<Node*, Node*>(neighbor, new Node(neighbor->val)));
                    myQ.push(neighbor);
                }
                myMap.find(n)->second->neighbors.push_back(myMap.find(neighbor)->second);
            }
        }
        return myMap.find(node)->second;
    }

    // DFS approach

    // unordered_map<Node*, Node*> visited_clone_graph_dfs;

    Node* cloneGraph_DFS(Node* node) {
        if (node == NULL) {
            return node;
        }
        if (visited_clone_graph_dfs.find(node) != visited_clone_graph_dfs.end()) {
            return visited_clone_graph_dfs.find(node)->second;
        }
        visited_clone_graph_dfs.insert(pair<Node*, Node*>(node, new Node(node->val)));
        for (auto neighbor : node->neighbors) {
            visited_clone_graph_dfs.find(node)->second->neighbors.push_back(cloneGraph_DFS(neighbor));
        }
        return visited_clone_graph_dfs.find(node)->second;
    }


    // LC 20. Valid Parentheses
    bool isValid(string s) {
        stack<char> otherHalf;
        for (char s_part : s) {
            if (s_part == '(') otherHalf.push(')');
            else if (s_part == '[') otherHalf.push(']');
            else if (s_part == '{') otherHalf.push('}');
            else if (otherHalf.empty() || s_part != otherHalf.top()) return false;
            else otherHalf.pop();
        }
        return otherHalf.empty();
    }

    // LC 236. Lowest Common Ancestor of a Binary Tree

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (p == root || q == root) {
            return root;
        }
        unordered_map<TreeNode*, TreeNode*> child_parent;
        child_parent.insert(pair<TreeNode*, TreeNode*>(root, nullptr));
        queue<TreeNode*> myQ;
        myQ.push(root);
        while (child_parent.find(p) == child_parent.end() || child_parent.find(q) == child_parent.end()) {
                TreeNode* temp = myQ.front();
                myQ.pop();
                if (temp->left) {
                    myQ.push(temp->left);
                    child_parent.insert(pair<TreeNode*, TreeNode*>(temp->left, temp));
                }
                if (temp->right) {
                    myQ.push(temp->right);
                    child_parent.insert(pair<TreeNode*, TreeNode*>(temp->right, temp));
                }
        }
        set<TreeNode*> p_ancestors;
        while (p != nullptr) {
            p_ancestors.insert(p);
            p = child_parent.find(p)->second;
        }
        while (p_ancestors.find(q) == p_ancestors.end()) {
            q = child_parent.find(q)->second;
        }
        return q;
    }
    
    // LC 347. Top K Frequent Elements
    
    vector<int> topKFrequent(vector<int>& nums, int k) {
            if (nums.size() == 1) return {nums[0]};
            unordered_map<int,int> myMap;
            for (auto a : nums) {
                if (myMap.find(a) == myMap.end()) {
                    myMap.insert(pair<int, int>(a, 1));
                }
                else myMap.find(a)->second++;
            }
            multimap<int, int> res1;
            for (auto iter = myMap.begin(); iter != myMap.end(); iter++) {
                 res1.insert(pair<int, int>(iter->second, iter->first));
            }
            vector<int> res;
            int count = 0;
            for (auto iter = res1.rbegin(); iter != res1.rend(); iter++) {
                 if (count == k) break;
                 res.push_back(iter->second);
                 count++;
            }
            return res;
        }
    
    // Lc 198. House Robber
    // dynamic programming
    int rob(vector<int>& nums) {
        if (nums.size() == 1) {
            return nums[0];
        }
        int maxSum[nums.size() + 1];
        maxSum[nums.size()] = 0;
        maxSum[nums.size() - 1] = nums[nums.size() - 1];
        for (int i = nums.size() - 2; i >= 0; i--) {
            maxSum[i] = max(maxSum[i + 1], maxSum[i + 2] + nums[i]);
        }
        return maxSum[0];
    }
    // time complexity: O(N), space complexity: O(N)
    
    // For possible follow up:
    // optimization for LC 198: discard the dp table and just use two variables to store the largest sum
    int rob_optinization(vector<int>& nums) {
            if (nums.size() == 1) {
                return nums[0];
            }
            int maxSum_nums_size = 0;
            int maxSum_nums_size_minus_1 = nums[nums.size() - 1];
            for (int i = nums.size() - 2; i >= 0; i--) {
                int res = max(maxSum_nums_size_minus_1, maxSum_nums_size + nums[i]);
                maxSum_nums_size = maxSum_nums_size_minus_1;
                maxSum_nums_size_minus_1 = res;
            }
            return maxSum_nums_size_minus_1;
        }
    // time complexity: O(N), space complexity: O(1)
    
    //LC 151. Reverse Words in a String
    
    string reverseWords(string s) {
            reverse(s.begin(), s.end());
            int i = 0;
            string res;
            while (s[i] == ' ') {  // remove space at the beginning
                i++;
            }
            for (; i < s.size() - 1; i++) {
                if (s[i] == ' ' && s[i + 1] == ' ' ) {   // remove the extra space in the middle of the string
                    continue;
                }
                if (s[i] == ' ' && s[i + 1] != ' ') {   // add one ' ' in the middle of two adjacent words
                    res += ' ';
                    continue;
                }
                if (s[i] != ' ') {
                    string temp;
                    while (s[i] != ' ' && i <= s.size() - 1) {  // get one word, whose sequence is reversed
                        temp += s[i];
                        i++;
                    }
                    reverse(temp.begin(), temp.end());         // get the correct word
                    res += temp;
                    i--;
                }
            }
            if (i == s.size() - 1) {
                if (s[i] != ' ') {      // take care of the last char of string s
                    res += s[i];
                }
            }
            return res;
        }
        // time complexity: O(N), space cpmplexity: O(N)
    
    
    
    //LC 314. Binary Tree Vertical Order Traversal
    
    // BFS approach
    vector<vector<int>> verticalOrder_BFS(TreeNode* root) {
        vector<vector<int>> res;
        if (root == NULL) {
            return res;
        }
        map<int, vector<int>> columnTable;    
        queue<pair<TreeNode*, int>> myQ;
        myQ.push(pair<TreeNode*, int>(root, 0));
        while (!myQ.empty()) {
            auto temp = myQ.front().first;   // the node
            int column = myQ.front().second;  // its column index
            myQ.pop();
            if (columnTable.find(column) == columnTable.end()) {
                columnTable.insert(pair<int, vector<int>>(column, vector<int>()));
            }
            columnTable.find(column)->second.push_back(temp->val);         // group all the nodes with the same column index
            if (temp->left) {
                myQ.push(pair<TreeNode*, int>(temp->left, column - 1));    // column index minuses 1 if going to left
            }
            if (temp->right) {
                myQ.push(pair<TreeNode*, int>(temp->right, column + 1));    // column index pluses 1 if going to right
            }
        }
        for (auto iter = columnTable.begin(); iter != columnTable.end(); iter++) {
            res.push_back(iter->second);
        }
        return res;
    }
    //  space complexity: O(N), time complexity: O(NlogN), N is the number of nodes in the tree.


    // DFS approach
    map<int, multimap<int, int>> columnTable;
    void dfs_for_verticalOrder(TreeNode* root, int column, int row) {
        if (root == nullptr) {
            return;
        }
        if (columnTable.find(column) == columnTable.end()) {
            columnTable.insert(pair<int, multimap<int, int>>(column, multimap<int, int>()));
        }
        columnTable.find(column)->second.insert(pair<int, int>(row, root->val));
        dfs_for_verticalOrder(root->left, column - 1, row + 1);
        dfs_for_verticalOrder(root->right, column + 1, row + 1);
    }
    vector<vector<int>> verticalOrder_DFS(TreeNode* root) {
        vector<vector<int>> res;
        if (root == NULL) {
            return res;
        }
        dfs_for_verticalOrder(root, 0, 0);
        for (auto iter = columnTable.begin(); iter != columnTable.end(); iter++) {
            vector<int> temp;
            for (auto a = iter->second.begin(); a != iter->second.end(); a++) {
                temp.push_back(a->second);
            }
            res.push_back(temp);
        }
        return res;
    }
    // Time Complexity: O(W⋅HlogH)), where Wis the width of the binary tree (i.e. the number of columns in the result) 
    // and H is the height of the tree.
    // space complexity: O(N), where N is the number of all nodes

    // LC 210. Course Schedule II
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> courseDependencies(numCourses, 0);
        unordered_map<int, vector<int>> courseAdjList;
        for (auto prereq : prerequisites) {
            courseDependencies[prereq[0]]++;
            if (courseAdjList.find(prereq[1]) == courseAdjList.end()) {
                courseAdjList.insert(pair<int, vector<int>>(prereq[1], vector<int>()));
            }
             courseAdjList.find(prereq[1])->second.push_back(prereq[0]);
        }
        queue<int> q;
        vector<int> res;
        vector<bool> visited(numCourses, false);
        for (int i = 0; i < numCourses; i++) {
            if (courseDependencies[i] == 0) {
                q.push(i);
                visited[i] = true;
            }
        }
        while (!q.empty()) {
            int course = q.front();
            q.pop();
            res.push_back(course);
            for (int i = 0; i < courseAdjList[course].size(); i++) {
                int dependentCourse = courseAdjList.find(course)->second[i];
                if (!visited[dependentCourse]) {
                    courseDependencies[dependentCourse]--;
                    if (courseDependencies[dependentCourse] == 0) {
                        q.push(dependentCourse);
                        visited[dependentCourse] = 1;
                    }
                }
            }
        }
        for (auto visit : visited) {
            if (visit == false) return {};
        }
        return res;
    }
    



private: unordered_map<Node*, Node*> visited_clone_graph_dfs;

};

int main() {
    
}



