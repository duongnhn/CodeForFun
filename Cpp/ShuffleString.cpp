// https://leetcode.com/problems/shuffle-string/
// 1528. Shuffle String
// Easy

#include <string>
#include <vector>

using namespace std;

class Solution {
public:

  // In-place.
  string restoreString(string s, vector<int>& indices) {
    string out(s);
    for (int i = 0; i < indices.size(); i++) {
      while (indices[i] != i) {
        swap(indices[i], indices[indices[i]]);
        swap(s[i], s[indices[i]]);
      }
    }
    return s;
  }

  //// Extra O(n) space
  //string restoreString(string s, vector<int>& indices) {
  //  string out(s);
  //  for (int i = 0; i < indices.size(); i++) {
  //    out[indices[i]] = s[i];
  //  }
  //  return out;
  //}
};
