// https://leetcode.com/problems/third-maximum-number/
// 414. Third Maximum Number
// Easy

#include <vector>
#include <set>
using namespace std;

class Solution {
public:
  int thirdMax(vector<int>& nums) {
    set<int> s(begin(nums), end(nums));
    auto it = rbegin(s);
    if (s.size() < 3) return *it;
    it++;
    it++;
    return *it;
  }
};