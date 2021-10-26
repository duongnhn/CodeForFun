// https://leetcode.com/problems/non-decreasing-array/
// 665. Non-decreasing Array
// Easy

#include <vector>
using namespace std;

class NonDecreasingArray {
public:
	bool checkPossibility(vector<int>& nums) {
		// Find first invalid element.
		size_t found = -1;
		size_t length = nums.size();
		for (size_t i = 0; i < length - 1; i++) {
			if (nums[i] > nums[i + 1]) {
				found = i;
				break;
			}
		}
		if (found == -1 || found == length - 2) return true;
		if (checkNonDecreasingWithSkip(nums, found) || checkNonDecreasingWithSkip(nums, found + 1)) return true;
		return false;
	}

	bool checkNonDecreasingWithSkip(vector<int>& nums, size_t skip) {
		size_t found = -1;
		size_t length = nums.size();
		for (size_t i = 0; i < length - 1; i++) {
			if (i == skip - 1) {
				if (nums[i] > nums[i + 2]) return false;
				continue;
			}
			else if (i == skip) {
				continue;
			}
			if (nums[i] > nums[i + 1]) {
				found = i;
				break;
			}
		}
		if (found == -1) return true;
		return false;
	}
};