#include "vector"
#include "climits"
using namespace std;

class Solution {
public:
    long long minimumHealth(vector<int>& damage, int armor) {
        int Max = INT_MIN;    
        long sum = 0;
        for (auto a : damage) {
            sum += a;                    // sum all the damage
            Max = a > Max ? a : Max;     // find the largest value in damage
        }    
        if (armor >= Max) {
            return (sum + 1 - Max);      // use armor to defend
        }
        else return (sum + 1 - armor);   // add more health if the armor can NOT defend the largest damage
    }
};