// https://leetcode.com/problems/integer-to-roman/
// 12. Integer to Roman
// Medium

#include <string>
#include <map>
using namespace std;

class Solution {
public:
  string intToRoman(int num) {
    string symbol[] = { "M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I" };
    int value[] = { 1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1 };    

    string out;
    int i = 0;
    int n = 13;
    while (num > 0) {
      while (i < n && value[i]>num) i++;
      out.append(symbol[i]);
      num -= value[i];
    }
    return out;
  }
};
