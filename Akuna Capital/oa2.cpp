#include <vector>
#include <algorithm>
#include "iostream"
#include "string"
#include "vector"
#include "unordered_map"
#include "set"
#include "unordered_set"
#include "map"
#include "numeric"
using namespace std;

// int maximizeStudents(int shiftLength, const std::vector<int> &schedule) {
//     int n = schedule.size();
//     int maxStudents = 0;

//     if (n < 2 * shiftLength + 1) {
//         return 0; // Not enough sessions to form two shifts
//     }

//     // Initial sum for the first shift
//     int firstShiftSum = std::accumulate(schedule.begin(), schedule.begin() + shiftLength, 0);
//     // Initial sum for the second shift
//     int secondShiftSum = std::accumulate(schedule.begin() + shiftLength + 1, schedule.begin() + 2 * shiftLength + 1, 0);

//     maxStudents = firstShiftSum + secondShiftSum;

//     for (int i = 1; i <= n - 2 * shiftLength - 1; ++i) {
//         // Slide the window for the first shift
//         firstShiftSum = firstShiftSum - schedule[i - 1] + schedule[i + shiftLength - 1];
//         // Slide the window for the second shift
//         secondShiftSum = secondShiftSum - schedule[i + shiftLength] + schedule[i + 2 * shiftLength];

//         maxStudents = std::max(maxStudents, firstShiftSum + secondShiftSum);
//     }

//     return maxStudents;
// }

int maximizeStudents(int shiftLength, const std::vector<int> &schedule) {
    int n = schedule.size();
    if (n < 2 * shiftLength + 1) {
        return 0; // Not enough sessions to form two shifts
    }
    int maxStudents = 0;
    int maxSuffixSum = 0, sum = 0;
    vector<int> suffixSum(n - shiftLength + 1, 0);
    for (int i = n - shiftLength; i < n; i++) {
        maxSuffixSum += schedule[i];
        sum += schedule[i];
    }
    suffixSum.back() = maxSuffixSum;
    for (int i = n - shiftLength - 1; i >= 0; i--) {
        sum = sum + schedule[i] - schedule[i + shiftLength];
        maxSuffixSum = max(maxSuffixSum, sum);
        suffixSum[i] = maxSuffixSum;
    }
    int firstShiftSum = std::accumulate(schedule.begin(), schedule.begin() + shiftLength, 0);
    for (int i = 0; i <= n - 2 * shiftLength - 1; ++i) {
        if (i > 0) {
            firstShiftSum = firstShiftSum + schedule[i + shiftLength - 1] - schedule[i - 1];
        }
        int totalStudents = firstShiftSum + suffixSum[i + shiftLength + 1];
        maxStudents = std::max(maxStudents, totalStudents);
    }
    return maxStudents;
}

double payoutProbability(int sharksNeeded, int tanks, const std::vector<std::array<double, 6>>& probabilities) {
    std::vector<std::vector<double>> dp(tanks + 1, std::vector<double>(sharksNeeded + 1, 0.0));
    dp[0][0] = 1.0;  // Base case: 0 tanks used, 0 sharks seen

    // Process each tank
    for (int t = 1; t <= tanks; ++t) {
        // Possible sharks seen after t tanks
        for (int s = 1; s <= sharksNeeded; ++s) {
            // Try each location
            double cur = 0;
            for (const auto& prob : probabilities) {
                // Each number of sharks that could be seen in one dive at this location
                double temp = 0.0;
                for (int j = 0; j <= 5; ++j) {
                    if (s >= j) {  // Only update if the total sharks seen is feasible
                        temp += dp[t-1][s-j] * prob[j];
                    }
                }
                cur = max(temp, cur);
            }
            dp[t][s] += cur;
        }
    }

    // The probability of seeing exactly 'sharksNeeded' sharks after 'tanks' tanks
    return dp[tanks][sharksNeeded];
}

int planChocolateTour(int budget, vector<int>& shops) {
    int res = 0, expense = 0;
    int i = 0, j = 0;
    for (; i < shops.size(); i++) {
        expense += shops[i];
        if (expense == budget) return budget;
        while (expense > budget) {
            expense -= shops[j++];
        }
        res = max(res, expense);
    }
    return res;
}

// int planChocolateTour(int budget, vector<int>& shops) {
//     int res = 0, expense = 0;
//     int i = 0, j = 0;
//     for (; i < shops.size(); i++) {
//         expense += shops[i];
//         if (expense == budget) return budget;
//         while (i < shops.size() - 1 && j <= i && expense + shops[i+1] > budget) {
//             expense -= shops[j++];
//         }
//         if (res <= budget) res = max(res, expense);
//     }
//     return res;
// }


int main() {
    // vector<int> schedule = {1,6,4,10,2};
    // int res =planChocolateTour(13, schedule);
    vector<array<double, 6>> prob = {{0.1,0.1,0.2,0.2,0.3,0.1}, {0.0, 0.3, 0.15, 0.45, 0.1, 0.0}, {0.4, 0.1,0.1,0.1,0.1,0.2}};
    double res = payoutProbability(8,2,prob);
    cout<<res<<endl;
    return 0;
}


