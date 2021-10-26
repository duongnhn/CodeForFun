// https://leetcode.com/problems/replace-the-substring-for-balanced-string/
// 1234. Replace the Substring for Balanced String
// Medium
#include <string>
#include <algorithm>
#include <unordered_map>
using namespace std;

class Solution {
public:
  int balancedString(string s) {
    int n = s.length();
    int each = n / 4;
    unordered_map<char, int> count{};
    for (char ch : s) {
      auto it = count.find(ch);
      if (it != count.end()) {
        it->second++;
      }
      else {
        count.insert({ ch, 1 });
      }
    }
    int sum = 0;
    auto it = count.begin();
    unordered_map<char, int> to_remove{};
    while (it != count.end()) {
      it->second -= each;
      if (it->second > 0) {
        sum += it->second;
        to_remove.insert({ it->first, it->second });
      }
      it++;
    }
    if (sum <= 1) return sum;
    // find min substring that contains count{}
    int i = 0, j = 0, min = INT_MAX, unique_count = to_remove.size();
    while (j < n) {
      char ch = s[j];
      auto it = to_remove.find(ch);
      if (it != to_remove.end()) {
        it->second--;
        if (it->second == 0) unique_count--;
      }
      if (unique_count > 0) {
        j++;
      }
      else if (unique_count == 0) {
        min = std::min(j - i + 1, min);
        while (unique_count == 0) {
          char ch = s[i];
          auto it = to_remove.find(ch);
          if (it != to_remove.end()) {
            it->second++;
            if (it->second == 1) unique_count++;
          }
          min = std::min(j - i + 1, min);
          i++;
        }
        j++;
      }
    }
    return min;
  }
};
