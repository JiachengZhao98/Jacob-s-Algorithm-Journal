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


 // Definition for singly-linked list.
  struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
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

class Node_2 {
public:
    int val;
    Node_2* next;
    Node_2* random;

    Node_2(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

struct Node_trie{
        Node_trie* links[26];
        bool flag;

        bool containsKey(char ch) {
            return links[ch - 'a'] != nullptr;
        }

        void put(char ch, Node_trie* node_trie) {
            links[ch - 'a'] = node_trie;
        }

        Node_trie* get(char ch) {
            return links[ch - 'a'];
        }

        void setEnd() {
            flag = 1;
        }

        bool isEnd() {
            return flag;
        }
    };

class Trie{
private:
    Node_trie* root;

public:
    Trie() {
        root = new Node_trie();
    }

    void insert(string word) {
        Node_trie* node = root;
        for (int i = 0; i < word.size(); i++) {
            if (!node->containsKey(word[i])) {
                node->put(word[i], new Node_trie());
            }
            node = node->get(word[i]);
        }
        node->setEnd();
    }

    bool search(string word) {
        Node_trie* node = root;
        for (int i = 0; i < word.size(); i++) {
            if (!node->containsKey(word[i])) {
                return false;
            }
            node = node->get(word[i]);
        }
        return node->isEnd();
    }

     bool startsWith(string prefix) {

        Node_trie* node = root;
        for(int i=0;i<prefix.length();i++)
        {
            if(!node->containsKey(prefix[i]))
            {
                return false;
            }
            node=node->get(prefix[i]);
        }
        return true;

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
    void dfs_for_verticalOrder(TreeNode* root, int column, int row, map<int, multimap<int, int>>& columnTable) {
        if (root == nullptr) {
            return;
        }
        if (columnTable.find(column) == columnTable.end()) {
            columnTable.insert(pair<int, multimap<int, int>>(column, multimap<int, int>()));
        }
        columnTable.find(column)->second.insert(pair<int, int>(row, root->val));
        dfs_for_verticalOrder(root->left, column - 1, row + 1, columnTable);
        dfs_for_verticalOrder(root->right, column + 1, row + 1, columnTable);
    }
    vector<vector<int>> verticalOrder(TreeNode* root) {
        vector<vector<int>> res;
        if (root == NULL) {
            return res;
        }
        map<int, multimap<int, int>> columnTable;
        dfs_for_verticalOrder(root, 0, 0, columnTable);
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

    // time and space complexity: O(N)


    // 92. Reverse Linked List II

    // first approach
    ListNode* reverseBetween_1(ListNode* head, int left, int right) {
        ListNode* begin = head;
        ListNode* end = head;
        ListNode* after;
        ListNode* pre;
        int count = 1;
        if (left == 1) {
            pre = nullptr;
        }
        else if (left > 1) {
            while (count != left - 1) {
                begin = begin->next;
                count++;
            }
            pre = begin;
            begin = begin->next;
        }
        count = 1;
        if (right == 1) {
            return head;
        }
        else if (right > 1) {
            while (count != right) {
                end = end->next;
                count++;
            }
            after = end->next;
        }
        ListNode* cur = begin->next;
        ListNode* temp;
        ListNode* prev = begin;
        while (prev != end) {
            temp = cur->next;
            cur->next = prev;
            prev = cur;
            cur = temp;
        }
        if(pre) pre->next = end;
        begin->next = cur;
        if (left == 1) {
            return end;
        }
        else return head;
    }

        // use stack
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode* newHead = head;
        ListNode* resHead = head;
        int pos = 1;
        stack<int> mySta;
        while (head) {
            if (pos <= right && pos >= left) {
                mySta.push(head->val);
            }
            head = head->next;
            pos++;
        }
        pos = 1;
        while (newHead) {
            if (pos <= right && pos >= left) {
                newHead->val = mySta.top();
                mySta.pop();
            }
            newHead = newHead->next;
            pos++;
        }
        return resHead;
    }
    // time and space complexity are both O(N).
    // We do not need to change the 'next' pointer in order to reverse the linked list. We can just change the
    //corresponding nodes' values to achieve this goal.


    //LC 200. Number of Islands
    // DFS approach
    void dfs_for_numIslands(vector<vector<char>>& grid, int i, int j, vector<vector<bool>>& visited) {
        if (i >= grid.size() || j >= grid[0].size() || i < 0 || j < 0) {
            return;
        }
        if (visited[i][j]) return;
        if (grid[i][j] == '0') return;
        visited[i][j] = true;
        dfs_for_numIslands(grid, i + 1, j, visited);
        dfs_for_numIslands(grid, i, j+ 1, visited);
        dfs_for_numIslands(grid, i - 1, j, visited);
        dfs_for_numIslands(grid, i, j - 1, visited);
    }
    int numIslands_DFS(vector<vector<char>>& grid) {
        int count = 0;
        vector<vector<bool>> visited(grid.size(), vector<bool>(grid[0].size(), false));
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] == '1' && (!visited[i][j])) {
                    dfs_for_numIslands(grid, i, j, visited);
                    count++;
                }
            }
        }
        return count;
    }
    // time and space complexity are both O(M * N);

    // BFS approach
    int numIslands(vector<vector<char>>& grid) {
        int count = 0;
        vector<vector<bool>> visited(grid.size(), vector<bool>(grid[0].size(), false));
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] == '1' && (!visited[i][j])) {
                    queue<pair<int, int>> q;
                    q.push(pair<int, int>(i, j));
                    while (!q.empty()) {
                        auto temp = q.front();
                        q.pop();
                        visited[temp.first][temp.second] = true;
                        if (temp.first + 1 < grid.size() && grid[temp.first + 1][temp.second] == '1' && !visited[temp.first + 1][temp.second]) {
                            q.push(pair<int, int>(temp.first + 1, temp.second));
                        }
                        if (temp.second + 1 < grid[0].size() && grid[temp.first][temp.second + 1] == '1' && !visited[temp.first][temp.second + 1]) {
                            q.push(pair<int,int>(temp.first, temp.second + 1));
                        }
                        if (temp.first - 1 >= 0 && grid[temp.first - 1][temp.second] == '1' && !visited[temp.first - 1][temp.second]) {
                            q.push(pair<int, int>(temp.first - 1, temp.second));
                        }
                       if (temp.second - 1 >= 0 && grid[temp.first][temp.second - 1] == '1' && !visited[temp.first][temp.second - 1]) {
                            q.push(pair<int, int>(temp.first, temp.second - 1));
                        }
                    }
                    count++;
                }
            }
        }
        return count;
    }

    //LC 109 Convert Sorted List to Binary Search Tree

    ListNode* findMidNode(ListNode* head) {
        ListNode* Next;
        ListNode* slow = head;
        ListNode* fast = head;
        while (fast && fast->next) {
            Next = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        if (Next) {
            Next->next = nullptr;         // Handling the case when slowPtr was equal to head.
        }
        return slow;
    }
    TreeNode* sortedListToBST(ListNode* head) {
        if (head == nullptr) {
            return nullptr;
        }
        ListNode* mid = findMidNode(head);
        TreeNode* root = new TreeNode(mid->val);
        if (head == mid) {
            return root;
        }
        root->left = sortedListToBST(head);
        root->right = sortedListToBST(mid->next);
        return root;
    }


    //LC 22. Generate Parentheses
    void allPossibleParentheses(string curr, int open, int close, int n, vector<string>& ans) {
        if (open == n && close == n) {
            ans.push_back(curr);
            return;
        }
        if (open < n) {
            allPossibleParentheses(curr + '(', open + 1, close, n, ans);
        }
        if (close < open) {
            allPossibleParentheses(curr + ')', open, close + 1, n, ans);
        }
    }
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        allPossibleParentheses("", 0, 0, n, ans);
        return ans;
    }

    // LC 105. Construct Binary Tree from Preorder and Inorder Traversal
    TreeNode* traversal(vector<int>& preorder, vector<int>& inorder) {
        if (preorder.size() == 0) {
            return nullptr;
        }
        int rootVal = preorder[0];
        TreeNode* root = new TreeNode(rootVal);
        if (preorder.size() == 1) {
            return root;
        }
        int delimiter;
        for (int i = 0; i < inorder.size(); i++) {
            if (inorder[i] == rootVal) {
                delimiter = i;
            }
        }
        vector<int> leftInorder(inorder.begin(), inorder.begin() + delimiter);
        vector<int> rightInorder(inorder.begin() + delimiter + 1, inorder.end());

        for (int i = 0; i < preorder.size() - 1; i++) {
            preorder[i] = preorder[i + 1];
        }
        preorder.pop_back();
        vector<int> leftPreorder(preorder.begin(), preorder.begin() + leftInorder.size());
        vector<int> rightPreorder(preorder.begin() + leftInorder.size(), preorder.end());
        root->left = traversal(leftPreorder, leftInorder);
        root->right = traversal(rightPreorder, rightInorder);
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        TreeNode* root = traversal(preorder, inorder);
        return root;
    }


    // LC 79. Word Search
    bool dfsForWorldSearch(vector<vector<char>>& board, int i, int j, string word, vector<vector<bool>>& visited, int count) {
    if (count == word.size()) return 1;
    if (i < 0 || j < 0 || i >= board.size() || j >= board[0].size() || visited[i][j]) {
        return 0;
    }
    if (board[i][j] != word[count]) {
        return 0;
    }
    visited[i][j] = 1;
    bool b1 = dfsForWorldSearch(board, i + 1, j, word, visited, count + 1);
    bool b2 = dfsForWorldSearch(board, i - 1, j, word, visited, count + 1);
    bool b3 = dfsForWorldSearch(board, i, j + 1, word, visited, count + 1);
    bool b4 = dfsForWorldSearch(board, i, j - 1, word, visited, count + 1);
    if (b1 || b2 || b3 || b4) return true;
    visited[i][j] = 0;
    return false;
    }

    bool exist(vector<vector<char>>& board, string word) {
        vector<vector<bool>> visited(board.size(), vector<bool>(board[0].size(), 0));
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[0].size(); j++) {
                if (board[i][j] == word[0]) {
                    if (dfsForWorldSearch(board, i, j, word, visited, 0)) {
                        return true;
                    }
                }
            }
        }
        return false;
    }

    // LC 62. Unique Paths

    // DFS approach

    void dfs_uniquePath(vector<vector<int>> grid, int i, int j) {
        if (i >= grid.size() || j >= grid[0].size()) {
            return;
        }
        if (grid[i][j] == 2) {
            path_count++;
            return;
        }
        dfs_uniquePath(grid, i + 1, j);
        dfs_uniquePath(grid, i, j + 1);
    }
    int uniquePaths(int m, int n) {
        vector<vector<int>> grid(m, vector<int>(n, 1));
        grid[m - 1][n - 1] = 2;
        dfs_uniquePath(grid, 0, 0);
        return path_count;
    }


    // DP approach
    int uniquePaths_DP(int m, int n) {
        vector<vector<int>> dp(m, vector<int>(n, 0));
        for (int i = 0; i < m; i++) {
            dp[i][n - 1]  = 1;
        }
        for (int i = 0; i < n; i++) {
            dp[m - 1][i] = 1;
        }
        for (int i = m - 2; i >= 0; i--) {
            for (int j = n - 2; j >= 0; j--) {
                dp[i][j] = dp[i + 1][j] + dp[i][j + 1];
            }
        }
        return dp[0][0];
    }

    // LC 322. Coin Change
    int coinChange(vector<int>& coins, int amount) {
        if (amount == 0) return 0;
        vector<int> dp(amount + 1, amount + 1);
        dp[0] = 0;
        for (int i = 1; i <= amount; i++) {
            for (int j = 0; j < coins.size(); j++) {
                if (coins[j] <= i) {
                    dp[i] = min(dp[i], dp[i - coins[j]] + 1);
                }
            }
        }
        return dp[amount] > amount ? -1 : dp[amount];
    }

    // LC 518. Coin Change 2
    int change(int amount, vector<int>& coins) {
        vector<int> rec(amount + 1, 0);
        rec[0] = 1;
        for (auto coin : coins) {
            for (int i = coin; i <= amount; i++) {
                rec[i] += rec[i - coin];
            }
        }
        return rec[amount];
    }

    //LC 1696. Jump Game VI
    int maxResult(vector<int>& nums, int k) {
        if (k == 0) return 0;

    }


    // LC 55. Jump Game
    bool canJump(vector<int>& nums) {
        if (nums.size() == 1) {
            return true;
        }
        int cover = nums[0];
        for (int i = 1; i <= cover; i++) {
            if (cover >= (nums.size() - 1)) {
                return true;
            }
            cover =  max(cover, i +nums[i]);
        }
        return false;
    }


    // LC 23. Merge k Sorted Lists
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.size() == 0 or (lists.size() == 1 and lists[0] == nullptr)) {
            return nullptr;
        }
        priority_queue<int, vector<int>, greater<int>> pq;
        for (auto list : lists) {
            while (list != nullptr) {
                pq.push(list->val);
                list = list->next;
            }
        }
        ListNode* head = new ListNode();
        ListNode* head2 = head;
        while (!pq.empty()) {
            ListNode* temp = new ListNode(pq.top());
            pq.pop();
            head->next = temp;
            head = head->next;
        }
        return head2->next;
    }

    ListNode* mergeKLists_2(vector<ListNode*>& lists) {
        if (lists.size() == 0 or (lists.size() == 1 and lists[0] == nullptr)) {
            return nullptr;
        }
        multiset<int> ms;
        for (auto list : lists) {
            while (list != nullptr) {
                ms.insert(list->val);
                list = list->next;
            }
        }
        ListNode* head = new ListNode();
        ListNode* head2 = head;
        for (auto iter = ms.begin(); iter != ms.end(); iter++) {
            head->next = new ListNode(*iter);
            head = head->next;
        }
        return head2->next;

    }

    // LC 1151. Minimum Swaps to Group All 1's Together
    int minSwaps(vector<int>& data) {
        int ones = 0;
        for (auto a : data) {
            ones += a;
        }
        int left = 0, right = 0, sum = 0, res = 0;
        while (right < data.size()) {
            sum += data[right];
            right++;
            if (right - left > ones) {
                sum -= data[left];
                left++;
            }
            res = max(res, sum);
        }
        return ones - res;
    }


    // LC 503. Next Greater Element II
    vector<int> nextGreaterElements(vector<int>& nums) {
        vector<int> ans(nums.size(), 0);
        stack<int> sta;
        if (nums.size() == 1) {
            return {-1};
        }
        for (int i = nums.size() - 2; i >= 0; i--) {
            sta.push(nums[i]);
        }
        for (int i = nums.size() - 1; i >= 0; i--) {
            int temp = nums[i];
            while (!sta.empty() && sta.top() <= temp) {
                sta.pop();
            }
            if (sta.empty()) {
                ans[i] = -1;
            }
            else {
                ans[i] = sta.top();
            }
            sta.push(temp);
        }
        return ans;
    }



    // LC 138. Copy List with Random Pointer
    // Node* copyRandomList(Node_2* head) {
    //     if (head == nullptr) return nullptr;
    //     unordered_map<Node*, int> original_list;
    //     unordered_map<int, int> random_map;
    //     int i = 1;
    //     Node_2* head_dul = head;
    //     while (head != nullptr) {
    //         original_list[head] = i;
    //         head = head->next;
    //         i++;
    //     }
    //     head = head_dul;
    //     i = 1;
    //     while (head != nullptr) {
    //         if (head->random == nullptr) {
    //             random_map[i] = 0;
    //         }
    //         else {
    //             random_map[i] = original_list.find(head->random)->second;
    //         }
    //         head = head->next;
    //         i++;
    //     }
    //     i = 1;
    //     Node* dummhead = new Node(-1);
    //     Node* dummhead_dul = dummhead;
    //     unordered_map<int, Node*> copyList;
    //     head = head_dul;
    //     while (head != nullptr) {
    //         dummhead->next = new Node(head->val);
    //         copyList[i] = dummhead->next;
    //         i++;
    //         dummhead = dummhead->next;
    //         head = head->next;
    //     }
    //     dummhead = dummhead_dul->next;
    //     i = 1;
    //     while (dummhead != nullptr) {
    //         if (random_map[i] == 0) {
    //             dummhead->random = nullptr;
    //         }
    //         else {
    //             dummhead->random = copyList[random_map[i]];
    //         }
    //         dummhead = dummhead->next;
    //         i++;
    //     }
    //     return dummhead_dul->next;
    // }

private:
    unordered_map<Node*, Node*> visited_clone_graph_dfs;
    int path_count = 0;

};

int main() {

}



