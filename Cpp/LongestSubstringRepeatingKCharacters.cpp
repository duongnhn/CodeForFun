//https://leetcode.com/problems/longest-substring-with-at-least-k-repeating-characters/
//395. Longest Substring with At Least K Repeating Characters
//Medium

#include <vector>
#include <string>
using namespace std;

class Solution {
public:
  int longestSubstring(string s, int k) {
    int l = s.length();
    if (l == 0) return 0;
    int countMap[26] = { 0 };
    memset(countMap, 0, sizeof(countMap));
    for (char ch : s) {
      countMap[index(ch)]++;
    }
    // Number of unique charactes in s.
    int maxUnique = 0;
    for (int c : countMap) {
      if (0 < c) {
        maxUnique++;
      }
    }
    int longest = 0;
    // Sliding window base on number of unique characters.
    for (int unique = 1; unique <= maxUnique; unique++) {
      memset(countMap, 0, sizeof(countMap));
      int start = 0;
      int end = start;
      int current_unique = 0;
      int countAtLeastK = 0;
      while (end < l) {
        if (current_unique <= unique) {
          int idx = index(s[end]);
          if (countMap[idx] == 0) current_unique++;
          countMap[idx]++;
          if (countMap[idx] == k) countAtLeastK++;
          end++;
        }
        else {
          int idx = index(s[start]);
          if (countMap[idx] == k) countAtLeastK--;
          countMap[idx]--;
          if (countMap[idx] == 0) current_unique--;
          start++;
        }
        if (current_unique == unique && countAtLeastK == unique) {
          longest = max(longest, end - start);
        }
      }
    }
    return longest;
  }

  int index(char ch) {
    return ch - 'a';
  }

  //int longestSubstring(string s, int k) {
  //  int l = s.length();
  //  if (l == 0) return 0;
  //  int countMap[26] = { 0 };
  //  int longest = 0;
  //  for (int start = 0; start < l; start++) {
  //    memset(countMap, 0, sizeof(countMap));
  //    for (int end = start; end < l && end - start >= longest; end++) {
  //      countMap[s[end] - 'a']++;
  //      if (isValid(countMap, k)) {
  //        longest = max(longest, end - start + 1);
  //      }
  //    }
  //  }
  //  return longest;
  //}

  //bool isValid(int countMap[26], int k) {
  //  for (int i = 0; i < 26; i++) {
  //    if (0 < countMap[i] && countMap[i] < k) {
  //      return false;
  //    }
  //  }
  //  return true;
  //}
};
