// https://leetcode.com/problems/reverse-words-in-a-string/
// 151. Reverse Words in a String
// Medium

#include <string>
#include <sstream>
using namespace std;

class ReverseWordsInAString {
public:
  string reverseWords(string s) {
    reverse(s);
    int start = 0; int end = 0;
    while (start < s.length()) {
      // Find first non-space characters.
      if (s[start] == ' ') {
        start++;
        continue;
      }
      // Find word and reverse.
      end = start+1;
      while (end < s.length() && s[end] != ' ') {
        end++;
      }
      // Reverse a word.
      reverse(s, start, end-1);
      start = end;
    }
    // Trim non-space characters.
    start = 0;
     while (start < s.length() && s[start] == ' ') {
      start++;
    }
    stringstream ss;
    end = s.length() - 1;
    while (end >= start && s[end] == ' ') {
      end--;
    }
    bool previous_is_space = false;
    while (start <= end) {
      if (!previous_is_space || s[start] != ' ') {
        ss << s[start];
      }
      previous_is_space = s[start] == ' ';
      start++;
    }
    return ss.str();
  }

  void reverse(string& s) {
    reverse(s, 0, s.length()-1);
  }

  void reverse(string& s, int start, int end) {
    if (start < 0 || end >= s.length()) return;
    int i = start;
    int j = end;
    while (i < j) {
      swap(s[i], s[j]);
      i++;
      j--;
    }
  }
};