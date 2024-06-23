#include <iostream>
#include <vector>
#include <utility>
#include <tuple>
#include "map"
#include "cmath"
#include "unordered_map"
#include "unordered_set"
#include "map"
#include "set"
#include "mutex"
#include "condition_variable"
#include "stack"
#include "queue"

using namespace std;

// Q1
// 给一部分含有线程锁的c++函数，请你看出这部分函数是有内存泄露、造成死锁、是否支持多线程访问、内存占用、内存没对齐、是否处理有效输入、是否造成内存越界、是否正确并且安全



// Q2
// 在代码中定义了一颗自定义的树，给出制定的起点和终点，求从起点到终点会遍历的所有节点。


// Q3
// no info

// Q4
// 使用七个硬盘下载数据，硬盘的读写数独在装载量不同的情况下各不相同。现在需要你求，写满百分之八十五的硬盘，所需要的时间。

// Q5
// 一个页面内需要呈现4款数据，包括：页面状态，页面索引、访问模式和进程ID。这4款数据又有各自的取值范围，比如说3，100，45000。现在求装载这4个状态所需要的最小字节数

// To find the minimum number of bytes required to represent the four types of data—page status, page index, access mode, and process ID—we first need to understand the range of values each type of data can hold. This will help us determine how many bits are needed to represent each type. From the information you provided, we have the following maximum values for each type:

// 1. Page status: Assuming 3 distinct states, needing at least \(\log_2(3) \approx 2\) bits.
// 2. Page index: With a maximum value of 100, requiring \(\log_2(101) \approx 7\) bits.
// 3. Access mode: Assuming it also has 3 distinct states like page status, needing at least \(\log_2(3) \approx 2\) bits.
// 4. Process ID: Maximum value is 45000, requiring \(\log_2(45001) \approx 16\) bits.

// Let's summarize:
// - Page status: 2 bits
// - Page index: 7 bits
// - Access mode: 2 bits
// - Process ID: 16 bits

// Adding these together gives us a total of \(2 + 7 + 2 + 16 = 27\) bits.

// Since 1 byte consists of 8 bits, we can calculate the number of bytes required by dividing the total number of bits by 8 and then rounding up to the nearest whole number if necessary:

// \[
// \frac{27 \text{ bits}}{8 \text{ bits/byte}} \approx 3.375 \text{ bytes}
// \]

// Thus, you would need 4 bytes to represent all four data types together, as you cannot use a fraction of a byte in practical scenarios.


// Q6
// use stack to stimulate thread manager
class threadManager {
private:
    stack<string> taskStack; // Stack to manage tasks

public:
    void startTask(const std::string& taskName) {
        taskStack.push(taskName);
        std::cout << "Started task: " << taskName << std::endl;
    }

    // Complete the current task
    void completeTask() {
        if (!taskStack.empty()) {
            std::cout << "Completed task: " << taskStack.top() << std::endl;
            taskStack.pop();
        } else {
            std::cout << "No tasks to complete." << std::endl;
        }
    }

    // Get the current running task
    std::string currentTask() {
        if (!taskStack.empty()) {
            return taskStack.top();
        } else {
            return "No tasks are running.";
        }
    }

    // Check if there are any tasks running
    bool hasTasks() {
        return !taskStack.empty();
    }

};

// Q7
// 编程：给出字符串，计算能构建的最大回文数。
// 解答：从中心出扩展两边是否是回文，然后用set求每个回文的个数
// possible answer, similar to leetcode 647 Palindromic Substrings

int numberOfPalindrome(string s) {
    string res;
    unordered_set<string> Set; // maybe choose `vector` in the question
    for (int i = 0; i < s.size(); i++) {
        int idx = i;
        string temp; temp += s[i];
        Set.insert(temp);
        if (idx < s.size() - 1 && s[idx] == s[idx + 1]) {
            int left = idx, right = idx + 1;
            string cur;
            while (left >= 0 && right < s.size() && s[left] == s[right]) {
                cur = s.substr(left, right + 1 - left);
                Set.insert(cur);
                left--;
                right++;
            }
        }
        if (idx >= 1 && idx < s.size() - 1 && s[idx - 1] == s[idx + 1]) {
            int left = idx - 1, right = idx + 1;
            string cur;
            while (left >= 0 && right < s.size() && s[left] == s[right]) {
                cur = s.substr(left, right + 1 - left);
                Set.insert(cur);
                left--;
                right++;
            }
        }
    }
    return Set.size();
}

// Q8
// 编程：阅读给出的二分搜索的代码，检查看他会不会有bug；如果有，返回一个conner case的输入。
// 解答：选一个test case，代入代码推一下变量就行
