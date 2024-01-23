#include "vector"
#include "iostream"
#include "numeric"
using namespace std;

int main() {
    vector<int> test = {1,2,3};
    int the_sum = accumulate(test.begin(), test.end(), 0);
    cout<<the_sum<<endl;
    return 0;
}
