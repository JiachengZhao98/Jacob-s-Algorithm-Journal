#include "iostream"
#include "stdio.h"
#include "cmath"
#include "string"
#include "string.h"
#include "array"
#include "set"
#include "map"
#include "vector"
#include "algorithm"
#include "stack"
#include "queue"
#include "unordered_set"
#include "unordered_map"
using namespace std;

class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        if (bills[0] > 5){
            return false;
        }
        if (bills.size() == 1) {
            return true;
        }
        vector<vector<int>> income = {{5, 10}, {0, 0}};
        for (int i = 0; i < bills.size(); i++) {
            for (int j = 0; j < 3; j++) {
                if (income[0][j] == bills[i]) {
                    income[1][j]++;
                }
            }
            int change = bills[i] - 5;
            if (change == 5) {
                if (income[1][0] >= 1) {
                    income[1][0]--;
                }
                else return false;
            }
            if (change == 15) {
                if (income[1][1] >= 1) {
                    income[1][1]--;
                    if (income[1][0] >= 1) {
                        income[1][0]--;
                    }
                    else return false;
                }
                else if (income[1][0] >=3){
                    income[1][0] -= 3;
                } else return false;
            }
        }
        return true;
    }
};

