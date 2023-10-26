#include "vector"
#include "map"
using namespace::std;

class Solution {
    // same question as IsPossible in Goldman Sachs



    // Busy Intersection

    vector<int> getResult(vector<int>& arrival, vector<int>& street) {
        int n = arrival.size();
        int time = 0;
        vector<int> res(n, -1);
    }

    double average(const std::vector<int>& data) {
        double sum = 0.0;
        for (auto val : data) {
            sum += val;
        }
        return sum / data.size();
    }

    double standard_deviation(const std::vector<int>& data) {
        int n = data.size();
        double sum = 0.0;
        for (auto val : data) {
            sum += val;
        }
        double mean = sum / n;

        double sum_of_square_diff = 0.0;
        for (auto val : data) {
            sum_of_square_diff += (val - mean) * (val - mean);
        }

        return std::sqrt(sum_of_square_diff / n);
    }


    int realEstateAnalysis(int reqArea, vector<int>& area, vector<int>& price) {
        multimap<int, int> myMap;
        for (int i = 0; i < area.size(); i++) {
             myMap.insert(pair<int, int>(area[i], price[i]));
        }
        if (myMap.find(reqArea) != myMap.end()) {
            vector<int> reqAreaPrice;
            auto range = myMap.equal_range(reqArea);  // This will give a range of all pairs with key reqArea
            for (auto it = range.first; it != range.second; ++it) {
                reqAreaPrice.push_back(it->second);
            }
            double std = standard_deviation(reqAreaPrice);
            double avg = average(reqAreaPrice);
            for (auto it = range.first; it != range.second;) {
                if (abs(it->second - avg) > 3 * std) {
                    it = myMap.erase(it);
                }
                else ++it;
            }
        }
    }
};
