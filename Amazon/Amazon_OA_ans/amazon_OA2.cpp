#include "iostream"
#include "vector"
#include "set"
#include "unordered_set"
#include "map"
#include "unordered_map"
#include "string"

using namespace std;

// problem url: https://leetcode.com/discuss/interview-question/5043451/Amazon-OA/

vector<int> findServerVulnerability(int k, int m, vector<int>& vulnerability) {
    vector<int> res;
    multiset<int> myset;
    for (int i = 0; i < m; i++) {
        myset.insert(vulnerability[i]);
    }
    res.push_back(*next(myset.begin(), k - 1));
    for (int i = m; i < vulnerability.size(); i++) {
        myset.insert(vulnerability[i]);
        myset.erase(myset.find(vulnerability[i - m]));
        res.push_back(*next(myset.begin(), k - 1));
    }
    return res;
}

// problem url: https://leetcode.com/discuss/interview-question/4754212/amazon

vector<int> tasksInQueus(vector<int>& waitTime) {
    int n = waitTime.size();
    int time = 0, idx = 0;
    vector<int> res;
    unordered_map<int, vector<int>> mp;
    for (int i = 0; i < n; i++) {
        mp[waitTime[i]].push_back(i);
    }
    while (n > 0) {
        if (waitTime[idx] == -1) {
            idx++;
            continue;
        }
        res.push_back(n);
        n--;
        idx++;
        time++;
        if (mp.find(time) != mp.end()) {
            vector<int> cur = mp[time];
            int count = 0;
            for (auto a : cur) {
                if (a > time) {
                    count++;
                    waitTime[a] = -1;
                }
            }
            n -= count;
        }
    }
    res.push_back(0);
    return res;
}


// 2024 ng oa


/*
AWS stores grayscale images as an array of white and black pixels.
The image is stored as a binary string where a white pixel is represented by '1', and a black pixel is represented by '0'.
The reverse of the image is represented as the reverse of this binary representation.
For example, the reverse of "11010" is "01011". They want to store the reverse of each image as a backup.
In order to reproduce the reverse from the original,
the following operation can be performed any number of times:
remove any character from the string and append it to the end of the string, i.e., choose any pixel and shift it to the end of the string.
Given the binary representation of pixels denoted by image, find the minimum number of operations needed to produce its reverse.
Function Description:
Complete the function findMinimumOperations in the editor. findMinimumOperations has the following parameter:
1. String image : a binary string that represents an image
Returns
int : the minimum number of operations required to produce a reverse, i.e., to reverse the string.
*/


int findMinimumOperations(string image) {
    int n = image.size();
    string reverse_image = image;
    reverse(reverse_image.begin(), reverse_image.end());

    int ops = 0;
    int j = 0;

    // Iterate through each character in the reverse_image
    for (int i = 0; i < n; ++i) {
        // If we find the character in image that matches the current character in reverse_image
        while (j < n && image[j] != reverse_image[i]) {
            ++j;
        }
        if (j < n) {
            ++j;
        } else {
            ++ops;
        }
    }

    return ops;
}

/*
// Given an array, arr, of length k containing strings consisting of lowercase English letters only and a string regex of length n,
for each of them find whether the given regex matches with the string or not and report an array of strings "YES" or "NO" respectively.
*/

/*
approach: use the built-in library "regex"
std::regex pattern("regex_pattern")
method std::regex_match(test_str, pattern);
*/

/*
if TLE in cpp library, try python using `re`:

example code:

    import re

    if re.match("ab(e.r)*e", "abefretre"):
        print("YES")
    else:
        print("NO")

*/



int main() {
    vector<int> temp = {2,2,3,1};
    vector<int> vec = tasksInQueus(temp);
    for (auto a : vec) {
        cout<<a<<" ";
    }
    cout<<endl;
    return 0;
}
