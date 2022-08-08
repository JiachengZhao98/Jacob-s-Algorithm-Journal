#include "vector"
#include "string"
#include "iostream"
using namespace std;

/*
If current character is '0', it can be the middle of "101" slection
		add how many selections can be there with this '0' as the middle element
		(this is, numbers of ones on the left * number of ones on the right)
If current character is '1', it can be the middle of "010" selection
		add how many selections can be there with this '1' as the middle element
		(this is, numbers of zeros on the left * number of zeros on the right)

*/

class Solution {
public:
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
};

int main() {
    Solution sol;
    int res = sol.howMany101Or010InAString("01001");
    cout<<res<<endl;
    return 0;
}