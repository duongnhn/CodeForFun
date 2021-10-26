// https://leetcode.com/problems/ugly-number-ii/
// 264. Ugly Number II
// Medium

#include <vector>
using namespace std;

class UglyNumberII {
public:
  int nthUglyNumber(int n) {
    if (n == 0) return 1;
    vector<int> dp = { 1 };
    int p2 = 0, p3 = 0, p5 = 0;
    for (int i = 1; i < n; i++) {
      int a2 = dp[p2] * 2;
      int a3 = dp[p3] * 3;
      int a5 = dp[p5] * 5;
      int next = min({ a2, a3, a5 });
      dp.push_back(next);
      if (next == a2) p2++;
      if (next == a3) p3++;
      if (next == a5) p5++;
    }
    return dp[(size_t)n - 1];
  }
};