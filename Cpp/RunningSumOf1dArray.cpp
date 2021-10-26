// https://leetcode.com/problems/running-sum-of-1d-array/
// 1480. Running Sum of 1d Array
// Easy

#include <vector>
using namespace std;

class RunningSumOf1dArray {
public:
  vector<int> runningSum(vector<int>& nums) {
    for (size_t i = 1; i < nums.size(); i++) {
      nums[i] += nums[i - 1];
    }
    return nums;
  }
};