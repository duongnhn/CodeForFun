// https://leetcode.com/problems/kth-largest-element-in-an-array/
// 215. Kth Largest Element in an Array
// Medium

#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
  int findKthLargest(vector<int>& nums, int k) {
    vector<int> heap_k(nums.begin(), nums.begin()+k);
    // Min heap.
    make_heap(heap_k.begin(), heap_k.end(), greater<>{});
    auto it = nums.begin() + k;
    while (it != nums.end()) {
      heap_k.push_back(*it);
      push_heap(begin(heap_k), end(heap_k), greater<>{});
      pop_heap(begin(heap_k), end(heap_k), greater<>{});
      heap_k.pop_back();
      it++;
    }
    return heap_k.front();
  }
};