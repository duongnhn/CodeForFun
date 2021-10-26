// https://leetcode.com/problems/target-sum/
// 494. Target Sum
// Medium

#include <vector>
#include <string>
using namespace std;

class Solution {
public:
  vector<string> letterCombinations(string digits) {
    int length = digits.length();
    vector<string> out{};
    generate(out, digits, 0);
    return out;
  }

  vector<vector<char>> telephone_button = {
      {'a', 'b', 'c'},
      {'d', 'e', 'f'},
      {'g', 'h', 'i'},
      {'j', 'k', 'l'},
      {'m', 'n', 'o'},
      {'p', 'q', 'r', 's'},
      {'t', 'u', 'v'},
      {'w', 'x', 'y', 'z'},
  };
  string temp{};
  void generate(vector<string>& out, string digits, int length) {
    if (length >= digits.length()) {
      out.push_back(temp);
      return;
    }
    char x = digits.at(length);
    for (char ch : telephone_button[x - '2']) {
      temp += ch;
      generate(out, digits, length + 1);
      temp.pop_back();
    }
  }
};
