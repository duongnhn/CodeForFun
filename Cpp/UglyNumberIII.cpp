// https://leetcode.com/problems/ugly-number-iii/
// 1201. Ugly Number III
// Medium

#include <algorithm>
#define ll long long 
using namespace std;

class UglyNumberIII {
public:
  int nthUglyNumber(int n, int a, int b, int c) {
    ll end = 2 * 1e9;
    ll start = 1;
    while (start < end) {
      ll mid = (start + end) / 2;
      ll number = f(mid, a, b, c);
      if (number == n) {
        return UglyNumberLessThan(mid, a, b, c);
      }
      else if (number > n) {
        end = mid - 1;
      }
      else {
        start = mid + 1;
      }
    }
    return start;
  }

  ll UglyNumberLessThan(ll k, ll a, ll b, ll c) {
    return max({ k - k % a, k - k % b, k - k % c });
  }

  ll f(ll mid, ll a, ll b, ll c) {
    return (mid / a + mid / b + mid / c - (mid / lcm(a, b) + mid / lcm(b, c) + mid / lcm(a, c) - mid / lcm(a, lcm(b, c))));
  }

  ll gcd(ll a, ll b) {
    if (b == 0)
      return a;
    return gcd(b, a % b);
  }

  ll lcm(ll a, ll b) {
    return (a * b) / gcd(a, b);
  }
};