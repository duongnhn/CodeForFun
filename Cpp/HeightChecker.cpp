// https://leetcode.com/problems/height-checker/
// 1051. Height Checker
// Easy

#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
  int heightChecker(vector<int>& heights) {
    vector<int> target(begin(heights), end(heights));
    sort(begin(target), end(target));
    int height = 0;
    for (int i = 0; i < heights.size(); i++) {
      if (target[i] != heights[i]) {
        height++;
      }
    }
    return height;
  }
};
