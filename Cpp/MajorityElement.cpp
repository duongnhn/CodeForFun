// https://leetcode.com/problems/majority-element/
// 169. Majority Element
// Easy

#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
  int majorityElement(vector<int>& nums) {
    if (nums.size() == 1) return nums[0];
    unordered_map<int, int> elements_count;
    for (int num : nums) {
      auto it = elements_count.find(num);
      if (it == elements_count.end()) {
        elements_count.insert({ num, 1 });
      }
      else {
        it->second++;
        if (it->second > nums.size() / 2) return num;
      }
    }
    // Unreachable.
    return -1;
  }
};
