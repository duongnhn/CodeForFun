// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iii/
// 123. Best Time to Buy and Sell Stock III
// Hard

#include <vector>
using namespace std;

class BestTimeStockTwoTransaction {
public:
  int maxProfit(vector<int>& prices) {
    if (prices.size() == 0) return 0;

    // There are 4 states: (1) first buy, (2) first sell, (3) second buy, (4) second sell.
    int s1 = -prices[0], s2 = INT_MIN, s3 = INT_MIN, s4 = INT_MIN;
    for (size_t i = 1; i < prices.size(); i++) {
      s1 = max(s1, -prices[i]);
      s2 = max(s2, s1 + prices[i]);
      s3 = max(s3, s2 - prices[i]);
      s4 = max(s4, s3 + prices[i]);
    }

    return max(0, s4);
  }
};