// https://leetcode.com/problems/contains-duplicate/
// 217. Contains Duplicate
// Easy

#include <vector>
#include <unordered_set>
using namespace std;

class ContainsDuplicate {
public:
	bool containsDuplicate(vector<int>& nums) {
		unordered_set<int> s;
		for (int element : nums) {
			if (s.find(element) == s.end()) {
				s.insert(element);
			}
			else {
				return true;
			}
		}
		return false;
	}
};