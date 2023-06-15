/*
You are given an array prices where prices[i] is the price of a given stock on the ith day.

You want to maximize your profit by choosing a single day to buy one stock and choosing a different day in the future to sell that stock.

Return the maximum profit you can achieve from this transaction. If you cannot achieve any profit, return 0.
*/

/*
- We use an algorithm similar to Kadane's algorithm except we aren't calculating sum but a difference between 2 numbers.
*/

#include <vector>
using namespace std;
int maxProfit(vector<int>& prices) {
    int max_profit = 0;
    int buy = 0;
    for (int i = 1; i < prices.size(); i++){
        int profit = prices[i] - prices[buy];
        if (profit >= max_profit){
            max_profit = profit;
        }
        if (profit < 0){
            buy = i;
        }
    }
    return max_profit;
}

// TC: O(n)