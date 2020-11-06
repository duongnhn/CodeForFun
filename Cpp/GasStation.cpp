// https://leetcode.com/problems/gas-station/
// 134. Gas Station
// Medium

#include <vector>
using namespace std;

class Solution {
public:
  int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
    int n = gas.size();
    int sum = 0;
    int startStation = 0;
    for (int i = 0; i < 2 * n; i++) {
      int j = i % n;
      sum += gas[j] - cost[j];
      // Sum from i to j < 0 then startStation can't be i to j
      // We try again with j+1.
      if (sum < 0) {
        startStation = (j + 1) % n;
        sum = 0;
      }
      else {
        if ((j + 1) % n == startStation) {
          return startStation;
        }
      }
    }
    return -1;
  }
};
