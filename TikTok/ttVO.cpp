#include "vector"
#include "queue"
#include "set"
#include "unordered_set"
#include "map"
#include "unordered_map"
#include "string"
#include "iostream"
#include "algorithm"
#include "stack"
#include "list"
#include "cwctype"
#include "numeric"
using namespace std;

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (p == root || q == root) return root;
        TreeNode* root_dul = root;
        while (root != nullptr) {
        }
    }
};

// LC 33. Search in Rotated Sorted Array

    int search(vector<int>& nums, int target) {
        if (nums.size() == 1) {
            if (target == nums[0]) {
                return 0;
            }
            else return -1;
        }
        int left = 0, right = nums.size() - 1;

        // use the double pointer and figure out all the possible situations

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
                else left = mid + 1;
            }
            else {
                if (nums[mid] > nums[nums.size() - 1]) {
                    if (target <= nums[nums.size() - 1]) {
                        left = mid + 1;
                    }
                    else right = mid - 1;
                }
                else right = mid - 1;
            }
        }
        if (nums[left] == target) {
            return left;
        }
        return -1;
    }

    // LC 1235. Maximum Profit in Job Scheduling
    int memo[500001];
    int maxProfit(vector<int>& startTime, map<int, vector<int>>& myMap) {
        int n = startTime.size();
        for (int position = n - 1; position >= 0; position--) {
            int currProfit = 0;
            int nextIndex = lower_bound(startTime.begin(), startTime.end(), myMap.find(position)->second[0]) -
                            startTime.begin();
            if (nextIndex != n ) {
                currProfit = myMap.find(position)->second[1] + memo[nextIndex];
            }
            else {
                currProfit = myMap.find(position)->second[1];
            }
            if (position == n - 1) {
                memo[position] = currProfit;
            }
            else {
                memo[position] = max(currProfit, memo[position + 1]);
            }
        }
        return memo[0];
    }

    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        map<int, vector<int>> myMap;
        for (int i = 0; i < startTime.size(); i++) {
            myMap.insert(pair<int, vector<int>>(startTime[i], {endTime[i], profit[i]}));
        }
        int i = 0;
        for (auto it : myMap) {
            startTime[i] = it.first;
            i++;
        }
        return maxProfit(startTime, myMap);
    }

    // LC 55. Jump Game
    bool canJump(vector<int>& nums) {
        if (nums.size() == 1) {
            return true;
        }
        int cover = nums[0];
        for (int i = 1; i <= cover; i++) {
            if (cover >= nums.size() - 1) {
                return true;
            }
            cover = max(cover, i + nums[i]);
        }
        return false;
    }

    // LC 1227. Airplane Seat Assignment Probability
    double nthPersonGetsNthSeat(int n) {
        return n == 1 ? 1.0 : 0.5;
    }

    // LC 165. Compare Version Numbers
    int compareVersion(string version1, string version2) {
        int length1 = version1.size();
        int length2 = version2.size();
        vector<int> num1;
        vector<int> num2;
        string temp1 = "", temp2 = "";
        for (int i = 0; i < max(length1, length2); i++) {
            if (i < version1.size()) {
                if (version1[i] != '.') {
                    temp1 += version1[i];
                }
                else {
                    num1.push_back(stoi(temp1));
                    temp1 = "";
                }
            }
            if (i < version2.size()) {
                if (version2[i] != '.') {
                    temp2 += version2[i];
                }
                else {
                    num2.push_back(stoi(temp2));
                    temp2 = "";
                }
            }
        }
        int index = 0;
        for (;index < min(num1.size(), num2.size()); index++) {
            if (num1[index] > num2[index]) return 1;
            if (num1[index] < num2[index]) return -1;
        }
        if (num1.size() == num2.size()) return 0;
        else if (num1.size() > num2.size()) {
            while (index < num1.size()) {
                if (num1[index] > 0) return 1;
                index++;
            }
            return 0;
        }
        else {
            while (index < num2.size()) {
                if (num2[index] > 0) return -1;
                index++;
            }
            return 0;
        }
    }

// LC 2217

long long concatenate(long long num, int intLength) {
    string num_str = to_string(num);
    if (intLength % 2) {
        string dul_num_str = num_str;
        reverse(dul_num_str.begin(), dul_num_str.end());
        num_str.pop_back();     // pop the middle digit
        num_str += dul_num_str;
    }
    else {
        string dul_num_str = num_str;
        reverse(dul_num_str.begin(), dul_num_str.end());
        num_str += dul_num_str;
    }
    return stoll(num_str);
}

vector<long long> kthPalindrome(vector<int>& queries, int intLength) {
    vector<long long> ans(queries.size(), -1);
    int num_max = pow(10, (intLength + 1) / 2), num_min = pow(10, (intLength + 1) / 2 - 1);
    int num = num_max - num_min;
    for (auto a : queries) {
        if (a > num) {
            ans.push_back(-1);
            continue;
        }
        long long temp_num = num_min + a - 1;
        ans.push_back(concatenate(temp_num, intLength));
    }
    return ans;
}

// LC 1235. Maximum Profit in Job Scheduling
    class Solution {
public:
    // maximum number of jobs are 50000
    int memo[50001];

    int findMaxProfit(vector<int>& startTime, vector<vector<int>>& jobs) {
        int length = startTime.size();

        for (int position = length - 1; position >= 0; position--) {
            // it is the profit made by scheduling the current job
            int currProfit = 0;

            // nextIndex is the index of next non-conflicting job
            // this step is similar to the binary search as in the java solution
            // lower_bound will return the iterator to the first element which is
            // equal to or greater than the element at `jobs[position][1]`
            int nextIndex = lower_bound(startTime.begin(), startTime.end(), jobs[position][1]) - startTime.begin();

            // if there is a non-conflicting job possible add it's profit
            // else just consider the curent job profit
            if (nextIndex != length) {
                currProfit = jobs[position][2] + memo[nextIndex];
            } else {
                currProfit = jobs[position][2];
            }

            // storing the maximum profit we can achieve by scheduling
            // non - conflicting jobs from index i to the end of array
            if (position == length - 1) {
                memo[position] = currProfit;
            } else {
                memo[position] = max(currProfit, memo[position + 1]);
            }
        }

        return memo[0];
    }

    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        vector<vector<int>> jobs;

        // storing job's details into one list
        // this will help in sorting the jobs while maintaining the other parameters
        for (int i = 0; i < profit.size(); i++) {
            jobs.push_back({startTime[i], endTime[i], profit[i]});
        }

        sort(jobs.begin(), jobs.end());

        // binary search will be used in startTime so store it as separate list
        for (int i = 0; i < profit.size(); i++) {
            startTime[i] = jobs[i][0];
        }

        return findMaxProfit(startTime, jobs);
    }
};


    // LC 773. Sliding Puzzle

int slidingPuzzle(std::vector<std::vector<int>>& board) {
    string start = "", target = "123450";
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 3; j++) {
            start += to_string(board[i][j]);
        }
    }
    vector<vector<int>> directions = {{1, 3}, {0, 2, 4}, {1, 5}, {0, 4}, {1, 3, 5}, {2, 4}};
    unordered_set<string> visited;
    queue<string> q;
    q.push(start);
    visited.insert(start);
    int count = 0;
    while (!q.empty()) {
        int size = q.size();
        for (int i = 0; i < size; i++) {
            string cur = q.front();
            q.pop();
            if (cur == target) {
                return count;
            }
            int zero = cur.find('0');
            for (int i = 0; i < directions[zero].size(); i++) {
                string next = cur;
                char temp = next[zero];
                next[zero] = next[directions[zero][i]];
                next[directions[zero][i]] = temp;
                if (visited.find(next) == visited.end()) {
                    visited.insert(next);
                    q.push(next);
                }
            }
        }
        count++;
    }
    return -1;
}

// LC 96. Unique Binary Search Trees
int numTrees(int n) {
    vector<int> dp(n + 1, 0);
    dp[0] = 1;
    dp[1] = 1;
    for (int i = 2; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            dp[i] += dp[j - 1] * dp[i - j];  // use the permutations
        }
    }
    return dp[n];
}

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

bool areTreesDifferent(TreeNode* root1, TreeNode* root2) {
    // If both nodes are NULL, they are the same
    if (!root1 && !root2) return false;

    // If one of them is NULL and the other isn't, they are different
    if (!root1 || !root2) return true;

    // If the values are different, the trees are different
    if (root1->val != root2->val) return true;

    // Recursively check left and right subtrees
    return areTreesDifferent(root1->left, root2->left) || areTreesDifferent(root1->right, root2->right);
}


// LC 93. Restore IP Addresses

void dfs_93(string& s, vector<string> &ans, string cur, int count) {
        if (count > 3) {
            if (s.empty()) {
                cur.pop_back();
                ans.push_back(cur);
            }
            return;
        }
        for (int i = 1; i <= 3 && i <= s.size(); i++) {
                string temp = s.substr(0, i), s_dul = s, cur_dul = cur;
                if (i == 1 || (i == 2 && stoi(temp) >= 10) || (stoi(temp) <= 255 && stoi(temp) >= 100)) {
                    cur_dul += temp + ".";
                    s_dul.erase(0, i);
                    dfs_93(s_dul, ans, cur_dul, count + 1);  // rememeber NOT to change the current state's count number
                }
        }
        return;
    }

    vector<string> restoreIpAddresses(string s) {
        if (s.size() > 12 || s.size() < 4) return {};
        vector<string> ans;
        dfs_93(s, ans, "", 0);
        return ans;
    }

// LC 394. Decode String


    string decodeString(string s) {
    stack<char> sta;
    unordered_set<char> num_set = {'0','1','2','3','4','5','6','7','8','9'};
    for (auto a : s) {
        if (a == ']') {
            string decodedString = "";
            while (sta.top() != '[') {
                decodedString += sta.top();
                sta.pop();
            }
            sta.pop();
            reverse(decodedString.begin(), decodedString.end());
            string num = "";
            while (!sta.empty() && num_set.count(sta.top()) != 0 ) {
                num += sta.top();
                sta.pop();
            }
            reverse(num.begin(), num.end());
            //que.push(pair<string, int>(decodedString, stoi(num)));
            int count = stoi(num);
            while (count) {
                for (int i = 0; i < decodedString.size(); i++) {
                    sta.push(decodedString[i]);
                }
                count--;
            }
        }
        else {
            sta.push(a);
        }
    }
    string res = "";
    while (!sta.empty()) {
        res = sta.top() + res;
        sta.pop();
    }
    return res;
}

string dec(string& s, int& index) {
        string res;
        while (index < s.size() && s[index] != ']') {
            if (!isdigit(s[index])) {
                res += s[index];
                index++;
            }
            else {
                string num;
                while (isdigit(s[index]) && index < s.size()) {
                    num += s[index];
                    index++;
                }
                index++;  // to avoid '['
                string decodedString = dec(s, index);
                index++;
                int count = stoi(num);
                while (count) {
                    res += decodedString;
                    count--;
                }
            }
        }
        return res;
    }
    string decodeString(string s) {
        int index = 0;
        return dec(s, index);
    }

//Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};



    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (p == root || q == root) return root;
        unordered_map<TreeNode*, TreeNode*> child_parent;
        queue<TreeNode*> myQue;
        myQue.push(root);
        child_parent.insert(pair<TreeNode*, TreeNode*>(root, nullptr));
        while (!myQue.empty()) {
            int size = myQue.size();
            for (int i = 0; i < size; i++) {
                TreeNode* cur = myQue.front();
                myQue.pop();
                if (cur->left) {
                    child_parent.insert(pair<TreeNode*, TreeNode*>(cur->left, cur));
                    myQue.push(cur->left);
                }
                if (cur->right) {
                    child_parent.insert(pair<TreeNode*, TreeNode*>(cur->right, cur));
                    myQue.push(cur->right);
                }
            }
        }
        unordered_set<TreeNode*> mySet;
        TreeNode* temp = p;
        while (temp != nullptr) {
            if (mySet.find(temp) == mySet.end()) {
                mySet.insert(temp);
            }
            temp = child_parent.find(temp)->second;
        }
        temp = q;
        while (temp != nullptr) {
            if (mySet.find(temp) != mySet.end()) {
                return temp;
            }
            temp = child_parent.find(temp)->second;
        }

    }

struct Node {
        int key;
        int val;
        Node* next;
        Node* prev;
        Node(int key, int val): key(key), val(val), next(nullptr), prev(nullptr) {}
};

class LRUCache {
public:

    // idea: efficient way to implement queue -> linked list -> efficient way to find the node's previous node -> doubly
    // linked list

    unordered_map<int, Node*> myMap;
    Node* tail;
    Node* head;
    int capacity;

    void addNode(Node* node) {
        Node* temp = tail->prev;
        temp->next = node;
        node->prev = temp;
        node->next = tail;
        tail->prev = node;
    }

    void deleteNode(Node* node) {
        node->prev->next = node->next;
        node->next->prev = node->prev;
    }

    LRUCache(int capacity) {  // use the constructor to initialize the member elements
                              // don't initialize the elements directly in the class scope
        this->capacity = capacity;
        tail = new Node(-1, -1);
        head = new Node(-1, -1);
        tail->prev = head;
        head->next = tail;
    }

    int get(int key) {
        if (myMap.find(key) == myMap.end()) {
            return -1;
        }
        Node* node = myMap.find(key)->second;
        deleteNode(node);
        addNode(node);
        return node->val;
    }

    void put(int key, int value) {
        if (myMap.find(key) != myMap.end()) {
            Node* node = myMap.find(key)->second;
            node->val = value;
            deleteNode(node);
            addNode(node);
            return;
        }
        Node* cur = new Node(key, value);
        myMap.insert(pair<int, Node*>(key, cur));
        addNode(cur);
        if (myMap.size() > capacity) {
            Node* temp = head->next;
            myMap.erase(temp->key);
            deleteNode(temp);
        }
    }
};

class LRUCache {
public:
    list<pair<int, int>> lru;
    unordered_map<int, list<pair<int, int>>::iterator> myMap;
    int capacity;
    LRUCache(int capacity) {
        this->capacity = capacity;
    }

    int get(int key) {
        if (myMap.find(key) == myMap.end()) {
            return -1;
        }
        list<pair<int, int>>::iterator itr = myMap.find(key)->second;
        int value = itr->second;
        lru.erase(itr);
        lru.push_front(pair<int, int>(key, value));
        myMap.find(key)->second = lru.begin();
        return value;
    }

    void put(int key, int value) {
        if (myMap.find(key) != myMap.end()) {
            auto itr = myMap.find(key);
            lru.erase(itr->second);
            lru.push_front(pair<int, int>(key, value));
            itr->second = lru.begin();
            return;
        }
        lru.push_front(pair<int, int>(key, value));
        myMap.insert(pair<int, list<pair<int,int>>::iterator>(key, lru.begin()));
        if (lru.size() > capacity) {
            auto it = myMap.find(lru.rbegin()->first);
            myMap.erase(it);
            lru.pop_back();
        }
    }
};

// Lc 621 Task Scheduler
int leastInterval(vector<char>& tasks, int n) {
        if (n == 0) return tasks.size();
        unordered_map<char, int> myMap;
        for (auto a : tasks) {
            if (myMap.find(a) == myMap.end()) {
                myMap.insert(pair<char, int>(a, 1));
                continue;
            }
            myMap.find(a)->second++;
        }
        vector<int> vec;
        for (auto it : myMap) {
            vec.push_back(it.second);
        }
        sort(vec.begin(), vec.end());
        int index = vec.size() - 1;
        int f_max = vec[index];
        int idle_time = (vec[index] - 1) * n;
        while (index >= 1) {
            idle_time -= min(vec[index - 1], f_max - 1); // f_max - 1 means there is a task whose f is equal to f_max
            index--;
        }
        idle_time = max(idle_time, 0);
        return tasks.size() + idle_time;
    }

// LC 666. Path Sum IV
int pathSum(vector<int>& nums) {
    vector<vector<int>> mem(5, vector<int>(8, 0));
    int max_level = 0;
    for (auto num : nums) {
        int level = num / 100, position = num / 10 % 10 - 1, val = num % 10;
        max_level = max(max_level, level);
        mem[level][position] += mem[level - 1][position / 2] + val; // the value of the last node of each subtree is the path sum
    }
    int sum = 0;
    for (int i = 1; i <= max_level; i++) {
        for (int j = 0; j < 8; j++) {
            if (i == max_level || (mem[i][j] && !mem[i + 1][j * 2] && !mem[i + 1][j * 2 + 1])) { // there are some
            // corner cases that the levels of right and left binary trees are not the same
                sum += mem[i][j];
            }
        }
    }
    return sum;
}


// LC 1345. Jump Game IV
    int minJumps(vector<int>& arr) {
        if (arr.size() == 1) return 0;
        unordered_map<long, queue<long>> myMap;
        for (int i = 0; i < arr.size(); i++) {
            if (myMap.find(arr[i]) == myMap.end()) {
                queue<long> que;
                myMap.insert(pair<long, queue<long>>(arr[i], que));
            }
            myMap.find(arr[i])->second.push(i);
        }
        unordered_set<long> myset;
        queue<long> q;
        q.push(0);
        myset.insert(0);
        int step = 0;
        while (!q.empty()) {
            int size = q.size();
            for (int i = 0; i < size; i++) {
                int index = q.front(); q.pop();
                if (index == arr.size() - 1) return step;
                if (index + 1 < arr.size() && myset.find(index + 1) == myset.end()) {
                    q.push(index + 1);
                    myset.insert(index + 1);
                }
                if (index - 1 >= 0 && myset.find(index - 1) == myset.end()) {
                    q.push(index - 1);
                    myset.insert(index - 1);
                }
                if (myMap.find(arr[index])->second.size() > 1) {
                    while (myMap.find(arr[index])->second.size()) {
                        long num = myMap.find(arr[index])->second.front();
                        if (myset.find(num) == myset.end()) {
                            q.push(num);
                            myset.insert(num);
                        }
                        myMap.find(arr[index])->second.pop();
                    }
                }
            }
            step++;
        }
        return -1;
    }


    vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) {
        unordered_map<string, vector<string>> adj;
        unordered_map<string, int> inDegree;
        vector<string> ans;
        for (int i = 0; i < ingredients.size(); i++) {
            for (int j = 0; j < ingredients[0].size(); j++) {
                adj[ingredients[i][j]].push_back(recipes[i]);
                inDegree[recipes[i]]++;
            }
        }
        queue<string> que;
        for (auto a : supplies) {
            que.push(a);
        }
        while (!que.empty()) {
            string cur = que.front();
            que.pop();
            for (auto a : adj[cur]) {
                inDegree[a]--;
                if (inDegree[a] == 0) {
                    ans.push_back(a);
                    que.push(a);
                    inDegree.erase(a);
                }
            }
        }
        return ans;
    }

    int minMeetingRooms(vector<vector<int>>& intervals) {
        int roomNum = 0, availality = 0;
        vector<int> start, end;
        for(auto a : intervals) {
            start.push_back(a[0]);
            end.push_back(a[1]);
        }
        sort(start.begin(), start.end());
        sort(end.begin(), end.end());
        int s = 0, e = 0;
        while (s < start.size()) {
            if (start[s] < end[e]) {
                if (availality > 0) {
                    availality--;
                }
                else {
                    roomNum++;
                }
                s++;
            }
            else {
                availality++;
                e++;
            }
        }
        return roomNum;
    }

    int numBusesToDestination(vector<vector<int>>& routes, int source, int target) {
        if (source == target) return 0;
        int res = 1;
        unordered_map<int, vector<int>> stop_bus;
        for (int i = 0; i < routes.size(); i++) {
            for (auto a : routes[i]) {
                if (stop_bus.find(a) == stop_bus.end()) {
                    stop_bus.insert(pair<int, vector<int>>(a, vector<int>()));
                }
                stop_bus[a].push_back(i);
            }
        }
        queue<int> que;
        unordered_set<int> stop_visited;
        unordered_set<int> route_visited;
        stop_visited.insert(source);
        for (auto a : stop_bus.find(source)->second) {
            route_visited.insert(a);
            for (auto b : routes[a]) {
                if (stop_visited.find(b) == stop_visited.end()) {
                    stop_visited.insert(b);
                    que.push(b);
                }
            }
        }
        while (!que.empty()) {
            int size = que.size();
            for (int i = 0; i < size; i++) {
                int stop = que.front(); que.pop();
                if (stop == target) return res;
                for (auto a : stop_bus[stop]) {
                    if (!route_visited.count(a)) {
                        route_visited.insert(a);
                        for (auto b : routes[a]) {
                            if (!stop_visited.count(b)) {
                                que.push(b);
                                stop_visited.insert(b);
                            }
                        }
                    }
                }
            }
            res++;
        }
        return -1;
    }

    // LC 1249. Minimum Remove to Make Valid Parentheses
    string minRemoveToMakeValid(string s) {
        unordered_set<int> left_p_index;
        unordered_set<int> right_p_index;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(') {
                left_p_index.insert(i);
            }
            else if (s[i] == ')') {
                if (left_p_index.empty()) {
                    right_p_index.insert(i);
                }
                else left_p_index.erase(left_p_index.begin());
            }
        }
        string res;
        for (int i = 0; i < s.size(); i++) {
            if (left_p_index.count(i) || right_p_index.count(i)) {
                continue;
            }
            res += s[i];
        }
        return res;
    }

    int twoCitySchedCost(vector<vector<int>>& costs) {
        int res = 0, N = costs.size() / 2;
        vector<int> diff;
        for (auto a : costs) {
            res += a[0];
            diff.push_back(a[1] - a[0]);
        }
        sort(diff.begin(), diff.end());
        for (int i = 0; i < N; i++) {
            res += diff[i];
        }
        return res;
    }

    vector<vector<int>> findMissingRanges(vector<int>& nums, int lower, int upper) {
        vector<vector<int>> ans;
        int n = nums.size();
        if (n == 0) return {{lower, upper}};
        if (nums[0] > lower) ans.push_back({lower, nums[0] - 1});
        for (int i = 0; i < n - 1; i++) {
            if (nums[i + 1] - nums[i] == 1) continue;
            ans.push_back({nums[i] + 1, nums[i + 1] - 1});
        }
        if (nums[n - 1] < upper) ans.push_back({nums[n -1] + 1, upper});
        return ans;
    }

    int findLengthOfLCIS(vector<int>& nums) {
        if (nums.empty()) return 0;
        int ans = 1;
        for (int i = 0; i < nums.size() - 1; i++) {
            if (nums[i + 1] > nums[i]) {
                int count = 1;
                while (i < nums.size() - 1 && nums[i + 1] > nums[i]) {  // check if i is in the range first !!!
                    count++;
                    i++;
                }
                ans = max(ans, count);
                i--;
            }
        }
        return ans;
    }

    // dp solution
    int findLengthOfLCIS_dp(vector<int>& nums) {
        int ans = 1;
        vector<int> dp(nums.size(), 1);
        for (int i = 0; i < nums.size() - 1; i++) {
            if (nums[i + 1] > nums[i]) {
                dp[i + 1] = max(dp[i + 1], dp[i] + 1);
            }
        }
        return *max_element(dp.begin(), dp.end());
    }

    int wordsTyping(vector<string>& sentence, int rows, int cols) {
        string allWords;
        for (auto word : sentence) {
            allWords += word + ' ';
        }
        int allWordsLength = allWords.size();
        int start = 0;
        for (int i = 0; i < rows; i++) {
            start += cols;
            if (allWords[start % allWordsLength] == ' ') {
                start++;
            }
            else {
                while (start > 0 && allWords[start & allWordsLength] != ' ') {
                    start--;
                }
            }
        }
        return start / allWordsLength;
    }

    int calculate(string s) {
        int len = s.size();
        if (len == 0) return 0;
        stack<int> mySta;
        int ans = 0;
        char operation = '+';
        string currNum;
        for (int i = 0; i < len; i++) {
            if (isdigit(s[i])){
                currNum += s[i];
            }
            if ((!isdigit(s[i]) && !iswspace(s[i])) || i == len - 1) {
                if (operation == '-') {
                    mySta.push(stoi(currNum) * -1);
                }
                else if (operation == '+') {
                    mySta.push(stoi(currNum));
                }
                else if (operation == '*') {
                    int temp = mySta.top();
                    mySta.pop();
                    mySta.push(temp * stoi(currNum));
                }
                else if (operation == '/') {
                    int temp = mySta.top();
                    mySta.pop();
                    mySta.push(temp / stoi(currNum));
                }
                operation = s[i];
                currNum = "";
            }
        }
        while (!mySta.empty()) {
            ans += mySta.top();
            mySta.pop();
        }
        return ans;
    }


    int calculate(string s) {
        if (s.size() == 0) return 0;
        int ans = 0;
        vector<int> sta;
        char op = '+';
        long num = 0;
        for (int i = 0; i < s.size(); i++) {
            if (isdigit(s[i])) {
                num = num * 10 + s[i] - '0';
            }
            if ((!isdigit(s[i]) && !iswspace(s[i])) || i == s.size() - 1) { // it's if, NOT else if ! We want to run this
                                                                            // part of code when i is the last element of the string which is a integer
                if (op == '+') {
                    sta.push_back(num);
                }
                else if (op == '-') {
                    sta.push_back(-num);
                }
                else if (op == '*') {
                    int temp = sta.back();
                    sta.pop_back();
                    sta.push_back(temp * num);
                }
                else if (op == '/') {
                    int temp = sta.back();
                    sta.pop_back();
                    sta.push_back(temp / num);
                }
                op = s[i];
                num = 0;
            }
        }
        return accumulate(sta.begin(), sta.end(), 0);
    }

    int calculate(string s) {
        if (s.size() == 0) return 0;
        int i = 0;
        return cal(s, i);
    }
    int cal(string s, int& i) {
        vector<int> nums;
        char op = '+';
        int num = 0;
        for (; i < s.size() && op != ')'; i++) {
            if (iswspace(s[i])) continue;
            if (isdigit(s[i])) {
                num = getNum(s, i);
            } else if (s[i] == '(') {
                num = cal(s, ++i);
            }
            switch (op) {
                case '+': nums.push_back(num); break;
                case '-': nums.push_back(-num); break;
                case '*': nums.back() *= num; break;
                case '/': nums.back() /= num; break;
            }
            op = s[i];
        }
        return accumulate(nums.begin(), nums.end(), 0);
    }
    int getNum(string s, int& i) {
        int ans = 0;
        while (i < s.size() && isdigit(s[i])) {
            ans = ans * 10 + s[i++] - '0';
        }
        return ans;
    }

    double champagneTower(int poured, int row, int glass) {
        double wine[101][101] = {0};
        wine[0][0] = poured;
        for (int i = 0; i < 100; i++) {
            for (int j = 0; j <= i; j++) {
                if (wine[i][j] > 1) {
                    wine[i + 1][j] += (wine[i][j] - 1) / 2.0;
                    wine[i + 1][j + 1] += (wine[i][j] - 1) / 2.0;
                    wine[i][j] = 1;
                }
            }
        }
        return wine[row][glass];
    }

    int longestPalindromeSubseq(string s) {
        vector<vector<int>> dp(s.size(), vector<int>(s.size(), 0));
        for (int i = 0; i < s.size(); i++) {
            dp[i][i] = 1;
        }
        for (int i = s.size() - 1; i >= 0; i--) {
            for (int j = i + 1; j < s.size(); j++) {
                if (s[i] == s[j]) {
                    dp[i][j] = dp[i + 1][j - 1] + 2;
                }
                else {
                    dp[i][j] = max(dp[i + 1][j], dp[i][j - 1]);
                }
            }
        }
        return dp[0][s.size() - 1];
    }

    bool search(TreeNode* root, int target, string &s){
        if(root==NULL) {
            return false;
        }
        if(root->val==target) {
            return true;
        }

        bool find1=search(root->left,target, s+='L');  // search on left side
        if(find1) return true;
        s.pop_back(); // backtracking step

        bool find2= search(root->right,target, s+='R'); // search on right side
        if(find2) return true;
        s.pop_back(); // backtracking step
        return false;
    }

     TreeNode* lca(TreeNode* root ,int n1 ,int n2)
    {
       if(root==NULL)
       return NULL;
       if(root->val==n1 or root->val==n2)
       return root;

       TreeNode* left=lca(root->left,n1,n2);
       TreeNode* right=lca(root->right,n1,n2);

       if(left!=NULL && right!=NULL)
       return root;
       if(left)
       return left;
       if(right)
       return right;

       return NULL; // not present in tree

    }
    string getDirections(TreeNode* root, int startValue, int destValue) {
        TreeNode* temp=lca(root,startValue,destValue);

        string s1,s2;
        search(temp,startValue,s1);
        search(temp,destValue,s2);
        for(auto &it:s1){
            it='U';
        }
        return s1+s2;
    }

int main() {
    TreeNode* tree1 = new TreeNode(1);
    tree1->left = new TreeNode(2);
    tree1->left->left = new TreeNode(3);

    TreeNode* tree2 = new TreeNode(1);
    tree2->left = new TreeNode(2);
    tree2->right = new TreeNode(3);

    if (areTreesDifferent(tree1, tree2)) {
        std::cout << "The trees are different." << std::endl;
    } else {
        std::cout << "The trees are the same." << std::endl;
    }

    return 0;
}

