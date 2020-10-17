// https://leetcode.com/problems/arithmetic-slices/
// 413. Arithmetic Slices
// Medium

#include <vector>
using namespace std;

class ArithmeticSlices {
public:
  int numberOfArithmeticSlices(vector<int>& A) {
    size_t n = A.size();
    if (n <= 2) return 0;
    int last = 0;
    int count = 0;
    for (size_t k = 2; k < n; k++) {
      // count number of slides that includes A[k] as last element.
      if (A[k] - A[k - 1] == A[k - 1] - A[k - 2]) {
        last++;
        count += last;
      }
      else {
        last = 0;
      }
    }
    return count;
  }
};