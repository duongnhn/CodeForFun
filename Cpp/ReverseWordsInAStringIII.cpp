// https://leetcode.com/problems/reverse-words-in-a-string-iii/
// 557. Reverse Words in a String III
// Easy

#include <string>
using namespace std;

class Solution {
public:
  string reverseWords(string s) {
    int start = 0;
    int n = s.size();
    while (start < n) {
      // start would be index of first non-space char in a word.
      while (start < n && s[start] == ' ') start++;
      if (start >= n) break;
      int end = start + 1;
      // end would be index of space char right after this word.
      while (end < n && s[end] != ' ') end++;
      reverse(s, start, end - 1);
      start = end + 1;
    }
    return s;
  }

  void reverse(string& s, int start, int end) {
    while (start < end) {
      swap(s[start], s[end]);
      start++;
      end--;
    }
  }
};
