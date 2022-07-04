#include "iostream"
#include "vector"
using namespace std;
class Solution_1 {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        vector<int> mxr(n);   //max height to right
        vector<int> mxl(n);   //max height to left
        
        //max to left (mxl vector)
        int prevmxl = INT_MIN;
        for (int i = 0; i<n; i++) {
            mxl[i] = max(prevmxl, height[i]);
            prevmxl = mxl[i];
        }
        
        //max to right (mxr vector)
        int prevmxr = INT_MIN;
        for (int i = n-1; i>=0; i--) {
            mxr[i] = max(prevmxr, height[i]);
            prevmxr = mxr[i];
        }
        int sum = 0;
        vector<int> water(n);
        for (int i = 0; i<n; i++) {
            water[i] = min(mxr[i], mxl[i]) - height[i];
            sum+=water[i];
        }
        return sum;
    }
};