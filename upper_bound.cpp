#include <iostream>
#include "vector"

    int bs(int idx, std::vector<int>& prefixSum) {
        int head = 0, tail = prefixSum.size() - 1;
        while (head < tail) {
            int mid = (head + tail) / 2;
            if (idx > prefixSum[mid]) {
                head = mid + 1;
            }
            else if (idx == prefixSum[mid]) {
                return mid + 1;
            }
            else {
                if (mid > 0 && idx >= prefixSum[mid - 1]) {
                    return mid;
                }
                else tail = mid - 1;
            }
        }
        return head;
    }

int main() {
    std::vector<int> vec = {1,3,6,10,15,21};
    int index = bs(5, vec);
    std::cout<<index<<std::endl;
    return 0;
}
