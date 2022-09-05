//
//  Blind 75
//
//  Created by Jiacheng Zhao on 8/27/22.
//

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

// this is for blind 75

//made by Jacob Zhao

// suggestions of improvement are strongly recommended and welcomed

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


// the definitons above are common in leetcode



class Solution {
public:

    // Array

    // 1. Two Sum
    // basic approach
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> myMap;
        vector<int> res;
        for (int i = 0; i < nums.size(); i++) {
            if (myMap.find(target - nums[i]) == myMap.end()) {
                myMap.insert(pair<int, int>(nums[i], i));
            }
            else {
                res.push_back(myMap.find(target - nums[i])->second);
                res.push_back(i);
            }
        }
        return res;
    }
    // time and space complexity are both O(N).


    // 121. Best Time to Buy and Sell Stock
    // greedy approach
    int maxProfit(vector<int>& prices) {
        int Min = INT_MAX, maxSum = 0;
        for (auto a : prices) {
            Min = min(a, Min);
            maxSum = max(maxSum, a - Min);
        }
        return maxSum;
    }

    //dynamic programming approach
    int maxProfit_dp(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n, vector<int>(2,0));
        for (int i = 0; i < n; i++) {
            if (i == 0) {
                dp[i][0] = 0;
                dp[i][1] = -prices[i];
                continue;
            }
            dp[i][0] = max(dp[i - 1][0], dp[i - 1][1] + prices[i]);
            dp[i][1] = max(-prices[i], dp[i - 1][1]);
        }
        return dp[n - 1][0];
    }

    // 217. Contains Duplicate
    bool containsDuplicate(vector<int>& nums) {
       unordered_set<int> s;
       for (auto a : nums) {
            s.insert(a);
       }
       return (s.size() != nums.size());
    }
    // time and space complexity are both O(N).


    // 238. Product of Array Except Self
    vector<int> productExceptSelf(vector<int>& nums) {
        int product = 1;
        vector<int> pos_0;
        vector<int> answer;
        for (int i = 0; i < nums.size(); i++ ) {
            if (nums[i] == 0) {
                pos_0.push_back(i);
                continue;
            }
            product *= nums[i];
        }
        if (pos_0.size()) {
            if (pos_0.size() > 1) {
                vector<int> res(nums.size(), 0);
                return res;
            }
            else {
                vector<int> res(nums.size(), 0);
                res[pos_0[0]] = product;
                return res;
            }
        }
        for (auto a : nums) {
            answer.push_back(product / a);
        }
        return answer;
    }

    // 53. Maximum Subarray
    int maxSubArray(vector<int>& nums) {
        if (nums.size() == 1) return nums[0];
        int count = 0, maxSum = INT_MIN;
        for (auto a : nums) {
            count += a;
            if (count > maxSum) {
                maxSum = count;
            }
            if (count <= 0) count = 0;
        }
        return maxSum;
    }
    //time complexity: O(N), space complexity: O(1)

    // 152. Maximum Product Subarray
    int maxProduct(vector<int>& nums) {
       if (nums.size() == 1) return nums[0];
       int maxSoFar = nums[0], minSoFar = nums[0], ans = INT_MIN;
       for (int i = 0; i < nums.size(); i++) {
            int temp = max(nums[i], max(maxSoFar * nums[i], minSoFar * nums[i]));   // nums[i] will be picked
                                                                                    //if the accumulated product has been really bad
                                                                                    //(even compared to the current number), like(-3,5)
                                                                                    //(preceded by a single negative number)
                                                                                    // or (0,5) (current number has a preceding zero)
            minSoFar = min(nums[i], min(minSoFar * nums[i], maxSoFar * nums[i]));
            maxSoFar = temp;
            ans = max(ans, maxSoFar);
       }
       return ans;
    }
    // time complexity: O(N), space complexity: O(1);


    // LC 153. Find Minimum in Rotated Sorted Array
   int findMin(vector<int>& nums) {
        if (nums.size() == 1) {
            return nums[0];
        }
        int mid = (nums.size() - 1) / 2;
        if (nums[mid] < nums[nums.size() - 1]) {
            vector<int> temp(nums.begin(), nums.begin() + mid + 1);
            return findMin(temp);
        }
        else {
            vector<int> temp(nums.begin() + mid + 1, nums.end());
            return findMin(temp);
        }
    }
    // the problem requires me to use a O(logn) method, in this case I choose to use binary search
    
    // LC 33. Search in Rotated Sorted Array
    int search(vector<int>& nums, int target) {
        if (nums.size() == 1) {
            if (nums[0] == target) return 0;
            else return -1;
        }
        int left = 0, right = nums.size() - 1;
        while (left < right) {
            int mid = (left + right) / 2;
            if (nums[mid] == target) return mid;
            else if (nums[mid] < target) {
                if (nums[mid] < nums[nums.size() - 1]) {
                    if (target <= nums[nums.size() - 1]) {
                        left = mid + 1;
                    }
                    else right = mid - 1;
                }
                else {
                    left = mid + 1;
                }
            }
            else {
                if (nums[mid] < nums[nums.size() - 1]) {
                    right = mid - 1;
                }
                else {
                    if (target >= nums[0]) {
                        right = mid - 1;
                    }
                    else left = mid + 1;
                }
            }
        }
        if (nums[left] == target) {
            return left;
        }
        else return -1;
    }
    // binary search, remember to discuss all possible situations

    // LC 15. 3 sum
    // vector<vector<int>> threeSum(vector<int>& nums) {
    //     vector<vector<int>> ans;
    //     multiset<int> myS;
    //     set<tuple<int, int, int>> s;
    //     multimap<int, pair<int,int>> myMap;
    //     for (int i = 0; i < nums.size(); i++) {
    //         for (int j = i + 1; j < nums.size(); j++) {
    //             int temp = -1 * (nums[i] + nums[j]);
    //             myMap.insert(pair<int, pair<int, int>>(temp, pair<int, int>(nums[i], nums[j])));
    //         }
    //     }
    //     for (auto a : nums) {
    //         myS.insert(a);
    //     }
    //     for (auto iter = myMap.begin(); iter != myMap.end(); iter++) {
    //         multiset<int> temp = myS;
    //         temp.erase(temp.find(iter->second.first));
    //         temp.erase(temp.find(iter->second.second));
    //         if (temp.find(iter->first) != temp.end()) {
    //             if (s.find(pair<int, int>(iter->second.first, iter->second.second)) == s.end()
    //             && s.find(pair<int, int>(iter->second.second, iter->second.first)) == s.end()) {
    //                 s.insert(pair<int, int>(iter->second.second, iter->second.first));
    //             }
    //         }
    //     }
    //     for (auto a = s.begin(); a != s.end(); a++) {
    //         int temp = -1 * (a->first + a->second);
    //         ans.push_back({temp, a->first, a->second});
    //     }
    //     return ans;
    // }


    // LC 11. Container With Most Water

    int maxArea(vector<int>& height) {
        int slow = 0, fast = height.size() - 1, maxWater = INT_MIN;
        while (slow < fast) {
            int tempWater = min(height[slow], height[fast]) * (fast - slow);
            maxWater = max(maxWater, tempWater);
            if (height[slow] <= height[fast]) slow++;   // just need to move the shorter border
            else fast++;
        }
        return maxWater;
    }

    //Graph


    // LC 133. Clone Graph
    // BFS approach
    Node* cloneGraph_BFS(Node* node) {
        if (node == nullptr) {
            return nullptr;
        }
        if (node->neighbors.size() == 0) {
            Node* root = new Node(node->val);
            return root;
        }
        queue<Node*> q;
        q.push(node);
        unordered_map<Node*, Node*> myMap;
        myMap.insert(pair<Node*, Node*>(node, new Node(node->val)));   // use map to store the original and new node
        while (!q.empty()) {
            Node* temp = q.front();
            q.pop();
            for (auto a : temp->neighbors) {
                if (myMap.find(a) == myMap.end()) {
                    q.push(a);
                    myMap.insert(pair<Node*, Node*>(a, new Node(a->val)));
                }
                myMap.find(temp)->second->neighbors.push_back(myMap.find(a)->second);
            }
        }
        return myMap.find(node)->second;
    }

    // DFS approach
    unordered_map<Node*, Node*> myMap_for_clone_dfs;
    Node* cloneGraph_DFS(Node* node) {
        if (node == nullptr) {
            return nullptr;
        }
        if (myMap_for_clone_dfs.find(node) != myMap_for_clone_dfs.end()) {
            return myMap_for_clone_dfs.find(node)->second;
        }
        myMap_for_clone_dfs.insert(pair<Node*, Node*>(node, new Node(node->val)));
        for (auto a : node->neighbors) {
            myMap_for_clone_dfs.find(node)->second->neighbors.push_back(cloneGraph_DFS(a));  // push_back(dfs(neighbor))
        }
        return myMap_for_clone_dfs.find(node)->second;
    }


    // LC 207 course schedule
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> courseDependencies(numCourses, 0);
        unordered_map<int, vector<int>> courseAdjList;
        for (int i = 0; i < prerequisites.size(); i++) {
            courseDependencies[prerequisites[i][0]]++;
            if (courseAdjList.find(prerequisites[i][1]) == courseAdjList.end()) {
                courseAdjList.insert(pair<int, vector<int>>(prerequisites[i][1], vector<int>()));
            }
            courseAdjList.find(prerequisites[i][1])->second.push_back(prerequisites[i][0]);
        }
        queue<int> q;
        vector<bool> visited(numCourses, false);
        for (int i = 0; i < numCourses; i++) {
            if (courseDependencies[i] == 0) {
                q.push(i);
                visited[i] = true;
            }
        }
        while (!q.empty()) {
            int temp = q.front();
            q.pop();
            for (int i = 0; i < courseAdjList[temp].size(); i++) {   //  pay attention to this. use "courseAdjList[temp].size()"
                                                                     //  to avoid some temp does not a vector. DO NOT use
                                                                     //  "courseAdjList.find(temp)->second.size()" !!!
                int temp2 = courseAdjList.find(temp)->second[i];
                if (!visited[temp2]) {
                    courseDependencies[temp2]--;
                    if (courseDependencies[temp2] == 0) {
                        q.push(temp2);
                        visited[temp2] = true;
                    }
                }
            }
        }
        for (auto a : visited) {
            if (!a) return false;
        }
        return true;
    }

    // LC 417. Pacific Atlantic Water Flow
     void dfsForSea(int i, int j, vector<vector<bool>>& visited, vector<vector<int>>& heights, int prev) {
        if (i < 0 || i >= heights.size() || j < 0 || j >= heights[0].size() || visited[i][j] || prev > heights[i][j])
            return;
        
        visited[i][j]=true;
        dfsForSea(i+1,j,visited,heights,heights[i][j]);
        dfsForSea(i-1,j,visited,heights,heights[i][j]);
        dfsForSea(i,j+1,visited,heights,heights[i][j]);
        dfsForSea(i,j-1,visited,heights,heights[i][j]);
        
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        vector<vector<int>> ans;
        int row = heights.size(), column = heights[0].size();
        if (row == 0 && column == 0) {
            return ans;
        }
        int m = heights.size(), n = heights[0].size();
        vector<vector<bool>> pacific(m, vector<bool>(n, false));
        vector<vector<bool>> atlantic(m, vector<bool>(n, false));
        for (int i = 0; i < m; i++) {
            dfsForSea(i, 0, pacific, heights, INT_MIN);
            dfsForSea(i, n-1, atlantic, heights, INT_MIN);
        }
        for (int j = 0; j < n; j++) {
            dfsForSea(0, j, pacific, heights, INT_MIN);
            dfsForSea(m-1, j, atlantic, heights, INT_MIN);
        }
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (pacific[i][j] && atlantic[i][j]) {
                    ans.push_back({i, j});
                }
            }
        }
        return ans;
    }

    // LC 128. Longest Consecutive Sequence

    int longestConsecutive(vector<int>& nums) {
        if (nums.size() == 0) return 0;
        int record = 1;
        set<int> s;
        for (auto a : nums) {
            s.insert(a);
        }    
        int prev = *s.begin();
        int cont = 1;
        for (auto iter = next(s.begin()); iter != s.end(); iter++) {
            if (*iter - prev == 1) {
                cont++;
            }
            else {
                cont = 1;
            }
            record = max(record, cont);
            prev = *iter;
        }
        return record;
    }


    // 261. Graph Valid Tree
    bool validTree(int n, vector<vector<int>>& edges) {
        if (edges.size() != n - 1) {
            return false;
        }
        unordered_map<int, vector<int>> myMap;
        for (auto a :edges) {
            if (myMap.find(a[0]) == myMap.end()) {
                myMap.insert(pair<int, vector<int>>(a[0], vector<int>()));
            }
            myMap.find(a[0])->second.push_back(a[1]);
            if (myMap.find(a[1]) == myMap.end()) {
                myMap.insert(pair<int, vector<int>>(a[1], vector<int>()));
            }
            myMap.find(a[1])->second.push_back(a[0]);
        }
        queue<int> q;
        unordered_set<int> visited;
        q.push(0);
        visited.insert(0);
        while (!q.empty()) {
            int temp = q.front();
            q.pop();
            if (myMap.find(temp) == myMap.end()) break;
            for (int neighbor : myMap.find(temp)->second) {
                if (visited.find(neighbor) == visited.end()) {
                    q.push(neighbor);
                    visited.insert(neighbor);
                }
            }
        }
        return (visited.size() == n);
    }

    // LC 323. Number of Connected Components in an Undirected Graph
    void dfs_for_countComponents(int i, vector<bool>& visited, vector<vector<int>> adj) {
        if (visited[i]) return;
        visited[i] = 1;
        for (auto edge : adj[i]) {
             dfs_for_countComponents(edge, visited, adj);
        }
    }
    int countComponents(int n, vector<vector<int>>& edges) {
        int count = 0;
        vector<vector<int>> adj(n);
        for (auto a : edges) {
            adj[a[1]].push_back(a[0]);
            adj[a[0]].push_back(a[1]);
        }
        vector<bool> visited(n, false);
        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                dfs_for_countComponents(i, visited, adj);
                count++;
            }
        }
        return count;
    }

    // Linked List
    //206. Reverse Linked List
    ListNode* reverseList(ListNode* head) {
        if (head == nullptr) {
            return head;
        }
        stack<int> s;
        ListNode* dummy = head;
        while (dummy != nullptr) {
            s.push(dummy->val);
            dummy = dummy->next;
        }
        dummy = head;
        while (!s.empty()) {
            dummy->val = s.top();
            s.pop();
            dummy = dummy->next;
        }
        return head;
    }

    // LC 141. Linked List Cycle
    // initutive approach: hash table 
    // pass

    // O(1) space approach
    bool hasCycle(ListNode *head) {
        if (head == nullptr) 
            return false;
        if (head->next == head) 
            return true;
        ListNode* slow = head;
        ListNode* fast = head;
        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast)
                return true;
        }
        return false;
    }

    // LC 21. Merge Two Sorted Lists
    void compare(ListNode* list1, ListNode* list2, ListNode* dummy) {
        if (list1 == nullptr) {
            dummy->next = list2;
            return;
        }
        if (list2 == nullptr) {
            dummy->next = list1;
            return;
        }
        if (list1->val <= list2->val) {
            dummy->next = list1;
            dummy = dummy->next;
            compare(list1->next, list2, dummy);
        }
        else {
            dummy->next = list2;
            dummy = dummy->next;
            compare(list1, list2->next, dummy);
        }
    }
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if (list1 == nullptr) {
            return list2;
        }
        if (list2 == nullptr) {
            return list1;
        }
        ListNode* dummy = new ListNode();
        compare(list1, list2, dummy);
        return dummy->next;

    }

    // LC 19. Remove Nth Node From End of List
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if (head->next == nullptr) {
            return nullptr;
        }
        stack<ListNode*> s;
        ListNode* fakeHead = new ListNode();
        fakeHead->next = head;                 // use a dummy to replace the real head, in order to avoid the situation that n = linkedList's size
        ListNode* dummy = fakeHead;
        while (dummy != nullptr) {
            s.push(dummy);
            dummy = dummy->next;
        }
        int count = 0;
        while (!s.empty()) {
            count++;
            if (count == n + 1) {
                s.top()->next = s.top()->next->next;
                break;
            }
            s.pop();
        }
        return fakeHead->next;
    }

    // LC 143. Reorder List
    void reorderList(ListNode* head) {
        if (head == nullptr || head->next == nullptr) {
            return;
        }
        queue<ListNode*> q;         //regular sequence
        stack<ListNode*> s;          // reverse sequence
        ListNode* dul = head;
        ListNode* dummyHead = head;
        while (dul != nullptr) {
            q.push(dul);
            s.push(dul);
            dul = dul->next;
        }
        int length = s.size();          // the size of this linked list
        q.pop();                     // remove the first one in queue, which is head
        int count = 1;           
        while (count < length) {       // break the loop when we get the whole list
            if (count % 2) {
                s.top()->next = nullptr;   // make each s.top()->next = nullptr to avoid possible circle
                dummyHead->next = s.top();
                dummyHead = dummyHead->next;
                s.pop();
                count++;
            }
            else {
                q.front()->next = nullptr;         // same as before. To avoid possible circle
                dummyHead->next = q.front();
                dummyHead = dummyHead->next;
                q.pop();
                count++;   
            }
        }
        return;
    }

    // LC 104. Maximum Depth of Binary Tree
    void dfsFOrMaxDepth(TreeNode* root, int count, int& depth) {
        if (root == nullptr) {
            return;
        }
        count++;
        depth = max(depth, count);
        dfsFOrMaxDepth(root->left, count, depth);
        dfsFOrMaxDepth(root->right, count, depth);
    }
    int maxDepth(TreeNode* root) {
        int depth = 0;
        dfsFOrMaxDepth(root, 0, depth);
        return depth;
    }


    // LC 100. Same Tree
    bool isSameTree(TreeNode* p, TreeNode* q) {
        queue<TreeNode*> que;
        queue<TreeNode*> que2; 
        if (p == NULL && q == NULL)
        {
            return true;
        }   
        que.push(p);
        que2.push(q);
        while (!que.empty())
        {
                TreeNode* node = que.front();
                que.pop();
                TreeNode* node2 = que2.front();
                que2.pop();
                if (node == NULL && node2 == NULL) continue;
                if ( (node == NULL && node2 != NULL) || (node != NULL && node2 == NULL) || (node->val != node2->val)) {
                    return false;
                }
                    que.push(node->left);
                    que2.push(node2->left);

                    que.push(node->right);
                    que2.push(node2->right);
        }
        return true;
    }

    // LC 226. Invert Binary Tree
    TreeNode* invertTree(TreeNode* root) {
        if (root == nullptr) return root;
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            TreeNode* temp = q.front();
            q.pop();
            if (temp->left) q.push(temp->left);
            if (temp->right) q.push(temp->right);

            TreeNode* temporary =  temp->left;
            temp->left = temp->right;
            temp->right = temporary;
        }
        return root;
    }


    // LC 105 Construct Binary Tree from Preorder and Inorder Traversal

    TreeNode* traversal(vector<int>& preorder, vector<int>& inorder) {
        if (preorder.size() == 0) {
            return nullptr;
        }
        int rootVal = preorder[0];
        int delimiter = -1;
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
        TreeNode* root = new TreeNode(rootVal);
        root->left = traversal(leftPreorder, leftInorder);
        root->right = traversal(rightPreorder, rightInorder);
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        auto root = traversal(preorder, inorder);
        return root;
    }


    // LC 98. Validate Binary Search Tree
    
    // we use inorder traversal since the sequence of inorder is "left, node, right" 
	 //  In this case when we get the whole sequence number of inorder traversal, 
	 // each number should be smaller than the next one if it is a BST
	 
    void inorder(TreeNode* root, bool& isValid, vector<int>& rec) {
        if (root == nullptr) return;
        inorder(root->left, isValid, rec);
        rec.push_back(root->val);
        if (rec.size() >= 2) {
            if (rec[rec.size() - 1] <= rec[rec.size() - 2]) {
                isValid = 0;                     // change isValid to false if we find one number is greater than or equal to the next one 
            }
        }
        inorder(root->right, isValid, rec);
    }
    
    bool isValidBST(TreeNode* root) {
        if (root == nullptr) {
            return 1;
        }
        vector<int> rec;
        inorder(root, isValid, rec);
        return isValid;
    }

    // LC 235. Lowest Common Ancestor of a Binary Search Tree
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (p == root || q == root) {
            return root;
        } 
        unordered_map<TreeNode*, TreeNode*> child_parent;
        child_parent.insert(pair<TreeNode*, TreeNode*>(root, nullptr));
        queue<TreeNode*> que;
        que.push(root);
        while (child_parent.find(p) != child_parent.end() || child_parent.find(q) != child_parent.end()) {
            TreeNode* curr = que.front();
            que.pop();
            if (curr->left) {
                que.push(curr->left);
                child_parent.insert(pair<TreeNode*, TreeNode*>(curr->left, curr));
            }
            if (curr->right) {
                que.push(curr->right);
                child_parent.insert(pair<TreeNode*, TreeNode*>(curr->right, curr));
            }
        }
        unordered_set<TreeNode*> mySet;
        while (p != nullptr) {
            mySet.insert(p);
            p = child_parent.find(p)->second;
        }
        while (mySet.find(q) == mySet.end()) {
            q = child_parent.find(q)->second;
        }
        return q;
    }


private:
    bool isValid = 1;
};


