//
//  main.cpp
//  LC_stockPrices
//
//  Created by Jiacheng Zhao on 4/12/22.
//
//  All Rights Reserved

//BELW ARE LEETCODE STOCK PRICES RELATED PROBLEMS

//REFERENCE: https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-transaction-fee/discuss/108870/Most-consistent-ways-of-dealing-with-the-series-of-stock-problems


#include <iostream>
#include "vector"

using namespace std;

// dynamic programming framework for stock prices problems

//base case：
//dp[-1][...][0] = dp[...][0][0] = 0
//dp[-1][...][1] = dp[...][0][1] = -infinity
//
//state transfer formula：
//dp[i][k][0] = max(dp[i-1][k][0], dp[i-1][k][1] + prices[i])
//dp[i][k][1] = max(dp[i-1][k][1], dp[i-1][k-1][0] - prices[i])






// LC_121 Best Time to Buy and Sell Stock : EASY
// greedy alg
class Solution_121_1 {
public:
    int maxProfit(vector<int>& prices) {
        int low = INT_MAX;
        int res = 0;
        for (auto a : prices) {
            low = min(a, low); // find the lowest price of stock to buy
            res = max(res, a - low);
        }
        return res;
    }
};

// dynamic programming
class Solution_121_2 {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n, vector<int>(2,0));
        for (int i = 0; i < n; i++) {
            if (i == 0) {
                dp[i][0] = 0;
                dp[i][1] = -prices[i];               //  Base case;
                continue;
            }
            dp[i][0] = max(dp[i - 1][0], dp[i - 1][1] + prices[i]);
            dp[i][1] = max(-prices[i], dp[i - 1][1]); // In this case, dp[i - 1][0][0] - prices[i] = -prices[i] because when on day 0 and we don't buy any stocks yet
                                                     //, of course our profit is -prices[i] since dp[i - 1][0][0] = 0;
            
                                                     // In this two state transfer formulas k in all equations is 1, so we simplify the formula by removing the k from
                                                     // the formula.
        }
        return dp[n - 1][0];
    }
};

// LC_122 Best Time to Buy and Sell Stock II : MEDIUM

// greedy alg

class Solution_122_1 {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.size() < 2) {
            return 0;
        }
        int fast = 1;
        int slow = 0;
        int profit = 0;
        while (fast < prices.size()) {
            if (prices[fast] > prices[slow]) {
                profit += (prices[fast] - prices[slow]); // each time we find that tomorow's price is higher, we buy the stock and then sell it the next day.
            }
            slow++;
            fast++;
        }
        return profit;
    }
};

// Dynamic programming
class Solution_122_2 {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp (n, vector<int>(2,0));
        for (int i = 0; i < n; i++) {
            if (i == 0) {
                dp[i][0] = 0;
                dp[i][1] = -prices[i];       // Base case
                continue;
            }
            dp[i][0] = max(dp[i - 1][1] + prices[i], dp[i - 1][0]);
            dp[i][1] = max(dp[i - 1][1], dp[i - 1][0] - prices[i]);   // in this scenario we simplify the formula because k = + infinity -> k = k - 1;
        }
        return dp[n - 1][0];
    }
};


 
// LC_123  Best Time to Buy and Sell Stock III : HARD

//dynamic programming

class Solution_123 {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(3, vector<int>(2,0)));
        for (int i = 0; i < n; i++) {
            for (int k = 1; k < 3; k++) {
                if (i == 0) {
                    dp[i][k][0] = 0;
                    dp[i][k][1] = -prices[i];   // In this base case we need to define the specific number when k = 1 and k = 2
                    continue;
                }
                dp[i][k][0] = max(dp[i - 1][k][0], dp[i - 1][k][1] + prices[i]);
                dp[i][k][1] = max(dp[i - 1][k - 1][0] - prices[i], dp[i - 1][k][1]);
            }
        }
        return dp[n - 1][2][0];
    }
};



//LC_188  Best Time to Buy and Sell Stock IV : HARD

class Solution_188 {
public:
    int maxProfit(int K, vector<int>& prices) {
        int n = prices.size();
        if (n == 0) {
            return 0;
        }
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(K + 1, vector<int>(2,0)));
        for (int i = 0; i < n; i++) {
            for (int k = 1; k < K + 1; k++) {
                if (i == 0) {
                    dp[i][k][0] = 0;
                    dp[i][k][1] = -prices[i];
                    continue;
                }
                dp[i][k][0] = max(dp[i - 1][k][0], dp[i - 1][k][1] + prices[i]);
                dp[i][k][1] = max(dp[i - 1][k - 1][0] - prices[i], dp[i - 1][k][1]);
            }
        }
        return dp[n - 1][K][0];
    }
};

