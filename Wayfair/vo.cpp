#include "string"
#include "iostream"
#include "unordered_map"
#include "string"
#include "vector"

using namespace std;

//  LC 1507. Reformat Date
    string reformatDate(string date) {
        unordered_map<string, string> month = {{"Jan", "01"}, {"Feb", "02"}, {"Mar", "03"}, {"Apr", "04"},
                                            {"May", "05"}, {"Jun", "06"}, {"Jul", "07"}, {"Aug", "08"},
                                            {"Sep", "09"}, {"Oct", "10"}, {"Nov", "11"}, {"Dec", "12"}};
        vector<string> getDate;
        string temp;
        for (auto a : date) {
            if (a == ' ') {
                getDate.push_back(temp);
                temp = "";
                continue;
            }
            temp += a;
        }
        getDate.push_back(temp);
        getDate[1] = month[getDate[1]];
        getDate[0].pop_back(); getDate[0].pop_back();
        if (getDate[0].size() == 1) {
            getDate[0] = '0' + getDate[0];
        }
        string res;
        for (int i = 2; i >= 0; i--) {
            res += getDate[i] + '-';
        }
        res.pop_back();
        return  res;
    }

