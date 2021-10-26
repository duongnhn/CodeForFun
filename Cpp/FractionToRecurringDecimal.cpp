// https://leetcode.com/problems/fraction-to-recurring-decimal/
// 166. Fraction to Recurring Decimal
// Medium

#include <string>
#include <sstream>
#include <unordered_map>
using namespace std;

class FractionToRecurringDecimal {
public:
  string fractionToDecimal(int numerator, int denominator) {
    long long a = numerator;
    long long b = denominator;
    string result;
    long long r = a / b;
    result = to_string(r);
    if (r * b == a) {
      return result;
    }
    if (a == 0) return "0";
    bool positive = (a > 0 && b > 0) || (a < 0 && b < 0);
    if (a < 0) a = -a;
    if (b < 0) b = -b;
    long long remainder = a % b;
    result.append(".");
    string fraction;
    unordered_map<long long, int> remainderSet;
    int index = 0;
    remainder *= 10;
    while (remainder != 0) {
       while (remainder < b) {
        index++;
        fraction.append("0");
        remainder *= 10;
      }
      int digit = remainder / b;
      std::unordered_map<long long, int>::const_iterator got = remainderSet.find(remainder);
      if (got != remainderSet.end()) {
        // Pattern is repeated.
        int start_repeat_index = got->second;
        string repeat = fraction.substr(start_repeat_index);
        fraction = fraction.substr(0, start_repeat_index).append("(").append(repeat).append(")");
        break;
      }
      remainderSet.insert({ remainder, index });
      remainder = remainder % b;
      fraction.append(to_string(digit));
      index++;
      remainder *= 10;
    }
    result.append(fraction);
    if (!positive) {
      if (result[0] != '-') {
        string neg = "-";
        neg.append(result);
        return neg;
      }
    }
    return result;
  }
};