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
using namespace std;
using std::stack;

class Solution {
public:
    bool canMeasureWater(int jug1, int jug2, int tar) {
        if (jug1 + jug2 < tar) {
            return false;
        }
        vector<int> operation={jug1, jug2, -jug1, -jug2};
        map<int, int> cur;
        cur[0] = 1;
        queue<int> volume;
        volume.push(0);
        while (!volume.empty()) {
            int a = volume.front();
            volume.pop();
            if (a == tar) {
                return true;
            }
            for (int i = 0; i < 4; i++) {
                int node = a + operation[i];
                if (node == tar) {
                    return true;
                }
                if (node < 0 || node > (jug2 + jug1)) {
                    continue;
                }
                if (cur[node] == 0) {
                    volume.push(node);
                    cur[node] = 1;
                }
            }
        }
        return false;
    }
};

int main(){
    
}
