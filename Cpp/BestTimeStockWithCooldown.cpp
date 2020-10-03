// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-cooldown/
// 309. Best Time to Buy and Sell Stock with Cooldown
// Medium

#include <vector>
using namespace std;

class BestTimeToBuyAndSellStockWithCoolDown {
public:
  int maxProfit(vector<int>& prices) {
    size_t length = prices.size();
    vector<int> maxProfitNoOwn(length);
    vector<int> maxProfitOwn(length);
    vector<int> maxProfitCooldown(length);
    maxProfitNoOwn[0] = 0;
    maxProfitOwn[0] = -prices[0]; // Buy at 0.
    maxProfitCooldown[0] = 0;
    for (size_t k = 1; k < length; k++) {
      // Consider buy at k.
      maxProfitOwn[k] = max(maxProfitOwn[k-1], maxProfitCooldown[k-1] - prices[k]);
      // Consider sell at k.
      maxProfitNoOwn[k] = max(maxProfitNoOwn[k-1], maxProfitOwn[k-1] + prices[k]);
      // Cooldown.
      maxProfitCooldown[k] = max(maxProfitCooldown[k - 1], maxProfitNoOwn[k - 1]);
    }
    return max(maxProfitNoOwn[length-1], maxProfitOwn[length-1]);
  }
};