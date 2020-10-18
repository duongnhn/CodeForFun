// https://leetcode.com/problems/defanging-an-ip-address/
// 1108. Defanging an IP Address
// Easy

#include <string>
using namespace std;

class Solution {
public:
  string defangIPaddr(string address) {
    string out;
    for (auto ch : address) {
      if (ch == '.') {
        out.append("[.]");
      }
      else {
        string s(1, ch);
        out.append(s);
      }
    }
    return out;
  }
};
