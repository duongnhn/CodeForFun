// https://leetcode.com/problems/intersection-of-two-arrays/
// 349. Intersection of Two Arrays
// Easy

#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
public:
  vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
    unordered_set<int> s(nums1.begin(), nums1.end());
    unordered_set<int> result;
    for (int i = 0; i < nums2.size(); i++) {
      if (s.count(nums2[i])) {
        result.insert(nums2[i]);
      }
    }
    return vector<int>(result.begin(), result.end());
  }
};
