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
using namespace std;
/* class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        for (int i = 0; i < cost.size(); i++) {
            int rest = gas[i] - cost[i]; // gas remaining
            int index = (i + 1) % cost.size();
            while (rest >= 0 && index != i) { // starting from point i
                rest += gas[index] - cost[index];
                index = (index + 1) % cost.size();
            }
            //             if (rest >= 0 && index == i) return i;
        }
        return -1;
    }
}; */  // Brutal force is not working. ecceeds the time limit

class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int sumCost = 0;
        int sumGas = 0;
        for (int i = 0; i < gas.size(); i++) {
            sumGas += gas[i];
            sumCost += cost[i];
        }
        if (sumGas < sumCost) {
            return -1;
        }
        int preSum = 0;
        int sum = 0;
        int index = 0;
        for (int i = 0; i < gas.size(); i++) {
            preSum += gas[i] - cost[i];
            if (preSum < 0) {
                preSum = 0;
                sum = 0;
                index = i + 1;
            }
        }
        return index;
    }
};

