// https://leetcode.com/problems/find-common-characters/
// 1002. Find Common Characters
// Easy

#include <vector>
#include <string>
#include <unordered_map>
using namespace std;

class Solution {
public:
  vector<string> commonChars(vector<string>& A) {
    const int length = 'z' - 'a' + 1;
    int char_count[length] = {0};
    for (char ch : A[0]) {
      char_count[ch - 'a']++;
    }
    for (int i = 1; i < A.size(); i++) {
      int temp[length] = { 0 };
      for (char ch : A[i]) {
        temp[ch - 'a']++;
      }
      for (int i = 0; i < length; i++) {
        char_count[i] = min(char_count[i], temp[i]);
      }
    }
    vector<string> v;
    for (int i = 0; i < length; i++) {
      for (int j = 0; j < char_count[i]; j++) {
        string s(1, i + 'a');
        v.push_back(s);
      }
    }
    return v;
  }

  // Solution 1: Using map.
  //vector<string> commonChars(vector<string>& A) {
  //  unordered_map<char, int> m;
  //  for (char ch : A[0]) {
  //    auto it = m.find(ch);
  //    if (it != m.end()) {
  //      it->second++;
  //    }
  //    else {
  //      m.insert({ ch , 1 });
  //    }
  //  }
  //  for (int i = 1; i < A.size(); i++) {
  //    unordered_map<char, int> temp;
  //    string& str = A[i];
  //    for (char ch : str) {
  //      auto it = m.find(ch);
  //      if (it == m.end()) continue;
  //      it->second--;
  //      if (it->second == 0) m.erase(ch);
  //      // insert to temp.
  //      it = temp.find(ch);
  //      if (it != temp.end()) {
  //        it->second++;
  //      }
  //      else {
  //        temp.insert({ ch, 1 });
  //      }
  //    }
  //    m = temp;
  //  }
  //  // return from m;
  //  auto it = m.begin();
  //  vector<string> v;
  //  while (it != m.end()) {
  //    string s(1, it->first);
  //    int count = it->second;
  //    while (count > 0) {
  //      v.push_back(s);
  //      count--;
  //    }
  //    it++;
  //  }
  //  return v;
  //}
};
