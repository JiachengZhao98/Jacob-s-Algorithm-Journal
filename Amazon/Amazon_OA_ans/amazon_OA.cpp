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
#include "iostream"
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


// 133. Clone Graph
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
    vector<int> chooseWheels(vector<int>& wheels) {
        vector<int> res;
        for (int i = 0; i < wheels.size(); i++) {
            if (wheels[i] % 2) {
                res.push_back(0);
            }
            else {
                res.push_back(wheels[i] / 4 + 1);
            }
        }
        return res;
    }

    /*int main() {
    Solution sol;
    vector<int> wheels = {4,5,6};
    vector<int> ans = sol.chooseWheels(wheels);
    for (auto a : ans) {
        cout<<a<<" ";
    }
    cout<<endl;
    return 0;
    }*/

    vector<int> commonPrefix(string inputs){
        vector<int> res;
        int i = 0;
        int count = 0;
        for (int j = 0; j < inputs.size(); j++) {
            if (inputs[j] == inputs[0]) {
                int index = j;
                while (index < inputs.size() && inputs[index] == inputs[i]) {
                    count++;
                    index++;
                    i++;
                }
                res.push_back(count);
                i = 0;
                count = 0; continue;
            }
                res.push_back(0);
            }   
            return res;
        }
    /*int main() {
    vector<int> res;
    string inputs = "abcabcd";
    res = commonPrefix(inputs);
    for(auto a : res) {
        cout<<a<<" ";
    }
    cout<<endl;
    return 0;
    }*/

    int delivery(vector<int>& cargo) {
        map<int, int> myMap;
        int res = 0;
        for (int i = 0; i < cargo.size(); i++) {
            if (myMap.find(cargo[i]) == myMap.end()) {
                myMap.insert(pair<int, int>(cargo[i], 1));
            }
            else myMap.find(cargo[i])->second++;
        }
        for (auto iter = myMap.begin(); iter != myMap.end(); iter++) {
            if (iter->second == 1) {
                return -1;
            }
            else {
                if (iter->second % 3 == 0) {
                    res += iter->second / 3;
                }
                else {
                    res += (iter->second / 3 + 1);
                }
            }
        }
        return res;
    }
    /*int main() {
    Sloution sol;
    vector<int> cargo = {7,7,7,7,7,7,7};
    int ans = sol.delivery(cargo);
    cout<<ans<<endl;
    return 0;
    }*/

    int isOdd(int num) {
        return num % 2;
    }
    int Distinct_subarrays_with_at_most_k_odd_elements(vector<int>& nums, int k) {
        if (k == 0) {
            return 0;
        }
        unordered_set<string> mySet;
        for (int i = 0; i < nums.size(); i++) {
            int count = 0;
            string subarray;
            for (int j = i; j < nums.size(); j++) {
                if (isOdd(nums[j])) {
                    count++;
                    if (count > k) {
                        break;
                    }
                }
                subarray += char(nums[j]) + ",";
                mySet.insert(subarray);
            }
        }
        return mySet.size();
    }
    /*int main () {
    Solution sol;
    vector<int> nums = {3,2,3,2};
    int res = sol.Distinct_subarrays_with_at_most_k_odd_elements(nums, 1);
    cout<<res<<endl;
    return 0;
}*/

    
    long findEarliestMonth(vector<int>& stock) {
        long leftSum = 0, rightSum = 0, res = LONG_MAX;
        int index;
        for (auto a : stock) {
            rightSum += a;
        }
        for (int i = 0; i < stock.size() - 1; i++) {
            leftSum += stock[i];
            rightSum -= stock[i];
            long temp = abs((long)(leftSum / (i + 1) - rightSum / (stock.size() - i - 1)));
            if (res >= temp) {
                res = temp;
                index = i;
            }
        }
        return (index + 1);
    }
    /*int main() {
    solution sol;
    vector<int> stock = {1,4,4,5,4,4,1};
    int res = sol.findEarliestMonth(stock);
    cout<<res<<endl;
    return 0;
    }*/

    int triangularSum(vector<int>& nums) {
        if (nums.size() == 1) {
            return nums[0];
        }
        vector<int> ans;
        for(int i = 0; i < nums.size() - 1; i++) {
            int v = nums[i] + nums[i+1];
            if (v > 9) {
                v %= 10;
            }
            ans.push_back(v);
        }
        return triangularSum(ans);
    }

    int maximumElementAfterDecrementingAndRearranging(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        if (arr[0] > 1) {
            return arr.size();
        }
        for (int i = 0; i < (arr.size() - 1); i++) {
            if ((arr[i + 1] - arr[i]) > 1) {
                arr[i + 1] = arr[i] + 1;
            }
        }
        return arr[arr.size() - 1];
    }



    int maxGrey(vector<vector<int>>& grey) {
        vector<int> col(grey[0].size(), 0);
        vector<int> row(grey.size(), 0);
        int max = INT_MIN;
        for (int i = 0; i < grey.size(); i++) {
            for (int j = 0; j < grey[0].size(); j++) {
                row[i] += grey[i][j] == 1 ? 1 : -1;
            }
        }
        for (int j = 0; j < grey[0].size(); j++) {
            for (int i = 0; i < grey.size(); i++) {
                col[j] += grey[i][j] == 1 ? 1 : -1;
            }
        }
        for (int i = 0; i < grey.size(); i++) {
            for(int j = 0; j < grey[0].size(); j++) {
                int temp = grey[i][j] == 1 ? (row[i] + col[j] - 1) : (row[i] + col[j] + 1);
                max = temp > max ? temp : max;
            }
        }
        return max;
    }
    /*int main() {
    Solution sol;
    vector<vector<int>> grey = {{1,0,0}, {1,0,0}, {1,1,1}};
    int res = sol.maxGrey(grey);
    cout<<res<<endl;
    return 0;
    }*/



    /*
If current character is '0', it can be the middle of "101" slection
		add how many selections can be there with this '0' as the middle element
		(this is, numbers of ones on the left * number of ones on the right)
If current character is '1', it can be the middle of "010" selection
		add how many selections can be there with this '1' as the middle element
		(this is, numbers of zeros on the left * number of zeros on the right)

*/
    long long howMany101Or010InAString(string book) {
        long long left0 = 0, left1 = 0, count0 = 0, count1 = 0, ans = 0;
        for(char ch : book) {
            if (ch == '0') count0++;
            if (ch == '1') count1++;
        }
        for(int i=0; i<book.length(); i++) {
            if(book[i] == '1')    ans += left0 * (count0 - left0);
            if(book[i] == '0')    ans += left1 * (count1 - left1);
            left0 += (book[i] == '0');
            left1 += (book[i] == '1');
        }
        return ans;
    }
    /*int main() {
    Solution sol;
    int res = sol.howMany101Or010InAString("01001");
    cout<<res<<endl;
    return 0;
    }*/




    int keypadClickCount_1 (string text) {
        vector<char> letter(26, 0);
        vector<int> freq(26, 0);
        char input = 'a';
        for (int i = 0; i < 26; i++) {
            letter[i] = input;
            input++;
        }
        for (int i = 0; i < text.length(); i++) {
            for (int j = 0; j < 26; j++) {
                if (text[i] == letter[j]) {
                    freq[j]++;
                }
            }
        }
        sort(freq.begin(), freq.end());
        reverse(freq.begin(), freq.end());
        int count = 0;
        for (int i = 0; i < 26; i++) {
            count += freq[i] * ((i / 9) + 1);
        }
        return count;
    }
    
    int keypadClickCount_2 (string text) {
        map<char, int> letterCount;
        vector<int> count;
        int res = 0;
        for (int i = 0; i < text.size(); i++) {
            if (letterCount.find(text[i]) == letterCount.end()) {
                letterCount.insert(pair<char, int>(text[i], 1));
            }
            else {
                letterCount.find(text[i])->second++;
            }
        }
        int i = 0;
        for (auto iter = letterCount.begin(); iter != letterCount.end(); iter++) {
            count.push_back(iter->second);
        }
        sort(count.begin(), count.end());
        reverse(count.begin(), count.end());
        for (int i = 0; i < count.size(); i++) {
            res += count[i] * (i / 9 + 1);
        }
        return res;
    }

    /*int main () {
    string text = "abacadefghibj";
    Solution sol;
    int count = sol.keypadClickCount_2(text);
    cout<<count<<endl;
    return 0;
    }*/



    unordered_map<string, string> user;
    unordered_map<string, string> login;

    void Register(string username, string password) {
        if (user.find(username) != user.end()) {
            cout<<"Username already exists";
        }
        else {
            user.insert(pair<string, string>(username, password));
            cout<<"Registered Succcessfully";
        }
    }

    void Login(string username, string password) {
        auto iter = user.find(username);
        if (iter == user.end() || iter->second != password) {    // users have not registered, or users enter their username incorrectly
                                                                 // or users enter their password incorrectly
            cout<<"Login Unsuccessful";
            return;
        }
        else {
            if (login.find(iter->first) != login.end()) {        // users have already logged in
                cout<<"Login Unsuccessful";
            }
            else {
                login.insert(pair<string, string>(username, password));
                cout<<"Logged In Successfully";
            }
        }
    }

    void Logout(string username) {
        auto iter = login.find(username);
        if (iter == login.end()) {
            cout<<"Logout Unsuccessful";
        }
        else {
            login.erase(iter);
            cout<<"Logged Out Successfully";
        }
    }


// int main() {
//     Solution sol;
//     sol.Register("Jacobzhao98", "zjczjc666");
//     cout<<endl;
//     sol.Logout("Jacobzhao98");
//     cout<<endl;
//     sol.Login("Jacobzhao98", "zjczjc666");
//     cout<<endl;
//     sol.Login("Jacobzhao98", "zjczjc666");
//     cout<<endl;
// }




    vector<int> longestOnes(vector<int>& nums, int k) {
        vector<int> pos;
        vector<int> pos_res;
        queue<int> subArray;
        int count = 0;
        int res = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == 0) {
                count++;
                pos.push_back(i);
            }
            subArray.push(nums[i]); // push elements of nums into queue
            if (count > k) {
                while (subArray.front() == 1) {
                    subArray.pop(); // the number of zeros is greater than K, so we need to pop out one zero. It is possible that the first a few elements of                       queue are ones, in this case we need to pop out the first a few ones.
                }
                subArray.pop(); // pop out one 0
                pos.erase(pos.begin());
                count--;  // the number of zeros minus one
            }
            if(res < subArray.size()) {
                res = subArray.size(); // record the biggest length of queue
                pos_res.clear();
                for (auto iter = pos.begin(); iter != pos.end(); ++iter) {
                    pos_res.push_back(*iter);
                }
            }
        }
        return pos_res;
    }

// int main() {
//     Solution sol;
//     vector<int> nums = {0, 0, 0, 1};
//     int k = 4;
//     vector<int> res;
//     res = sol.longestOnes(nums, k);
//     for (auto a : res) {
//         cout<<a<<" ";
//     }
//     cout<<endl;
//     return 0;
// }





    int amazon_maxAZAfterInserting(string s) {
        int countA = 0, countZ = 0, res = 0;
        vector<int> record;
        for (int i = s.size() - 1; i >= 0; i--) {
            if (s[i] == 'Z') countZ++;
            if (s[i] == 'A') {
                countA++;
                res += countZ;
            }
        } 
        return (res + max(countA, countZ));
    }


// int main() {
//     Solution sol;
//     string s = "Z";
//     int ans = sol.amazon_maxAZAfterInserting(s);
//     cout<<ans<<endl;
//     return 0;
// }



    vector<int> maxConsecutiveNumber(vector<int>& nums, int k) {
        vector<int> res;
        if (nums.size() == 0 || k == 0) {
            return res;
        }
        int maxLength = 0;
        queue<int> recordSubarrayLength;
        set<int> recordIndex;
        int j = 0;
        int count = 0;
        for (; j < nums.size(); j++) {
                recordSubarrayLength.push(nums[j]);
                if (nums[j] == 0) {
                    count++;
                    recordIndex.insert(j);
                }
                if (count > k) {
                    while (recordSubarrayLength.front() == 1) {
                    recordSubarrayLength.pop();
                    }
                    recordSubarrayLength.pop();
                    recordIndex.erase(recordIndex.begin());
                    count--;
                }
                if (maxLength < recordSubarrayLength.size()) {
                res.clear();
                for (auto iter = recordIndex.begin(); iter != recordIndex.end(); iter++) {
                    res.push_back(*iter);
                }
                maxLength = recordSubarrayLength.size();
                }
            }
        return res;
    }

// int main() {
//     Solution sol;
//     vector<int> nums = {0,0,0,1};
//     vector<int> res;
//     res = sol.maxConsecutiveNumber(nums, 4);
//     for (auto a : res) {
//         cout<<a<<" ";
//     }
//     cout<<endl;
//     return 0;
// }



    int maxSubarrrayWithK(vector<int>& nums, int k) {
        int res = INT_MIN;
        for (int i = 0; i < nums.size() - k; i++) {
            int j = i;
            int temp = 0;
            set<int> mySet;
            while (j < i + k) {
                mySet.insert(nums[j]);
                temp += nums[j];
                j++;
            }
            if (mySet.size() == k) {
                res = res < temp ? temp : res;
            }
        }
        return res;
    }

    int maxSubarrrayWithK_2(vector<int>& nums, int k) {
        unordered_map<int, int> myMap;
        int res = INT_MIN, sum = 0;
        for (int i = 0; i < k; i++) {
            sum += nums[i];
            if (myMap.find(nums[i]) == myMap.end()) {
                myMap.insert(pair<int, int>(nums[i], 1));
            }
            else {
                myMap.find(nums[i])->second++;
            }
        }
        if (myMap.size() == k) {
            res = sum;
        }
        for (int i = k; i < nums.size(); i++) {
            sum = sum + nums[i] - nums[i - k];
            if (myMap.find(nums[i]) == myMap.end()) {
                myMap.insert(pair<int, int>(nums[i], 1));
            }
            else if (myMap.find(nums[i]) != myMap.end()) {
                myMap.find(nums[i])->second++;
            }
            myMap.find(nums[i - k])->second--;
            if (myMap.find(nums[i - k])->second == 0) {
                myMap.erase(myMap.find(nums[i - k]));
            }
            if (myMap.size() == k) {
                res = res < sum ? sum : res;
            }
        }
        return res;
    }

// int main() {
//     Solution_2 sol;
//     vector<int> nums = {1,2,7,7,4,3,6};
//     int ans = sol.maxSubarrrayWithK(nums, 3);
//     cout<<ans<<endl;
//     return 0;
// }







};

