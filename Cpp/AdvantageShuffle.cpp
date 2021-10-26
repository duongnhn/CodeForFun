// https://leetcode.com/problems/advantage-shuffle/
// 870. Advantage Shuffle
// Medium

#include <vector>
#include <set>
#include <map>
#include <algorithm>
using namespace std;

class Solution {
public:
  //Solution 2: only A need to be sorted.
  vector<int> advantageCount(vector<int>& A, vector<int>& B) {
    int n = A.size();
    vector<int> result(n);
    map<int, int> mapA;
    for (int i = 0; i < n; i++) {
      auto it = mapA.find(A[i]);
      if (it != mapA.end()) {
        mapA[A[i]]++;
      }
      else {
        mapA.insert({ A[i], 1 });
      }
    }
    for (int i = 0; i < n; i++) {
      int current = B[i];
      auto find = mapA.upper_bound(current);
      if (find == mapA.end()) {
        find = mapA.begin();
      }
      int a_i = find->first;
      find->second--;
      if (find->second == 0) mapA.erase(a_i);
      result[i] = a_i;
    }
    return result;
  }

  // Solution 1: sort both A and B.
  //vector<int> advantageCount(vector<int>& A, vector<int>& B) {
  //  int n = A.size();
  //  vector<int> result(n);
  //  map<int, vector<int>> mapB;
  //  for (int i = 0; i < n; i++) {
  //    auto it = mapB.find(B[i]);
  //    if (it != mapB.end()) {
  //      mapB[B[i]].push_back(i);
  //    }
  //    else {
  //      mapB.insert({ B[i], vector<int> { i } });
  //    }
  //  }
  //  sort(A.begin(), A.end());
  //  for (int i = n - 1; i >= 0; i--) {
  //    int current = A[i];
  //    auto find = mapB.lower_bound(current);
  //    if (find != mapB.begin()) find--;
  //    int b_i = find->first;
  //    vector<int> &v = find->second;
  //    int index = v[v.size() - 1];
  //    v.pop_back();
  //    if (v.empty()) mapB.erase(b_i);
  //    result[index] = A[i];
  //  }
  //  return result;
  //}
};