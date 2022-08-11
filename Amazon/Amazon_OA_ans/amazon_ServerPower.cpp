#include "vector"
#include "deque"
#include "iostream"
#include "map"
using namespace std;

int findMaximumSustainableClusterSize(vector<int> processingPower, vector<int> bootingPower, long powerMax) {
        int len = processingPower.size();
        if(len == 0 || bootingPower.size() == 0) return 0;
        int ans = 0;
        for(int i=0;i<len;i++){
            int count = 1, maxCount=1, sum =0, mul;
            int Max = INT_MIN;
            for(int j=i;j<len;j++){
                sum += processingPower[j];
                mul = sum * count;
                count++;

                Max = max(Max,bootingPower[j]);
                long tempPower = mul + Max;
                if(tempPower <= powerMax){
                   // System.out.println(tempPower);
                    ans = max(maxCount, ans);
                    maxCount++;
                }else break;
            }
        }
        return ans;
}


int main() {
    vector<int> process = {3,6,1,3,4};
    vector<int> boot = {2,1,3,4,5};
    int ans  = findMaximumSustainableClusterSize(process, boot, 27);
    cout<<ans<<endl;
    return 0;
}