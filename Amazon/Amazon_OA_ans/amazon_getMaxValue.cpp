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
};
