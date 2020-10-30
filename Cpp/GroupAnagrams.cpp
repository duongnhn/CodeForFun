// https://leetcode.com/problems/group-anagrams/
// 49. Group Anagrams
// Medium

#include <string>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
  vector<vector<string>> groupAnagrams(vector<string>& strs) {
    int n = strs.size();
    vector<vector<string>> out;
    vector<string> sorted_strs;
    for (string str : strs) {
      string sorted_str = str;
      sort(sorted_str.begin(), sorted_str.end());
      sorted_strs.push_back(sorted_str);
    }
    vector<bool> grouped(n, false);
    for (int i = 0; i < n; i++) {
      if (!grouped[i]) {
        vector<string> group = { strs[i] };
        grouped[i] = true;
        for (int j = i + 1; j < n; j++) {
          if (sorted_strs[i] == sorted_strs[j]) {
            group.push_back(strs[j]);
            grouped[j] = true;
          }
        }
        out.push_back(group);
      }
    }
    return out;
  }
};
