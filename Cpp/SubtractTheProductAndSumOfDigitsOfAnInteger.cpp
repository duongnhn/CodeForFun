//https://leetcode.com/problems/subtract-the-product-and-sum-of-digits-of-an-integer/
//1281. Subtract the Product and Sum of Digits of an Integer
//Easy

class Solution {
public:
  int subtractProductAndSum(int n) {
    int product = 1;
    int sum = 0;
    while (n > 0) {
      int digit = n % 10;
      sum += digit;
      product *= digit;
      n = n / 10;
    }
    return product - sum;
  }
};
