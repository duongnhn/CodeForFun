// https://leetcode.com/problems/sort-characters-by-frequency/
// 451. Sort Characters By Frequency
// Medium

#include <string>
#include <map>
#include <unordered_map>
using namespace std;

class Solution {
public:
  string frequencySort(string s) {
    unordered_map<char, int> chars_count_map;
    for (char ch : s) {
      auto it = chars_count_map.find(ch);
      if (it == chars_count_map.end()) {
        chars_count_map.insert({ ch, 1 });
      }
      else {
        it->second++;
      }
    }
    map<int, vector<char>> count_chars_map;
    auto it = chars_count_map.begin();
    while (it != chars_count_map.end()) {
      char ch = it->first;
      int count = it->second;
      auto it_temp = count_chars_map.find(count);
      if (it_temp == count_chars_map.end()) {
        vector<char> v = { ch };
        count_chars_map.insert({ count, v });
      }
      else {
        it_temp->second.push_back(ch);
      }
      it++;
    }
    // Create string.
    string str;
    auto it_result = count_chars_map.rbegin(); 
    while (it_result != count_chars_map.rend()) {
      int count = it_result->first;
      vector<char> v = it_result->second;
      for (char ch : v) {
        string s(1, ch);
        for (int i = 0; i < count; i++) {
          str.append(s);
        }
      }
      it_result++;
    }
    return str;
  }
};