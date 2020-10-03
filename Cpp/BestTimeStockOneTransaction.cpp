// https://leetcode.com/problems/best-time-to-buy-and-sell-stock/
// 121. Best Time to Buy and Sell Stock
// Easy

#include <vector>
using namespace std; class BestTimeStockOneTransaction {
public:
  int maxProfit(vector<int>& prices) {
    if (prices.empty()) return 0;
    int profit = 0;
    int minCostToBuy = prices[0];
    for (size_t i = 1; i < prices.size(); i++) {
      profit = max(profit, prices[i] - minCostToBuy);
      minCostToBuy = min(minCostToBuy, prices[i]);
    }
    return profit;
  }
};