// https://leetcode.com/problems/happy-number/
// 202. Happy Number
// Easy

#include <unordered_set>
using namespace std;

class HappyNumber {
public:
  bool isHappy(int n) {
    if (n <= 0) return false;
    if (n == 1) return true;
    unordered_set<int> s;
    s.insert(n);
    while (true) {
      int next = sumSquareDigits(n);
      if (s.count(next)) {
        return false;
      }
      if (next == 1) return true;
      n = next;
      s.insert(next);
    }
    return false;
  }

  int sumSquareDigits(int n) {
    int result = 0;
    while (n > 0) {
      int digit = n % 10;
      result += digit * digit;
      n = n / 10;
    }
    return result;
  }
};