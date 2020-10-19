// https://leetcode.com/problems/top-k-frequent-elements/
// 347. Top K Frequent Elements
// Medium

#include <vector>
#include <map>
#include <unordered_map>
using namespace std;

class Solution {
public:
  vector<int> topKFrequent(vector<int>& nums, int k) {
    unordered_map<int, int> elements_count_map;
    for (auto ch : nums) {
      auto it = elements_count_map.find(ch);
      if (it == elements_count_map.end()) {
        elements_count_map.insert({ ch, 1 });
      }
      else {
        it->second++;
      }
    }
    map<int, vector<int>> count_elements_map;
    auto it = elements_count_map.begin();
    while (it != elements_count_map.end()) {
      int ch = it->first;
      int count = it->second;
      auto it_temp = count_elements_map.find(count);
      if (it_temp == count_elements_map.end()) {
        vector<int> v = { ch };
        count_elements_map.insert({ count, v });
      }
      else {
        it_temp->second.push_back(ch);
      }
      it++;
    }
    // Create vector out.
    vector<int> out;
    auto it_result = count_elements_map.rbegin();
    while (it_result != count_elements_map.rend()) {
      int count = it_result->first;
      vector<int> v = it_result->second;
      for (int ch : v) {
        out.push_back(ch);
        if (out.size() == k) return out;
      }
      it_result++;
    }
    return out;
  }
};