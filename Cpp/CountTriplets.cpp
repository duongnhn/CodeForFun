// https://www.hackerrank.com/challenges/count-triplets-1
// Count Triplets
// Medium
#include <string>
#include <algorithm>
#include <unordered_map>
#include <iostream>
using namespace std;

class Solution {
public:
  // Complete the countTriplets function below.
  long countTriplets(vector<long> arr, long r) {
    unordered_map<long/*val*/, long /*freq*/> after_map{};
    unordered_map<long/*val*/, long /*freq*/> before_map{};
    int n = arr.size();
    if (n < 3) return 0;
    for (int i = 0; i < n; i++) {
      auto it = after_map.find(arr[i]);
      if (it != after_map.end()) {
        it->second++;
      }
      else {
        after_map.insert({ arr[i], 1 });
      }
    }
    // Count triplet (i,j,k)
    long count = 0;
    for (int j = 0; j < n; j++) {
      // Update after
      long current = arr[j];
      auto it = after_map.find(current);
      it->second--;
      if (it->second == 0) after_map.erase(it);
      long after = current * r;
      auto it_after = after_map.find(after);
      if (current % r == 0 && it_after != after_map.end()) {
        long before = current / r;
        auto it_before = before_map.find(before);
        if (it_before != before_map.end()) {
          count += it_before->second * it_after->second;
        }
      }
      // Update before
      auto it_before = before_map.find(current);
      if (it_before != before_map.end()) {
        it_before->second++;
      }
      else {
        before_map.insert({ current, 1 });
      }
    }
    return count;
  }
};
