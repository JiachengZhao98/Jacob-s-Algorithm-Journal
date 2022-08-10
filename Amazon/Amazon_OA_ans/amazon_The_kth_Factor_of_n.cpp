#include "set"
#include "cmath"

using namespace std;

class Solution {
public:
    int kthFactor(int n, int k) {
        set<int> factors;
         for (int i = 1; i <= sqrt(n); i++) {
            if (n % i == 0) {
                factors.insert(i);
                factors.insert(n / i);
            }
         }
         if (factors.size() < k) return -1;
         else {
            auto iter = factors.begin();
            advance(iter, k);
            return *iter;
         }
    }
};

// brilliant thought 
class Solution_2 {
public:
    int kthFactor(int n, int k) {
        
        for(int i=1;i<=n;i++){
            if(n%i==0)
                k--;
            if(k==0)
                return i;
            
        }
        return -1;
    }
};