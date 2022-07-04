#include "iostream"
#include "vector"
#include "unordered_map"
#include "unordered_set"
using namespace std;

class Solution_1 {
public:
    /**
     * @param numbers: An array of Integer
     * @param target: target = numbers[index1] + numbers[index2]
     * @return: [index1, index2] (index1 < index2)
     */
    vector<int> twoSum(vector<int> &numbers, int target) {
        int slow = 0, fast;
        vector<int> res;
        while (slow < numbers.size()) {
            for (fast = slow + 1; fast < numbers.size(); fast++) {
                if (numbers[slow] + numbers[fast] == target) {
                    res.push_back(slow);
                    res.push_back(fast);
                }
            }
            slow++;
        }
        return res;
    }
};

class Solution_2 {
public:
    vector<int> twoSum(vector<int>& num, int target) {
        unordered_map<int,int> res;
        for (int i = 0; i < num.size(); i++) {
            auto iter = res.find(target - num[i]);
            if (iter != res.end()) {
                return {iter->second, i};
            }
            res.insert(pair<int, int>(num[i], i));
        }
    return {};
    }
};
