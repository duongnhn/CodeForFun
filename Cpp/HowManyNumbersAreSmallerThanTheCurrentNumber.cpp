// https://leetcode.com/problems/how-many-numbers-are-smaller-than-the-current-number/
// 1365. How Many Numbers Are Smaller Than the Current Number
// Easy

#include <vector>
using namespace std;

class Solution {
public:
  vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
    int n = nums.size();
    int counts[101] = { 0 };
    vector<int> out(n);
    int max_num = -1;
    for (int num : nums) {
      counts[num]++;
      max_num = max(max_num, num);
    }
    for (int i = 1; i < max_num; i++) {
      counts[i] += counts[i - 1];
    }
    for (int i = 0; i < n; i++) {
      if (nums[i] == 0) continue;
      out[i] = counts[nums[i] - 1];
    }
    return out;
  }
};
