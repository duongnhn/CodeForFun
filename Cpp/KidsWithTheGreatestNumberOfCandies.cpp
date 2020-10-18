// https://leetcode.com/problems/kids-with-the-greatest-number-of-candies/
// 1431. Kids With the Greatest Number of Candies
// Easy

#include <vector>
using namespace std;

class Solution {
public:
  vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
    int n = candies.size();
    vector<bool> result(n);
    int maxCandies = INT_MIN;
    for (int i = 0; i < n; i++) {
      maxCandies = max(maxCandies, candies[i]);
    }
    for (int i = 0; i < n; i++) {
      result[i] = maxCandies - extraCandies <= candies[i] ? true : false;
    }
    return result;
  }
};