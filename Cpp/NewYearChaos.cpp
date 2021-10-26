// https://www.hackerrank.com/challenges/new-year-chaos
// New Year Chaos
// Medium
#include <string>
#include <algorithm>
#include <unordered_map>
#include <iostream>
using namespace std;

class Solution {
public:
  void minimumBribes(vector<int> q) {
    int n = q.size();
    vector<int> indices(n);
    for (int i = 0; i < n; i++) {
      indices[q[i] - 1] = i;
    }
    int start = n - 1, bride = 0;
    while (true) {
      while (start >= 0 && indices[start] == start) start--;
      if (start < 0) {
        cout << bride << "\n";
        return;
      }
      int index = indices[start];
      if (index < start - 2) {
        break;
      }
      // swap q[i] to q[start]
      while (index < start) {
        std::swap(indices[q[index]-1], indices[q[index + 1]-1]);
        std::swap(q[index], q[index + 1]);
        bride++;
        index++;
      }
    }
    cout << "Too chaotic" << "\n";
  }
};
