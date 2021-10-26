// https://leetcode.com/problems/maximum-length-of-repeated-subarray/
// 718. Maximum Length of Repeated Subarray
// Medium

#include <vector>
using namespace std;

class Solution {
public:
  int findLength(vector<int>& A, vector<int>& B) {
    int n = A.size();
    int m = B.size();
    vector<vector<int>> dp(n+1, vector<int> (m+1, 0));
    // dp[i][j]: max length of subarray from A[0:i-1] and B[0:j-1] where contains A[i-1] == B[j-1]
    // we need to find max(dp[i][j])
    int length = 0;
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= m; j++) {
        if (A[i-1] == B[j-1]) {
          dp[i][j] = dp[i - 1][j - 1] + 1;
          length = max(length, dp[i][j]);
        }
      }
    }
    return length;
  }
};