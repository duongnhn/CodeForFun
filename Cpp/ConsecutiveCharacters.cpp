// https://leetcode.com/problems/consecutive-characters/
// 1446. Consecutive Characters
// Easy

#include <string>
using namespace std;

class ConsecutiveCharacters {
public:
  int maxPower(string s) {
    int power = 0;
    int start = 0;
    while (start < s.length()) {
      int end = start+1;
      int count = 1;
      while (end < s.length() && s[end] == s[start]) {
        count++;
        end++;
      }
      if (count > power) power = count;
      start = end;
      if (s.length() - start <= power) return power;
    }
    return power;
  }
};