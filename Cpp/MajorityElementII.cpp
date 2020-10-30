// https://leetcode.com/problems/majority-element-ii/
// 229. Majority Element II
// Medium

#include <vector>
#include <unordered_set>
#include <unordered_map>
using namespace std;

class Solution {
public:
  vector<int> majorityElement(vector<int>& nums) {
    int n = nums.size();
    unordered_map<int, int> element_count_map;
    unordered_set<int> out;
    for (int num : nums) {
      auto it = element_count_map.find(num);
      int count = 1;
      if (it == element_count_map.end()) {
        element_count_map.insert({ num, 1 });
      }
      else {
        count = ++it->second;
      }
      if (count > n / 3) out.insert(num);
    }
    return vector<int>(out.begin(), out.end());
  }
};