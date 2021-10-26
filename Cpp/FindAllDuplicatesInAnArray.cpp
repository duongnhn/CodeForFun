// https://leetcode.com/problems/find-all-duplicates-in-an-array/
// 442. Find All Duplicates in an Array
// Medium

#include <vector>
#include <math.h>
using namespace std;

class FindAllDuplicatesInAnArray {
public:

  // Solution 1: Try to sort array: move element in its correct position if possible.
  //vector<int> findDuplicates(vector<int>& nums) {
  //  int n = nums.size();
  //  int i = 0;
  //  while (i < n) {
  //    int j = nums[i] - 1;
  //    if (i != j && nums[i] != nums[j]) {
  //      swap(nums[i], nums[j]);
  //    }
  //    else {
  //      i++;
  //    }
  //  }
  //  vector<int> result;
  //  for (int i = 0; i < n; i++) {
  //    if (nums[i] != i + 1) {
  //      result.push_back(nums[i]);
  //    }
  //  }
  //  return result;
  //}

  // Solution 2: "Hashset-ish" flip the sign of the element in the correct position. 
  // If found something negative then it is duplicate.
  vector<int> findDuplicates(vector<int>& nums) {
    int n = nums.size();
    vector<int> result;
    for (int i = 0; i < n; i++) {
      int j = abs(nums[i]) - 1;
      if (nums[j] < 0) {
        result.push_back(j+1);
      }
      else {
        nums[j] = -nums[j];
      }
    }
    return result;
  }
};