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

    int merge(vector<vector<int>>& intervals) {
        int size = intervals.size();
        vector<vector<int>> res;
        sort(intervals.begin(), intervals.end());
        for (int i = 0; i < intervals.size(); i++) {
            if (i + 1 < intervals.size() && intervals[i + 1][0] <= intervals[i][1]) {
                intervals[i + 1][0] = min(intervals[i + 1][0], intervals[i][0]);
                intervals[i + 1][1] = max(intervals[i + 1][1], intervals[i][1]);
            }
            else
                res.push_back({intervals[i][0], intervals[i][1]});
            }
        return size - res.size();
        }


    int minAfterMinusK(vector<int>& nums, int k) {
        int sum = 0;
        int partSum = 0;
        for (int i = 0; i < k; i++) {
            partSum += nums[i];
        }
        int Max = partSum;
        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];
            if (i + k < nums.size()) {
                partSum = partSum + nums[i + k] - nums[i];
                Max = max(Max, partSum);
            }
        }
        return (sum - Max);
    }

// int main() {
//     Solution sol;
//     vector<int> nums = {7,3,6,1};
//     int res = sol.minAfterMinusK(nums, 2);
//     cout<<res<<endl;
//     return 0;
// }


    long int Min(long x, long y) {
        if (x < y) return x;
        else return y;
    }
    int minDiffBetweenSubarray(vector<int>& nums) {
        if (nums.size() == 1) {
            return 0;
        }
        long tempSum = 0;
        long count;
        long sum = 0;
        long Minimum = INT_MAX;
        for (auto a : nums) {
            tempSum += a;
        }
        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];
            tempSum -= nums[i];
            int temp;
            if (i < nums.size() - 1) {
                temp = sum / (i + 1) - tempSum / (nums.size() - i - 1);
            }
            else temp = sum / (i + 1);
            temp = abs(temp);
            long tempMin = Min(Minimum, temp);
            if (tempMin < Minimum) {
                Minimum = tempMin;
                count = i + 1;
            }
        }
        return count - 1;
    }

// int main() {
//     Solution sol;
//     vector<int> stock = {1,3,2,3};
//     int res = sol.minDiffBetweenSubarray(stock);
//     cout<<res<<endl;
//     return 0;
// }


    long long minimumHealth(vector<int>& damage, int armor) {
        int Max = INT_MIN;
        long sum = 0;
        for (auto a : damage) {
            sum += a;                    // sum all the damage
            Max = a > Max ? a : Max;     // find the largest value in damage
        }
        if (armor >= Max) {
            return (sum + 1 - Max);      // use armor to defend
        }
        else return (sum + 1 - armor);   // add more health if the armor can NOT defend the largest damage
    }



    int minMove(vector<int>& nums) {
        int count1 = 0, dis = 0;
        for (auto a : nums) {
            if (a == 1) count1++;
            else dis += count1;
        }
        int count0 = nums.size() - count1;
        return min(dis, count0 * count1 - dis);
    }


// int main() {
//     vector<int> nums = {0, 1 ,0 , 1};
//     Solution sol;
//     int ans = sol.minMove(nums);
//     cout<<ans<<endl;
//     return 0;
// }


    int minSum(vector<int>& nums, int k) {
        int sumAll = 0;
        int sum = 0;
        int count = 0;
        int res = INT_MIN;
        queue<int> q;

        for(auto a : nums) {
            count++;
            q.push(a);
            sum += a;
            sumAll += a; // calculate the sum of all elements in nums
            if (count > k) {
                sum -= q.front(); // remove the first element of queue
                q.pop();          // move the slide window to next position
                count--;
            }
            res = sum > res ? sum : res;  // memorize the biggest sum of elements in the slide window
        }
        return sumAll - res;
    }

// int main() {
//     Solution sol;
//     vector<int> nums = {7,3,6,1};
//     int k = 1;
//     int res;
//     res = sol.minSum(nums, k);
//     cout<<res<<endl;
//     return 0;
// }


    vector<int> moveFromMoveTo(vector<int> locations, vector<int> moveFrom, vector<int> moveTo) {
        set<int> temp;
        vector<int> res;
        for (auto loc : locations) {
            temp.insert(loc);
        }
        for (int i = 0; i < moveFrom.size(); i++) {
            auto iter = temp.find(moveFrom[i]);
            temp.erase(iter);
            temp.insert(moveTo[i]);
        }
        for (auto iter = temp.begin(); iter != temp.end(); iter++) {
            res.push_back(*iter);
        }
        return res;
    }

// int main() {
//     vector<int> res;
//     Solution sol;
//     std::vector<int> locations = {1,7,6,8};
//     vector<int> moveFrom = {1,7,2};
//     vector<int> moveTo = {2,9,5};
//     res = sol.moveFromMoveTo(locations, moveFrom, moveTo);
//     for (auto a : res) {
//         cout<<a<<" ";
//     }
//     cout<<endl;
//     return 0;
// }




    int movieReward(vector<int>& awards, int k) {
        int i = 0, j = 0, count = 1;
        sort(awards.begin(), awards.end());
        while (j < awards.size()) {
            if (awards[j] - awards[i] <= k){
                j++;
                continue;
            }
            else {
                i = j;
                j++;
                count++;
            }
        }
        return count;
    }


// int main() {
//     Solution sol;
//     vector<int> awards = {1,5,4,6,8,9,2};
//     int res = sol.movieReward(awards, 3);
//     cout<<res<<endl;
//     return 0;
// }

// amazon password
// https://www.1point3acres.com/bbs/thread-844628-1-1.html



// amazon_router
int router(vector<int> buildingCount, vector<int> routerLoc, vector<int> routerRange) {
        int count = 0;
        for (int i = 0; i < routerLoc.size(); i++) {
            int begin = routerLoc[i] - 1 - routerRange[i];
            if (begin < 0) begin = 0;
            int end = routerLoc[i] - 1 + routerRange[i];
            if (end >= buildingCount.size()) end = buildingCount.size() - 1;
            while (begin <= end) {
                buildingCount[begin]--;
                begin++;
            }
        }
        for (auto a : buildingCount) {
            if (a <= 0) {
                count++;
            }
        }
        return count;
    }

//     int main() {
//     vector<int> bldgCount = {1,2,1,2,2};
//     vector<int> routerLoc = {3,1};
//     vector<int> routerRange = {1,2};
//     Solution sol;
//     int ans = sol.router(bldgCount, routerLoc, routerRange);
//     cout<<ans<<endl;
// }


// amazon_sContainT

    int SinT(string S, string T) {
        unordered_map<char, int> strmap_t;
        unordered_map<char, int> strmap_s;
        for (int i = 0; i < T.size(); i++) {
            if (strmap_t.find(T[i]) == strmap_t.end()) {
                strmap_t.insert(pair<char, int>(T[i], 1));
            }
            else strmap_t.find(T[i])->second++;
        }
        for (int i = 0; i < S.size(); i++) {
            if (strmap_s.find(S[i]) == strmap_s.end()) {
                strmap_s.insert(pair<char, int>(T[i], 1));
            }
            else strmap_s.find(S[i])->second++;
        }
        int res = INT_MAX;
        for (int i = 0; i < T.size(); i++) {
            auto iter = strmap_t.find(T[i]);
            auto iter_2 = strmap_s.find(T[i]);
            int temp = iter_2->second / iter->second;
            res = temp < res ? temp : res;
        }
        return res;
    }

//     int main() {
//     string S = "abababab";
//     string T = "bba";
//     Solution sol;
//     int res = sol.SinT(S, T);
//     cout<<res<<endl;
//     return 0;
// }



    // amazon_searchWord
    int searchWordResultword(string searchWord, string resultWord) {
        int i = 0, j = 0;
        int remain = -1;
        int count = 0;
        for (; j < searchWord.size(); j++) {
            if (searchWord[j] == resultWord[i]) {
                i++;
                count++;
            }
        }
        remain = resultWord.size() - count;
        return remain;
    }

    // int main() {
//     Solution sol;
//     string search = "aghgmhghghgahzghghghghghgh";
//     string result = "amazon";
//     int res = -1;
//     res = sol.searchWordResultword(search, result);
//     cout<<res<<endl;
//     return 0;
// }


    // amazon_server
    vector<int> moveServer (vector<int>& locations, vector<int>& moveFrom, vector<int>& moveTo) {
        set<int> newLocations;
        set<int>::iterator iter;
        vector<int> newlocations;
        int j = 0;
        for (int i = 0; i < locations.size(); i++) {
            newLocations.insert(locations[i]);
        }
        for (int i = 0; i < moveFrom.size(); i++) {
            newLocations.erase(moveFrom[i]);
            newLocations.insert(moveTo[i]);
        }
        for(iter = newLocations.begin(); iter != newLocations.end(); ++iter) {
            newlocations.push_back(*iter);
        }
        return newlocations;
    }

// int main() {
//     vector<int> locations = {1,7,6,8};
//     vector<int> moveFrom = {1,7,2};
//     vector<int> moveTo = {2,9,5};
//     Solution sol;
//     vector<int> res = sol.moveServer(locations, moveFrom, moveTo);
//     for (auto a : res) {
//         cout<<a<<" ";
//     }
//     return 0;
// }

    // amazon_serverPower

    int findMaximumSustainableClusterSize(vector<int> processingPower, vector<int> bootingPower, long powerMax) {
        int len = processingPower.size();
        if(len == 0 || bootingPower.size() == 0) return 0;
        int ans = 0;
        for(int i=0;i<len;i++){
            int count = 1, maxCount=1, sum =0, mul;
            int Max = INT_MIN;
            for(int j=i;j<len;j++){
                sum += processingPower[j];
                mul = sum * count;
                count++;

                Max = max(Max,bootingPower[j]);
                long tempPower = mul + Max;
                if(tempPower <= powerMax){
                   // System.out.println(tempPower);
                    ans = max(maxCount, ans);
                    maxCount++;
                }else break;
            }
        }
        return ans;
}

// int main() {
//     vector<int> process = {3,6,1,3,4};
//     vector<int> boot = {2,1,3,4,5};
//     int ans  = findMaximumSustainableClusterSize(process, boot, 27);
//     cout<<ans<<endl;
//     return 0;
// }


    // amazon_shortestPath

    int res = 0;
    void dfs(vector<vector<int>>& lot, int i, int j, vector<vector<bool>>& visited, int step) {
        int m = lot.size(), n = lot[0].size();
        if (i < 0 || j < 0 || i >= m || j >= n) {
            return ;
        }
        if (lot[i][j] == 0) {
            return;
        }
        if (visited[i][j]) {
            return ;
        }
        visited[i][j] = true;
        step++;
        if (lot[i][j] == 9) {
            res = step;
            return;
        }
        dfs(lot, i - 1, j, visited, step);
        dfs(lot, i + 1, j, visited, step);
        dfs(lot, i, j - 1, visited, step);
        dfs(lot, i, j + 1, visited, step);
    }

    int shortestPath(vector<vector<int>>& lot) {
        vector<vector<bool>> visited(lot.size(), vector<bool>(lot[0].size(), false));
        dfs(lot, 0, 0, visited, 0);
        return res - 1;
    }

// int main() {
//     Solution sol;
//     int ans;
//     vector<vector<int>> lot {{1,0,0}, {1,0,0}, {1,9,1}};
//     ans = sol.shortestPath(lot);
//     cout<<ans<<endl;
// }



    // amazon_slidingWindow

    int slidingWindow(vector<int>& memory, int k) {
        int maxSum = 0, allSum = 0;
        for (int i = 0; i < k; i++) {
            maxSum += memory[i];
            allSum += memory[i];
        }
        int max = maxSum;
        for (int i = k; i < memory.size(); i++) {
            allSum += memory[i];
            maxSum = maxSum - memory[i - k] + memory[i];
            max = max < maxSum ? maxSum : max;
        }
        return (allSum - max);
    }

// int main() {
//     Solution sol;
//     vector<int> memory = {1,4,4,6,9,4};
//     int ans = sol.slidingWindow(memory, 2);
//     cout<<ans<<endl;
//     return 0;
// }


    // amazon_slidingWindowPackages
    int slidingWindowPackage(vector<int>& packages) {
        int res = packages[packages.size() - 1];
        for (int i = packages.size() - 1; i >= 1; i--) {
            if (packages[i] > packages[i - 1]) {
                packages[i - 1] = packages[i] + packages[i - 1];
            }
            res = res < packages[i - 1] ? packages[i - 1] : res;
        }
        return res;
    }

// int main() {
//     Solution sol;
//     vector<int> packages = {2,9,10,3,7};
//     int ans = sol.slidingWindowPackage(packages);
//     cout<<ans<<endl;
//     return 0;
// }



    // amazon_stockPrice
    int stockPrice(vector<int>& month, int k){
        int sum = 0;
        int res = 0;
        set<int>::iterator iter;
        set<int> rem;
        if (month.size() < k) {
            return -1;
        }
        for (int i = 0; i <= month.size() - k; i++) {
            for (int j = i; j < i + k; j++) {
                rem.insert(month[j]);
            }
            if (rem.size() == k) {
                for ( iter = rem.begin(); iter != rem.end(); ++iter) {
                    sum += *iter;
                }
                if (sum > res) {
                    res = sum;
                }
            }
            rem.clear();
            sum = 0;
        }
        if (res == 0) {
            return -1;
        } else return res;
    }


// int main() {
//     Solution sol;
//     int k = 4;
//     vector<int> month = {1,2,7,7,4,3,6};
//     int sum = sol.stockPrice(month, k);
//     cout<<sum<<endl;

//     return 0;
// }


    // amazon_sumOfPower
    int totalStrength(vector<int>& strength) {
		int n = strength.size(), mod = 1e9 + 7;

		vector<long long> rightPref(n), rightPrefSum(n);
		vector<long long> leftPref(n), leftPrefSum(n);

		rightPref[0] = strength[0];
		rightPrefSum[0] = strength[0];
		for(auto i = 1; i < n; i++){
			rightPref[i] = rightPref[i - 1] + strength[i];
			rightPrefSum[i] = rightPrefSum[i - 1] + rightPref[i];
		}

		leftPref[n - 1] = strength[n - 1];
		leftPrefSum[n - 1] = strength[n - 1];
		for(auto i = n - 2; i >= 0; i--){
			leftPref[i] = leftPref[i + 1] + strength[i];
			leftPrefSum[i] = leftPrefSum[i + 1] + leftPref[i];
		}

		stack<int> st;
		vector<int> rightIndex(n); //right lowest index the current
		st.push(n);
		for(auto i = n - 1; i >= 0; i--){
			while(st.top() != n && strength[st.top()] >= strength[i]) st.pop();

			rightIndex[i] = st.top() - 1;
			st.push(i);
		}

		stack<int> lst;
		lst.push(-1);
		long long totalStrength = 0;

		for(auto i = 0; i < n; i++){
			while(lst.size() > 1 && strength[lst.top()] > strength[i]) lst.pop();

			int left = lst.top() + 1;
			lst.push(i);
			int right = rightIndex[i];
			int lsize = i - left + 1;
			int rsize = right - i + 1;

			long long rightSum = rightPrefSum[right] - (i > 0 ? rightPrefSum[i - 1] + rightPref[i - 1] * rsize : 0) % mod;
			long long leftSum = leftPrefSum[left] - (i < n - 1 ? leftPrefSum[i + 1] + leftPref[i + 1] * lsize : 0) % mod;

			long long totalSum = (rightSum % mod * lsize) % mod + (leftSum % mod * rsize) % mod - ((long long)strength[i] * lsize * rsize) % mod;

			totalStrength = (totalStrength + (totalSum % mod * strength[i]) % mod) % mod;
		}

		return totalStrength;
	}


    // amazon_sumOfSubarrayRanges

    long long subArrayRanges(vector<int>& nums) {
        stack<int> st;
        int n = nums.size();
        long long ans = 0;
        nums.push_back(INT_MAX);
        for(int i = 0; i <= n; i++){
            while(!st.empty() && nums[i] > nums[st.top()]) {
                int x = st.top();
                st.pop();
                int res = st.empty()? -1 : st.top();
                ans += (long long)nums[x]*(i-x)*(x-res);
            }
            st.push(i);
        }
        st.pop();
        nums[n]=INT_MIN;
        for(int i=0;i<=n;i++){
            while(!st.empty() && nums[i]<nums[st.top()]){
                int x=st.top();
                st.pop();
                int res=st.empty()?-1:st.top();
                ans-=(long long)nums[x]*(i-x)*(x-res);
            }
            st.push(i);
        }
        return ans;
    }


    // reference https://leetcode.com/problems/sum-of-subarray-ranges/discuss/1624222/JavaC++Python-O(n)-solution-detailed-explanation
    long long subArrayRanges_2(vector<int>& A) {
        long res = 0, n = A.size(), j, k;
        stack<int> s;
        for (int i = 0; i <= n; ++i) {
            while (!s.empty() && A[s.top()] > (i == n ? -2e9 : A[i])) {
                j = s.top(), s.pop();
                k = s.empty() ? -1 : s.top();
                res -= (long)A[j] * (i - j) * (j - k);
            }
            s.push(i);
        }
        s = stack<int>();
        for (int i = 0; i <= n; ++i) {
            while (!s.empty() && A[s.top()] < (i == n ? 2e9 : A[i])) {
                j = s.top(), s.pop();
                k = s.empty() ? -1 : s.top();
                res += (long)A[j] * (i - j) * (j - k);
            }
            s.push(i);
        }
        return res;
    }

    long long subArrayRanges_3(vector<int>& nums) {

        long sum=0;

        for(int l=0; l<nums.size(); l++){
            int minnum = nums[l];
            int maxnum = nums[l];
            for(int r=l; r<nums.size(); r++){
                // key: min and max can be reuse!
                maxnum = max(maxnum, nums[r]);
                minnum = min(minnum, nums[r]);
                sum += maxnum - minnum;
            }
        }
        return sum;
    }


    // amazon_temperature

    int temperature(vector<int> weather) {
        int i = 0;
        int sumftb = 0, sumbtf = 0;
        int res = INT_MIN;
        for (; i < weather.size(); i++) {
            sumftb += weather[i];
            sumbtf += weather[weather.size() - 1 - i];
            res = Max(sumbtf, sumftb, res);
        }
        return res;
    }

    int Max(int a, int b, int c){
        int temp = max(a, b);
        temp = max(temp, c);
        return temp;
    }

// int main() {
//     vector<int> temp = {-1,2,3};
//     Solution sol;
//     int res = sol.temperature(temp);
//     cout<<res<<endl;
//     return 0;
// }


    // amazon_The_kth_Factor_of_n

int kthFactor(int n, int k) {
        set<int> factors;
         for (int i = 1; i <= sqrt(n); i++) {
            if (n % i == 0) {
                factors.insert(i);
                factors.insert(n / i);
            }
         }
         if (factors.size() < k) return -1;
         else {
            auto iter = factors.begin();
            advance(iter, k);
            return *iter;
         }
    }

    // another thought
    int kthFactor_2(int n, int k) {

        for(int i=1;i<=n;i++){
            if(n%i==0)
                k--;
            if(k==0)
                return i;

        }
        return -1;
    }

};

