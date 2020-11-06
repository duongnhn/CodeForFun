// https://leetcode.com/problems/number-of-islands/
// 200. Number of Islands
// Medium

#include <vector>
using namespace std;

class Solution {
public:

  int numIslands(vector<vector<char>>& grid) {
    int m = grid.size();
    int n = grid[0].size();
    int count = 0;
    vector<vector<bool>> visited(m, vector<bool>(n, false));
    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        if (grid[i][j] == '1' && !visited[i][j]) {
          count++;
          visit(grid, visited, i, j, m, n);
        }
      }
    }
    return count;
  }

  vector<int> u = { 1, 0, 0, -1 };
  vector<int> v = { 0, 1, -1, 0 };

  void visit(vector<vector<char>>& grid, vector<vector<bool>>& visited, int i, int j, int m, int n) {
    visited[i][j] = true;
    for (int k = 0; k < 4; k++) {
      int r = i + u[k];
      int l = j + v[k];
      if (0 <= r && r < m && 0 <= l && l < n && !visited[r][l] && grid[r][l] == '1') {
        visit(grid, visited, i + u[k], j + v[k], m, n);
      }
    }
  }
};
