//
//  main.cpp
//  test_ beta
//
//  Created by Jiacheng Zhao on 3/16/22.
//

#include <iostream>
#include "map"
#include "vector"
using namespace std;

int main()
{
    vector<int> nums;
    nums = {0,1,2,3,3,3,3,2,6,7,8,5,9,10};
    map<int, int> myMap;
    int val = 0;
    for (int i = 0; i < nums.size(); i++) {
        myMap[nums[i]]++;
        val = myMap[nums[i]] >= myMap[val] ? nums[i] : val;
    }
    cout<<myMap.rbegin()->first<<endl;
    return 0;
}
