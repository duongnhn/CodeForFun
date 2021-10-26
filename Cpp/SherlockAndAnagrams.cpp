// https://www.hackerrank.com/challenges/magic-square-forming/
// Forming a Magic Square
// Medium
#include <string>
#include <algorithm>
#include <unordered_set>
using namespace std;

class Solution {
public:
  int sherlockAndAnagrams(string s) {
    int l = s.size();
    unordered_set<string> my_map;
    int result = 0;
    for (int i = 0; i < l; i++) {
      for (int j = 1; j < l - i + 1; j++) {
        string str = s.substr(i, j);
        sort(str.begin(), str.end());
        auto it = my_map.find(str);
        if (it != my_map.end()) {
          result++;
        }
        else {
          my_map.insert(str);
        }
      }
    }
    return result;
  }
};
