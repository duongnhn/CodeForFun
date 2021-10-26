// https://leetcode.com/problems/maximum-nesting-depth-of-the-parentheses/
// 1614. Maximum Nesting Depth of the Parentheses
// Easy

#include <string>
using namespace std;

class Solution {
public:
  int maxDepth(string s) {
    int count = 0;
    int depth = 0;
    for (char ch : s) {
      if (ch == '(') {
        count++;
        depth = max(depth, count);
      }
      else if (ch == ')') {
        count--;
      }
    }
    return depth;
  }
};
