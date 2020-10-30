// https://leetcode.com/problems/score-after-flipping-matrix/
// 861. Score After Flipping Matrix
// Medium

#include <vector>
using namespace std;

class Solution {
public:
  int matrixScore(vector<vector<int>>& A) {
    int r = A.size();
    int c = A[0].size();

    for (int i = 0; i < r; i++) {
      // Flip any row that first column of 0.
      if (A[i][0] == 0) {
        for (int j = 0; j < c; j++) {
          A[i][j] = 1 - A[i][j];
        }
      }
    }

    // Compute col_sum and score.
    int score = 0;
    int power_2 = 1;
    for (int j = c - 1; j >= 0; j--) {
      int col_sum = 0;
      for (int i = 0; i < r; i++) {
        col_sum += A[i][j];
      }
       score += max(col_sum, r - col_sum) * power_2;
      power_2 *= 2;
    }
    return score;
  }
};
