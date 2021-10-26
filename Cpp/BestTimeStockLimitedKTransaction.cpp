// https://leetcode.com/problems/best-time-to-buy-and-sell-stock/
// 121. Best Time to Buy and Sell Stock
// Easy

#include <vector>
using namespace std; 
// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iv/
// 188. Best Time to Buy and Sell Stock IV
// Hard

class BestTimeStockLimitedKTransaction {
public:
  int maxProfit(int k, vector<int>& prices) {
    if (prices.size() == 0) return 0;

    if (k <= 0) return 0;
    size_t size = prices.size();
    int numberOfTransaction = size%2==0? (int)size/2 : (int)size/2+1;

    if (k >= numberOfTransaction) {
      int profit = 0;
      for (size_t i = 1; i < size; i++)
        if (prices[i] > prices[i - 1])
          profit += prices[i] - prices[i - 1];
      return profit;
    }

    int length = k * 2;

    vector<int> s(length);
    s[0] = -prices[0];
    for (size_t i = 1; i < s.size(); i++) {
      s[i] = INT_MIN;
    }
    for (size_t i = 1; i < prices.size(); i++) {
      s[0] = max(s[0], -prices[i]);
      for (size_t j = 1; j < s.size(); j++) {
        int sign = j % 2 == 0 ? -1 : 1;
        s[j] = max(s[j], s[j - 1] + prices[i] * sign);
      }
    }

    return max(0, s[(size_t)length-1]);
  }
};