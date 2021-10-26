// https://leetcode.com/problems/decompress-run-length-encoded-list/
// 1313. Decompress Run - Length Encoded List
// Easy

#include <vector>
using namespace std;

class Solution {
public:
  vector<int> decompressRLElist(vector<int>& nums) {
    vector<int> out;
    for (int i = 0; i < nums.size(); i+=2) {
      while (nums[i]--) {
        out.push_back(nums[i+1]);
      }
    }
    return out;
  }
};
