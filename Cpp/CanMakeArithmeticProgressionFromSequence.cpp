// https://leetcode.com/problems/can-make-arithmetic-progression-from-sequence/
// 1502. Can Make Arithmetic Progression From Sequence
// Easy

#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
  bool canMakeArithmeticProgression(vector<int>& arr) {
    int n = arr.size();
    sort(arr.begin(), arr.end());
    int d = arr[1] - arr[0];
    for (int i = 2; i < arr.size(); i++) {
      if (arr[i] - arr[i - 1] != d) return false;
    }
    return true;
  }
};
