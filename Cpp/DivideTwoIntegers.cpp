// https://leetcode.com/problems/divide-two-integers/
// 29. Divide Two Integers
// Medium

class DivideTwoIntegers {
public:
  int divide(int dividend, int divisor) {
    const int MIN = -2147483648;
    const int MAX = 2147483647;
    long long a = dividend;
    long long b = divisor;
    if (a < MIN || a > MAX) return MAX;
    if (b < MIN || b > MAX) return MAX;
    if (b == 0) return MAX;
    if (a == 0) return 0;
    if (a == MIN && b == -1) return MAX;
    if (a == MIN && b == 1) return MIN;
    long long result = 0;
    bool positive = (a > 0 && b > 0) || (a < 0 && b < 0);
    if (a < 0) a = -a;
    if (b < 0) b = -b;
    if (b == 1) result = a;
    else {
      while (a >= b) {
        a -= b;
        result++;
      }
    }
    if (!positive) result = -result;
    if (result < MIN || result > MAX) return MAX;
    return result;
  }
};