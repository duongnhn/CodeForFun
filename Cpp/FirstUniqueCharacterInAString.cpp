// https://leetcode.com/problems/first-unique-character-in-a-string/
// 387. First Unique Character in a String
// Easy

#include <string>
using namespace std;

class Solution {
public:
  int firstUniqChar(string s) {
    const int size = 'z' - 'a' + 1;
    int count[size] = { 0 };
    for (char ch : s) {
      count[ch - 'a']++;
    }
    for (int i= 0; i < s.length();i++) {
      if (count[s[i] - 'a'] == 1) return i;
    }
    return -1;
  }
};