// https://leetcode.com/problems/target-sum/
// 494. Target Sum
// Medium

#include <vector>
using namespace std;

class Solution {
public:
  int k{};

  int findTargetSumWays(vector<int>& nums, int S) {
    int n = nums.size();
    if (n == 0) return 0;
    for (int x : nums) {
      k += x;
    }
    if (S > k || S < -k) return 0;
    int size = 2 * k + 1;
    vector<int> dp(size, 0);
    dp[toIndex(nums[0])] += 1;
    dp[toIndex(-nums[0])] += 1;
    for (int i = 1; i < n; i++) {
      vector<int> next(size, 0);
      for (int j = 0; j < size; j++) {
        if (dp[j] != 0) {
          next[toIndex(fromIndex(j) + nums[i])] += dp[j];
          next[toIndex(fromIndex(j) - nums[i])] += dp[j];
        }
      }
      dp = next;
    }
    return dp[toIndex(S)];
  }

  int toIndex(int x) { return x + k; }
  int fromIndex(int x) { return x - k;  }
};
