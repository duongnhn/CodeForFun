// https://leetcode.com/problems/count-of-smaller-numbers-after-self/
// 315. Count of Smaller Numbers After Self
// Hard

#include <vector>
using namespace std;
#define LSB(i) ((i) & (-i)) // zeros all the bits except the least siginificant one.

class Fenwick {
public: 

  Fenwick(int n) {
    size = n;
    A.resize(n+1);
  }

  int sum(int i) {
    int sum = 0;
    while (i > 0) {
      sum += A[i];
      i -= LSB(i);
    }
    return sum;
  }

  // Adds k to element of index i
  void add(int i, int k) {
    while (i < size) {
      A[i] += k;
      i += LSB(i);
    }
  }

  vector<int> A; // Binary indexed tree.
  int size;
};

class Solution {
public:
  // Solution 3: Use Fenwick or Binary Indexed Tree.
  vector<int> countSmaller(vector<int>& nums) {
    int n = nums.size();
    vector<int> out(n, 0);
    // Make all elements positive.
    for (int &num : nums) {
      num += 1e4+1;
    }
    Fenwick f(2*1e4+1);

    // Imagine we have an infinite array A of 0s. 
    // (add) For all element to the right of nums[i], add 0 at the index equal value of these elements: for j>i: A[nums[j]]++;
    // (sum) Now, we are at element i; sum(A[0]...A[nums[i]-1]) would be the number of elements that smaller then nums[i] (to the right of nums[i]).
    // Decrease i and 
    for (int i = n - 1; i >= 0; i--) {
      out[i] = f.sum(nums[i] - 1);
      f.add(nums[i], 1);
     }

    return out;
  }

  // Solution 2: 2e4*O(n) time. Not acceptable but we can optimize the sum and add operation to both O(log(2e4)) in Solution 3.
  //vector<int> countSmaller(vector<int>& nums) {
  //  int n = nums.size();
  //  vector<int> out(n, 0);
  //  // Make all element positive.
  //  for (int& num : nums) {
  //    num += 1e4 + 1;
  //  }
  //  // All elements in nums are in [1, 2*1e4].
  //  int size = 2 * 1e4 + 1;
  //  vector<int> A(size, 0);
  //  for (int i = n - 1; i >= 0; i--) {
  //    // Compute sum from A[0], .. A[nums[i]-1].
  //    for (int x = 0; x < nums[i]; x++) {
  //      out[i] += A[x];
  //    }
  //    // Add 1 to A[nums[i]].
  //    A[nums[i]]++;
  //  }
  //  return out;
  //}

  // Solution 1: O(n^2) not acceptable.
  //vector<int> countSmaller(vector<int>& nums) {
  //  int n = nums.size();
  //  vector<int> out(n);
  //  for (int i = 0; i < n - 1; i++) {
  //    for (int j = i + 1; j < n; j++) {
  //      if (nums[i] > nums[j]) {
  //        out[i]++;
  //      }
  //    }
  //  }
  //  return out;
  //}
};
