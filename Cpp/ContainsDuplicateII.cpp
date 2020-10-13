// https://leetcode.com/problems/contains-duplicate-ii/
// 219. Contains Duplicate II
// Easy

#include <vector>
#include <unordered_set>
using namespace std;

class ContainsDuplicateII {
public:
	bool containsNearbyDuplicate(vector<int>& nums, int k) {
		if (k <= 0) return false;
		unordered_set<int> s;
		for (size_t i = 0; i < nums.size(); i++) {
			int element = nums[i];
			if (s.find(element) == s.end()) {
				s.insert(element);
			}
			else {
				return true;
			}
			if (s.size() > k) {
				s.erase(nums[i - k]);
			}
		}
		return false;
	}
};