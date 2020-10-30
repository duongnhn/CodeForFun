// https://leetcode.com/problems/total-hamming-distance/
// 477. Total Hamming Distance
// Medium

#include <vector>
using namespace std;

class Solution {
public:

  // Look into each bit in 32 bits. The hamming distance for this bit is number of set * number of unset.
  int totalHammingDistance(vector<int>& nums) {
    int out = 0;
    for (int i = 0; i < 32; i++) {
      int set = 0;
      int unset = 0;
      for (int& num : nums) {
        set += num & 1;
        unset += 1 - (num & 1);
        num >>= 1;
      }
      out += set * unset;
    }
    return out;
  }

  // (O^2) time.
  //int totalHammingDistance(vector<int>& nums) {
  //  int n = nums.size();
  //  int total = 0;
  //  for (int i = 0; i < n - 1; i++) {
  //    for (int j = i + 1; j < n; j++) {
  //      total += hammingDistance(nums[i], nums[j]);
  //    }
  //  }
  //  return total;
  //}

  //int hammingDistance(int x, int y) {
  //  return __builtin_popcount(x ^ y);
  //  // int val = x^y;
  //  // int out = 0;
  //  // while (val > 0) {
  //  //     out += val&1;
  //  //     val >>= 1;
  //  // }
  //  // return out;
  //}
};
