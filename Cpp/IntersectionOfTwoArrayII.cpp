// https://leetcode.com/problems/intersection-of-two-arrays-ii/
// 350. Intersection of Two Arrays II
// Easy

#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
  vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
    unordered_map<int, int> m1;
    for (int num : nums1) {
      auto it = m1.find(num);
      if (it == m1.end()) {
        m1.insert({ num, 1 });
      }
      else {
        it->second++;
      }
    }
    vector<int> result;
    for (int num : nums2) {
      auto it = m1.find(num);
      if (it == m1.end()) continue;
      result.push_back(num);
      it->second--;
      if (it->second == 0) m1.erase(num);
    }
    return result;
  }
};
