// https://www.hackerrank.com/challenges/magic-square-forming/
// Forming a Magic Square
// Medium

#include <vector>
#include <cmath>
using namespace std;

class Solution {
public:
  int formingMagicSquare(vector<vector<int>> s) {
    vector<vector<vector<int>>> magic = { {{8, 1, 6},{3, 5, 7},{4, 9, 2}},
            {{6, 1, 8},{7, 5, 3},{2, 9, 4}},
            {{4, 9, 2},{3, 5, 7},{8, 1, 6}},
            {{2, 9, 4},{7, 5, 3},{6, 1, 8}},
            {{8, 3, 4},{1, 5, 9},{6, 7, 2}},
            {{4, 3, 8},{9, 5, 1},{2, 7, 6}},
            {{6, 7, 2},{1, 5, 9},{8, 3, 4}},
            {{2, 7, 6},{9, 5, 1},{4, 3, 8}}, };
    int result = 100;
    for (auto square: magic) {
      int temp = 0;
      for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
          temp += abs(s[i][j] - square[i][j]);
      if (temp < result) result = temp;
    }
    return result;
  }
};
