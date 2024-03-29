// https://leetcode.com/problems/shuffle-the-array/
// 1470. Shuffle the Array
// Easy

#include <vector>
using namespace std;

class Solution {
public:
  vector<int> shuffle(vector<int>& nums, int n) {
    vector<int> result(n * 2);
    for (int i = 0; i < n * 2; i++) {
      if (i % 2 == 0) {
        result[i] = nums[i / 2];
      }
      else {
        result[i] = nums[n + i / 2];
      }
    }
    return result;
  }
};