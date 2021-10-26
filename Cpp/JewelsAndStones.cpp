// https://leetcode.com/problems/jewels-and-stones/
// 771. Jewels and Stones
// Easy

#include <string>
#include <unordered_set>
using namespace std;

class Solution {
public:
  int numJewelsInStones(string J, string S) {
    unordered_set<char> s(J.begin(), J.end());
    int count = 0;
    for (char ch : S) {
      count += s.count(ch);
    }
    return count;
  }
};