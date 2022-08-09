#include "set"
#include "iostream"
#include "algorithm"
#include "vector"
#include "stack"
using namespace std;




class Solution {
public:
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
};

// reference https://leetcode.com/problems/sum-of-subarray-ranges/discuss/1624222/JavaC++Python-O(n)-solution-detailed-explanation 
class Solution_2{
public:
    long long subArrayRanges(vector<int>& A) {
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
};