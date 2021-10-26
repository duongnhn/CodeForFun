// https://leetcode.com/problems/prime-palindrome/
// 866. Prime Palindrome
// Medium

#include <math.h>
#include <string>
using namespace std;

class PrimePalindrome {
public:
  int primePalindrome(int N) {
    if (N <= 2) return 2;
    if (N <= 3) return 3;
    if (N <= 5) return 5;
    if (N <= 7) return 7;
    if (N <= 11) return 11;
    if (isPalindrome(N) && isPrime(N)) return N;
    string str = to_string(N);
    int n = str.length();
    while (n <= 9) {
      int mid = n%2 == 0 ? n / 2 : n/2 + 1;
      int start = (int)pow(10, mid-1);
      int end = start*10;
      while (start < end) {
        int next = generatePalindrome(n, start);
        if (next >= N && isPrime(next)) return next;
        start++;
      }
      n++;
    }
    const int MAX = 200000000;
    return MAX;
  }

  int generatePalindrome(int n, int first_half) {
    int result = first_half;
    int mid = n / 2;
    if (n % 2 == 0) {
      return first_half * (int)pow(10, mid) + reverse(first_half);
    }
    return first_half * (int)pow(10, mid) + reverse((int)first_half / 10);
  }

  bool isPrime(int N) {
    if (N < 2) return false;
    int R = (int)sqrt(N);
    for (int i = 2; i <= R; i++) {
      if (N % i == 0) {
        return false;
      }
    }
    return true;
  }

  int reverse(int N) {
    int ans = 0;
    while (N > 0) {
      ans = 10 * ans + (N % 10);
      N /= 10;
    }
    return ans;
  }

  bool isPalindrome(int N) {
    string str = to_string(N);
    int start = 0;
    int length = str.length();
    int end = length - 1;
    while (start < end) {
      if (str[start] != str[end]) {
        return false;
      }
      start++;
      end--;
    }
    return true;  
  }
};