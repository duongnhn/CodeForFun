// https://leetcode.com/problems/number-of-steps-to-reduce-a-number-to-zero/
// 1342. Number of Steps to Reduce a Number to Zero
// Easy

class Solution {
public:
  int numberOfSteps(int num) {
    if (num == 0) return 0;
    if (num % 2 == 0) return 1 + numberOfSteps(num / 2);
    else return 1 + numberOfSteps(num - 1);
  }
};
