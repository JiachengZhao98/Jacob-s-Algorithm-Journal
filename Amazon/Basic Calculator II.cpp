#include "string"
#include "stack"
#include "queue"
using namespace std;

class Solution {
public:
    string removeSpace(string s) {
        string newS;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] != ' ') {
                newS += s[i];
            }
        }
        return newS;
    }
    int calculate(string s1) {
        string s = removeSpace(s1);
        stack<int> currentNumSta;
        string strNum = "";
        int currentNum = INT_MIN;
        int PN = 1;
        int res = 0;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] != '+' && s[i] != '-' && s[i] != '*' && s[i] != '/' ) {
                strNum += s[i];
                currentNum = stoi(strNum);
                if (i == s.size()-1) {
                    currentNumSta.push(currentNum * PN);
                }
            }
            else if (s[i] == '+') {
                if (strNum == "") {
                    PN = 1;
                    continue;
                }
                else {currentNumSta.push(currentNum * PN);
                strNum = "";
                currentNum = INT_MIN;
                PN = 1;
                }
            }
            else if (s[i] == '-') {
                 if (strNum == "") {
                     PN = -1;
                     continue;
                 }
                else {currentNumSta.push(currentNum * PN);
                strNum = "";
                currentNum = INT_MIN;
                PN = -1;
            }
            }
            else if (s[i] == '*' || s[i] == '/') {
                queue<int> numQue;
                queue<char> operatorQue; 
                int tempRes = 0;
                while ((s[i] != '+' && s[i] != '-')) {
                    if (i == s.size()) break;
                    if (s[i] != '/' && s[i] != '*') {
                        strNum += s[i];
                        i++;
                        continue;
                    }
                    else if (s[i] == '*' || s[i] == '/') {
                        numQue.push(stoi(strNum));
                        operatorQue.push(s[i]);
                        strNum = "";
                        i++;
                    }
                }
                numQue.push(stoi(strNum));
                tempRes = numQue.front();
                numQue.pop();
                while (!numQue.empty()) {
                    if (operatorQue.front() == '*') {
                        tempRes *= numQue.front();
                    }
                    else {
                        tempRes /= numQue.front();
                    }
                    numQue.pop();
                    operatorQue.pop();
                }
                currentNumSta.push(tempRes * PN);
                i--;
                strNum = "";
            }
        }
        while (!currentNumSta.empty()) {
            res += currentNumSta.top();
            currentNumSta.pop();
        }
        return res;
    }
};