// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-transaction-fee/
// 714. Best Time to Buy and Sell Stock with Transaction Fee
// Medium

#include <vector>
using namespace std;

class BestTimeToBuyAndSellStockWithTransactionFee {
public:
  int maxProfit(vector<int>& prices, int fee) {
    size_t length = prices.size();
    int maxProfitNoOwn = 0;
    int maxProfitOwn = -prices[0]; // Buy at 0.
    for (size_t k = 1; k < length; k++) {
      int maxProfitNoOwnPrevious = maxProfitNoOwn;
      int maxProfitOwnPrevious = maxProfitOwn;
      // Consider buy at k.
      maxProfitOwn = max(maxProfitOwnPrevious, maxProfitNoOwnPrevious - prices[k]);
      // Consider sell at k.
      maxProfitNoOwn = max(maxProfitNoOwnPrevious, maxProfitOwnPrevious + prices[k] - fee);
    }
    return max(maxProfitNoOwn, maxProfitOwn);
  }
};