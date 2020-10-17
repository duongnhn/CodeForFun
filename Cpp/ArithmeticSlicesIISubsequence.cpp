// https://leetcode.com/problems/arithmetic-slices-ii-subsequence/
// 446. Arithmetic Slices II - Subsequence
// Hard

#include <vector>
#include <unordered_map>
#include <unordered_set>
using namespace std;

typedef long long2_type;
typedef unordered_map<long2_type, int> slide_map_type;

class ArithmeticSlicesIISubsequence {
public:
  // Alternative approval.
  //int numberOfArithmeticSlices(vector<int>& A) {
  //  size_t n = A.size();
  //  // Hashmap D[k] stores <difference d, number of differences of size d> that 
  //  // contains to A[k] in the set of A[0], A[1], ..., A[k] 
  //  vector<slide_map_type> D(n); 
  //  unordered_set<int> s(begin(A), end(A));
  //  int result = 0;
  //  for (int i = 0; i < n; i++) {
  //    for (int j = 0; j < i; j++) {
  //      long2_type d = (long2_type)A[i] - A[j];
  //      if (d < INT_MIN || d > INT_MAX) continue;
  //      auto it = D[j].find(d);
  //      int count = it == end(D[j]) ? 0 : it->second;
  //      result += count;
  //      if (s.count((long2_type)A[i] + d)) {
  //        D[i][d] += count + 1;
  //      }
  //    }
  //  }
  //  return result;
  //}

  int numberOfArithmeticSlices(vector<int>& A) {
    // dp[i][j]: number of arithmetic slices that ends at A[i] with difference of A[i]-A[j].
    // dp[i][j] = sum_k{dp[j][k] + 1} for k < j, meaning A[j]-A[k] = A[i]-A[j] and +1 for the sequence {A[k]->A[j]->A[i]}.
    // result = sum(dp[i],dp[j]).
    const size_t n = A.size();
    vector<vector<int>> dp(n, vector<int>(n));
    unordered_set<int> s(A.begin(), A.end());
    int result = 0;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < i; j++) {
        long d = (long)A[i] - A[j];
        if (d < INT_MIN || d > INT_MAX) continue;
        if (s.find((long)A[j] - d) == s.end()) continue;
        for (int k = 0; k < j; k++) {
          if (d+A[k] == A[j]) {
            dp[i][j] += dp[j][k] + 1; 
          }
        }
        result += dp[i][j];
      }
    }
    return result;
  }
};