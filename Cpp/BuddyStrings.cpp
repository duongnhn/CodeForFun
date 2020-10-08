// https://leetcode.com/problems/buddy-strings/
// 859. Buddy Strings
// Easy

#include <string>
#include <unordered_set>
using namespace std;

class BuddyStrings {
public:
  bool buddyStrings(string A, string B) {
    int n = A.length();
    if (n != B.length()) return false;
    int countDifferences = 0;
    int indexDifferences[3];
    for (int i = 0; i < n; i++) {
      if (A[i] != B[i]) {
        countDifferences++;
        indexDifferences[countDifferences - 1] = i;
      }
      if (countDifferences > 2) return false;
    }
    if (countDifferences == 1) return false;
    if (countDifferences == 2) {
      int i1 = indexDifferences[0];
      int i2 = indexDifferences[1];
      if (A[i1] == B[i2] && A[i2] == B[i1]) return true;
      return false;
    }
    // Two strings are identical but swap "aa" still itself.
    unordered_set<char> setOfChars;
    for (int i = 0; i < n; i++) {
      if (setOfChars.find(A[i]) != setOfChars.end()) {
        return true;
      }
      setOfChars.insert(A[i]);
    }
    return false;
  }
};