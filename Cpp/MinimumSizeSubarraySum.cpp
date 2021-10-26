// https://leetcode.com/problems/minimum-size-subarray-sum/
// 209. Minimum Size Subarray Sum
// Medium

#include <vector>
using namespace std;

class Solution {
public:

  // O(n^2) solution.
  //int minSubArrayLen(int s, vector<int>& nums) {
  //  int n = nums.size();
  //  if (n == 0) return 0;
  //  vector<int> sums(n + 1);
  //  int start_index = 0;
  //  for (int i = 1; i <= n; i++) {
  //    sums[i] = sums[i - 1] + nums[i - 1];
  //    if (sums[i - 1] < s && sums[i] >= s) start_index = i;
  //  }
  //  if (sums[n] < s) return 0;
  //  if (sums[n] == s) return n;
  //  int length = n + 1;
  //  for (int i = start_index; i <= n; i++) {
  //    for (int j = i - 1; j >= 0; j--) {
  //      int current_sum = sums[i] - sums[j];
  //      if (current_sum >= s) {
  //        length = min(length, i - j);
  //        break; // move to next i.
  //      }
  //    }
  //  }
  //  return length == n + 1 ? 0 : length;
  //}

  // O(nlogn) solution
  //int minSubArrayLen(int s, vector<int>& nums) {
  //  int n = nums.size();
  //  if (n == 0) return 0;
  //  vector<int> sums(n + 1);
  //  for (int i = 1; i <= n; i++) {
  //    sums[i] = sums[i - 1] + nums[i - 1];
  //  }
  //  int length = n + 1;
  //  for (int i = 0; i < n; i++) {
  //    int target = sums[i] + s;
  //    auto bound = lower_bound(sums.begin(), sums.end(), target);
  //    if (bound != sums.end()) {
  //      length = min(length, static_cast<int>(bound - (sums.begin() + i)));
  //    }
  //  }
  //  return (length == n + 1) ? 0 : length;
  //}

  // O(n) solution
  int minSubArrayLen(int s, vector<int>& nums) {
    int n = nums.size();
    if (n == 0) return 0;
    int sum = 0;
    int left = 0;
    int length = n + 1;
    for (int right = 0; right < n; right++) {
      sum += nums[right];
      while (sum >= s && left <= right) {
        length = min(length, right - left+1);
        sum -= nums[left];
        left++;
      }
    }
    return length == n + 1 ? 0 : length;
  }
};