// https://leetcode.com/problems/increasing-decreasing-string/
// 1370. Increasing Decreasing String
// Easy

#include <string>
#include <map>
using namespace std;

class Solution {
public:
  string sortString(string s) {
    map<char, int> m;
    for (char ch : s) {
      auto it = m.find(ch);
      if (it == m.end()) {
        m.insert({ ch, 1 });
      }
      else {
        it->second++;
      }
    }
    string result;
    while (true) {
      // 1. Pick the smallest character from s and append it to the result.
      auto it = m.begin();
      if (it == m.end()) return result;
      char ch = it->first;
      string str(1, ch);
      result.append(str);
      it->second--;
      if (it->second == 0) {
        m.erase(ch);
        it = m.begin();
      }
      else {
        it++;
      }
      //  Pick the smallest character from s which is greater than the last appended character to the resultand append it.
      //  Repeat step 2 until you cannot pick more characters.
      while (true) {
        while (it != m.end() && it->first <= ch) it++;
        if (it == m.end()) break;
        char current = it->first;
        string str(1, current);
        result.append(str);
        it->second--;
        ch = current;
        if (it->second == 0) {
          m.erase(current);
          it = m.begin();
        }
        else {
          it++;
        }
      }
      //  Pick the largest character from s and append it to the result.
      auto itr = m.rbegin();
      if (itr == m.rend()) return result;
      char chr = itr->first;
      string strr(1, chr);
      result.append(strr);
      itr->second--;
      if (itr->second == 0) {
        m.erase(chr);
        itr = m.rbegin();
      }
      else {
        itr++;
      }
      //  Pick the largest character from s which is smaller than the last appended character to the result and append it.
      //  Repeat step 5 until you cannot pick more characters.
      while (true) {
        while (itr != m.rend() && itr->first >= chr) itr++;
        if (itr == m.rend()) break;
        char current = itr->first;
        string str(1, current);
        result.append(str);
        itr->second--;
        chr = current;
        if (itr->second == 0) {
          m.erase(current);
          itr = m.rbegin();
        }
        else {
          itr++;
        }
      }
    }
    //  Repeat the steps from 1 to 6 until you pick all characters from s
    return result;
  }
};
