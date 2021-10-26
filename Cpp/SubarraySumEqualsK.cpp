// https://leetcode.com/problems/subarray-sum-equals-k/
// 560. Subarray Sum Equals K
// Medium

#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
  int subarraySum(vector<int>& nums, int k) {
    unordered_map<int, int> sum_map;
    int count = 0, sum = 0;
    sum_map.insert({ 0, 1 });
    for (int i = 0; i < nums.size(); i++) {
      sum += nums[i];
      auto it = sum_map.find(sum-k);
      if (it != sum_map.end()) {
        count += it->second;
      }
      it = sum_map.find(sum);
      if (it != sum_map.end()) {
        it->second++;
      }
      else {
        sum_map.insert({ sum, 1 });
      }
    }
    return count;
  }
};