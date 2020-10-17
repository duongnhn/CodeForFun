// https://leetcode.com/problems/subrectangle-queries/
// 1476. Subrectangle Queries
// Medium

#include <vector>
using namespace std;

class SubrectangleQueries {
public:
  SubrectangleQueries(vector<vector<int>>& rectangle) {
    row_ = rectangle.size();
    col_ = rectangle[0].size();
    rectangle_ = rectangle;
  }

  void updateSubrectangle(int row1, int col1, int row2, int col2, int newValue) {
    for (int i = row1; i <= row2; i++) {
      for (int j = col1; j <= col2; j++) {
        rectangle_[i][j] = newValue;
      }
    }
  }

  int getValue(int row, int col) {
    return rectangle_[row][col];
  }

  int row_;
  int col_;
  vector<vector<int>> rectangle_;
};

/**
 * Your SubrectangleQueries object will be instantiated and called as such:
 * SubrectangleQueries* obj = new SubrectangleQueries(rectangle);
 * obj->updateSubrectangle(row1,col1,row2,col2,newValue);
 * int param_2 = obj->getValue(row,col);
 */