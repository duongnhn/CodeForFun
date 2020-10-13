// https://leetcode.com/problems/contains-duplicate-iii/
// 220. Contains Duplicate III
// Medium

#include <vector>
#include <set>
using namespace std;

class ContainsDuplicateIII {
public:
	bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
		if (k <= 0) return false;
		set<int> s;
		const int MIN = -2147483648;
		const int MAX = 2147483647;
		for (size_t i = 0; i < nums.size(); i++) {
			int element = nums[i];
			long long lower_bound = element;
			lower_bound -= t;
			if (lower_bound < MIN) lower_bound = MIN;
			set<int>::iterator lower = s.lower_bound(lower_bound);
			if (lower != s.end()) {
				long long current = *lower;
				current -= element;
				if (abs(current) <= t) return true;
				lower++;
				if (lower != s.end()) {
					long long current = *lower;
					current -= element;
					if (abs(current) <= t) return true;
				}
			}
			s.insert(element);
			if (s.size() > k) {
				s.erase(nums[i - k]);
			}
		}
		return false;
	}
};