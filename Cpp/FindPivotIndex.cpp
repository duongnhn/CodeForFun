// https://leetcode.com/problems/find-pivot-index/
// 724. Find Pivot Index
// Easy

#include <vector>
using namespace std;

class Solution {
public:
  int pivotIndex(vector<int>& nums) {
    int n = nums.size();
    int sum = 0;
    for (int num : nums) sum += num;
    int left_sum = 0;
    for (int i = 0; i < n; i++) {
      int right_sum = sum - left_sum - nums[i];
      if (left_sum == right_sum) return i;
      left_sum += nums[i];
    }
    return -1;
  }
};
