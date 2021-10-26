// https://leetcode.com/problems/string-to-integer-atoi/
// 8. String to Integer (atoi)
// Medium

#include <string>
using namespace std;

class StringToInteger {
public:
    int myAtoi(string str) {
        bool is_negative = false;
        int start = 0;
        int length = str.length();
        while (start < length) {
            if (str.at(start) == ' ') {
                start++;
            }
            else {
                break;
            }
        }
        if (start == length) return 0;
        if (str.at(start) == '-') {
            start++;
            is_negative = true;
        }
        else if (str.at(start) == '+') {
            start++;
        }
        long long result = 0;
        while (start < length) {
            char ch = str.at(start);
            // invalid conversion.
            if (ch > '9' || ch < '0') {
                break;
            }
            int digit = ch - '0';
            // int temp = result;
            result = result * 10 + digit;
            // out of range.
            if (result > INT_MAX) {
                return is_negative ? INT_MIN : INT_MAX;
            }
            start++;
        }
        return is_negative ? -result : result;
    }
};
