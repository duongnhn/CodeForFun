// https://leetcode.com/problems/basic-calculator-ii/
// 227. Basic Calculator II
// Medium

#include <string>
#include <list>
using namespace std;

class Solution {
public:
  int calculate(string s) {
    list<int> operands;
    list<char> operators;
    int l = s.length();
    int start = 0;
    for (int i = 0; i < l; i++) {
      if (isOperator(s[i])) {
        operators.push_back(s[i]);
        int end = i - 1;
        operands.push_back(getInteger(s, start, end));
        start = i + 1;
      }
    }
    operands.push_back(getInteger(s, start, l - 1));
    int out = operands.front();
    bool has_mul_or_div = true;
    while (true) {
      if (operators.empty()) {
        return out;
      }
      // * and /
      if (has_mul_or_div) {
        auto it_op = operators.begin();
        auto it_num = operands.begin();
        while (it_op != operators.end() && *it_op != '*' && *it_op != '/') {
          it_op++;
          it_num++;
        }
        if (it_op != operators.end()) {
          auto first = it_num;
          auto second = ++it_num;
          out = compute(*first, *second, *it_op);
          operators.erase(it_op);
          operands.insert(first, out);
          operands.erase(first, ++it_num);
          continue;
        }
        has_mul_or_div = false;
      }
      // + and -
      auto it_op = operators.begin();
      auto it_num = operands.begin();
      auto first = it_num;
      auto second = ++it_num;
      out = compute(*first, *second, *it_op);
      operators.erase(it_op);
      operands.insert(first, out);
      operands.erase(first, ++it_num);
    }
    return out;
  }

  int compute(int x, int y, char ch) {
    switch (ch) {
    case '+':
      return x + y;
    case '-':
      return x - y;
    case '*':
      return x * y;
    case '/':
      return x / y;
    default:
      break;
    }
    return -1;
  }

  bool isOperator(char ch) {
    switch (ch) {
    case '+':
    case '-':
    case '*':
    case '/':
      return true;
    default:
      break;
    }
    return false;
  }

  int getInteger(string& s, int start, int end) {
    string str;
    for (int i = start; i <= end; i++) {
      if (s[i] != ' ') {
        string temp(1, s[i]);
        str.append(temp);
      }
    }
    return stoi(str);
  }
};