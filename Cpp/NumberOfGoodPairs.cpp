// https://leetcode.com/problems/number-of-good-pairs
// 1512. Number of Good Pairs
// Easy

#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
  int numIdenticalPairs(vector<int>& nums) {
    int n = nums.size();
    unordered_map<int, int> m;
    for (int i = 0; i < n; i++) {
      auto it = m.find(nums[i]);
      if (it != m.end()) {
        m[nums[i]]++;
      } else {
        m.insert({ nums[i], 1 });
      }
    }
    auto it = m.begin();
    int count = 0;
    while (it != m.end()) {
      int t = it->second;
      count += t * (t - 1) / 2;
      it++;
    }
    return count;
  }
};