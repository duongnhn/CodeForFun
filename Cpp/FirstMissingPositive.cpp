// https://leetcode.com/problems/first-missing-positive/
// 41. First Missing Positive
// Hard

#include <vector>
using namespace std;

class Solution {
public:
  int firstMissingPositive(vector<int>& nums) {
    int n = nums.size();
    for (int i = 0; i < n; i++) {
      if (nums[i] <= 0) {
        nums[i] = n+1;
      }
    }
    for (int i = 0; i < n; i++) {
      int j = abs(nums[i]) - 1;
      if (0 <= j && j < n) {
        nums[j] = -nums[j];
      }
    }
    for (int i = 0; i < n; i++) {
      if (nums[i] > 0) return i+1;
    }
    return n+1;
  }
};