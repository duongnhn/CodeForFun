// https://leetcode.com/problems/kth-smallest-element-in-a-sorted-matrix/
// 378. Kth Smallest Element in a Sorted Matrix
// Medium

#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
  // O^(n^logn log(max-min))
  int kthSmallest(vector<vector<int>>& matrix, int k) {
    int n = matrix.size();
    int start = matrix[0][0]; // min
    int end = matrix[n - 1][n - 1]; // max
    while (start < end) {
      int mid = (start + end) / 2;
      int count = 0, j;
      // count the numbers in matrix that <= mid;
      for (int i = 0; i < n; i++) {
        // since it is already sorted, we can use binary search here.
        int start_col = 0;
        int end_col = n;
        while (start_col < end_col) {
          int mid_col = (end_col + start_col) / 2;
          if (matrix[i][mid_col] <= mid) {
            start_col = mid_col + 1;
          }
          else {
            end_col = mid_col;
          }
        }
        count += start_col;
      }
      if (count < k) {
        start = mid + 1;
      }
      else {
        end = mid;
      }
    }
    return start;
  }

  // O(n^2) space and O(n^2) time
  //int kthSmallest(vector<vector<int>>& matrix, int k) {
  //  priority_queue<int, vector<int>, greater<int>> pq;
  //  for (auto i : matrix) {
  //    for (auto j : i) {
  //      pq.push(j);
  //    }
  //  }
  //  for (int i = 0; i < k - 1; i++) {
  //    pq.pop();
  //  }
  //  return pq.top();
  //}
};
