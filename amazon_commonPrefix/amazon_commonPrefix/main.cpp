//
//  main.cpp
//  amazon_commonPrefix
//
//  Created by Jiacheng Zhao on 3/15/22.
//

#include <iostream>
#include "vector"
#include "algorithm"
#include "string"
using namespace std;

vector<int> commonPrefix(string inputs){
    vector<int> res;
    int i = 0;
    int count = 0;
    for (int j = 0; j < inputs.size(); j++) {
        if (inputs[j] == inputs[0]) {
            int index = j;
            while (index < inputs.size() && inputs[index] == inputs[i]) {
                count++;
                index++;
                i++;
            }
            res.push_back(count);
            i = 0;
            count = 0; continue;
        }
        res.push_back(0);
    }
    return res;
}

int main() {
    vector<int> res;
    string inputs = "abcabcd";
    res = commonPrefix(inputs);
    for(auto a : res) {
        cout<<a<<" ";
    }
    cout<<endl;
    return 0;
}
