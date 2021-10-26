// https://leetcode.com/problems/sort-integers-by-the-number-of-1-bits/
// 1356. Sort Integers by The Number of 1 Bits
// Easy

#include <vector>
#include <algorithm>
using namespace std;

class SortIntegersByTheNumbersOf1Bis {
public:
  vector<int> sortByBits(vector<int>& arr) {
    std::sort(arr.begin(), arr.end(), &compare);
    return arr;
  }

  static bool compare(const int& n1, const int& n2) {
    int n1_bits = countNumberOf1Bits(n1);
    int n2_bits = countNumberOf1Bits(n2);
    if (n1_bits == n2_bits) {
      return n1 < n2;
    }
    return n1_bits < n2_bits;
  }

  static int countNumberOf1Bits(int n) {
    int count = 0;
    while (n > 0) {
      count += n & 1;
      n >>= 1;
    }
    return count;
  }
};