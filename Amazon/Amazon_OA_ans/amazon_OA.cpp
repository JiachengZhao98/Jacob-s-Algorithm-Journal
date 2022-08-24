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

};

