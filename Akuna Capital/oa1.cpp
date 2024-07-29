#include <vector>
#include <algorithm>
#include "iostream"
#include "string"
#include "vector"
#include "unordered_map"
#include "set"
#include "unordered_set"
#include "map"
using namespace std;

int longestMarathon(const std::vector<int>& runtimes) {
    if (runtimes.empty()) {
        return 0;
    }

    std::vector<int> sortedRuntimes = runtimes;
    std::sort(sortedRuntimes.begin(), sortedRuntimes.end());

    int n = sortedRuntimes.size();
    std::vector<int> dp(n, 1); // Initialize DP array with 1 (each movie can be a marathon of length 1)

    int maxLength = 1;

    for (int i = 1; i < n; ++i) {
        for (int j = 0; j < i; ++j) {
            if (sortedRuntimes[j] == sortedRuntimes[i] || sortedRuntimes[j] == sortedRuntimes[i] - 1) {
                dp[i] = std::max(dp[i], dp[j] + 1);
            }
        }
        maxLength = std::max(maxLength, dp[i]);
    }

    return maxLength;
}

int computeDifference(const std::vector<int>& deck) {
    int top = 0;
    int bottom = deck.size() - 1;
    int miriamScore = 0;
    int alejandroScore = 0;
    bool isFlipped = false;

    bool miriamTurn = true; // Miriam always starts first

    while (top <= bottom) {
        int currentCard;
        if (isFlipped) {
            currentCard = deck[bottom];
            bottom--;
        } else {
            currentCard = deck[top];
            top++;
        }

        if (miriamTurn) {
            miriamScore += currentCard;
        } else {
            alejandroScore += currentCard;
        }

        if (currentCard % 3 == 0) {
            isFlipped = !isFlipped;
        }

        miriamTurn = !miriamTurn; // Switch turns
    }

    return miriamScore - alejandroScore;
}

int romanToInt(string s) {
        unordered_map<char, int> roman = {{'I',1}, {'V',5}, {'X',10}, {'L',50}, {'C',100},
            {'D',500}, {'M', 1000}};
        int res = 0, index = 0;
        while (index < s.size()) {
            if (s[index] == 'I') {
                if (index + 1 < s.size() && (s[index + 1] == 'V' || s[index + 1] == 'X')) {
                    res += roman[s[index + 1]] - 1;
                    index += 2; continue;
                }
            }
            if (s[index] == 'X') {
                if (index + 1 < s.size() && (s[index + 1] == 'L' || s[index + 1] == 'C')) {
                    res += roman[s[index + 1]] - 10;
                    index += 2; continue;
                }
            }
            if (s[index] == 'C') {
                if (index + 1 < s.size() && (s[index + 1] == 'D' || s[index + 1] == 'M')) {
                    res += roman[s[index + 1]] - 100;
                    index += 2; continue;
                }
            }
            res += roman[s[index]];
            index++;
        }
        return res;
    }

vector<string> regnalNames(vector<string>& names) {
    map<int, set<string>> mp;
    for (auto a : names) {
        string num_s;
        for (int i = a.size() - 1; i >= 0; i--) {
            if (a[i] == ' ') break;
            num_s = a[i] + num_s;
        }
        mp[romanToInt(num_s)].insert(a);
    }
    vector<string> res;
    for (auto a : mp) {
        for (auto name : a.second) {
            res.push_back(name);
        }
    }
    return res;
}


// sell stock

struct Order {
    int timestamp;
    int stockID;
    bool isBuy; // true for buy, false for sell
    int quantity;
};

struct PriceUpdate {
    int timestamp;
    int stockID;
    int priceChange;
};

std::unordered_map<int, int> profitsAndLosses(int initialPrice, const std::vector<Order>& orders, const std::vector<PriceUpdate>& feed) {
    std::unordered_map<int, int> stockPrices;
    std::unordered_map<int, int> profitLoss;

    // Initialize all stock prices to initialPrice
    for (const auto& order : orders) {
        stockPrices[order.stockID] = initialPrice;
    }

    for (const auto& update : feed) {
        if (stockPrices.find(update.stockID) == stockPrices.end()) {
            stockPrices[update.stockID] = initialPrice;
        }
        stockPrices[update.stockID] += update.priceChange;
    }

    for (const auto& order : orders) {
        int price = initialPrice;
        for (const auto& update : feed) {
            if (update.timestamp > order.timestamp) break;
            if (update.stockID == order.stockID) {
                price += update.priceChange;
            }
        }

        if (order.isBuy) {
            profitLoss[order.stockID] -= price * order.quantity;
        } else {
            profitLoss[order.stockID] += price * order.quantity;
        }
    }

    // Remove stocks with no orders executed
    for (auto it = profitLoss.begin(); it != profitLoss.end(); ) {
        if (it->second == 0) {
            it = profitLoss.erase(it);
        } else {
            ++it;
        }
    }

    return profitLoss;
}


int main() {
    vector<string> names = {"Nicholas VIII", "Hypapsos XXIV", "Garibald Yosef II", "Nicholas C", "Michelfranko XXIV"};
    vector<string> res = regnalNames(names);
    for (auto a : res) {
        cout<<a<<" ";
    }
    cout<<endl;
    return 0;
}
