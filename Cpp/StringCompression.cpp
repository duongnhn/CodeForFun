// https://leetcode.com/problems/string-compression/
// 443. String Compression
// Medium

#include <vector>
using namespace std;

class Solution {
public:
  int compress(vector<char>& chars) {
    int n = chars.size();
    if (n == 1) return 1;
    int start = 0;
    int count = 1;
    char ch = chars[0];
    for (int i=1; i<=n;i++) {
      if (i < n && chars[i] == ch) {
        count++;
      }
      if ((i == n) || chars[i] != ch) {
        // write to chars
        chars[start++] = ch;
        if (count > 1) {
          vector<int> v;
          while (count > 0) {
            v.push_back(count %10);
            count = count / 10;
          }
          for (int j = v.size() - 1; j >= 0;j--) {
            chars[start++] = v[j] + '0'; // TODO: count >= 10.
          }
        }
        if (i == n) break;        
        ch = chars[i];
        count = 1;
      }
    }
    return start;
  }
};
