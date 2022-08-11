#include "vector"
#include "stack"
using namespace std;

class Solution {
public:
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
};
