// https://leetcode.com/problems/find-duplicate-file-in-system/
// 609. Find Duplicate File in System
// Medium

#include <vector>
#include <string>
#include <unordered_map>
using namespace std;

class Solution {
public:
  vector<vector<string>> findDuplicate(vector<string>& paths) {
    unordered_map<string/*content*/, vector<string/*"directory_path/file_name.txt"*/>> m;
    for (string str : paths) {
      // Extrace path, filename, contents.
      size_t pos1 = str.find_first_of(' ');
      string current_path = str.substr(0, pos1 - 1);
      while (pos1 < str.length()) {
        size_t pos2 = str.find_first_of('(', pos1 + 1);
        string current_filename = str.substr(pos1 + 1, pos2 - pos1);
        size_t pos3 = str.find_first_of(')', pos2 + 1);
        string current_content = str.substr(pos2 + 1, pos3 - pos2);
        string path(current_path);
        path.append("/");
        path.append(current_filename);
        auto it = m.find(current_content);
        if (it == m.end()) {
          vector<string> v = { path };
          m.insert({ current_content, v });
        }
        else {
          it->second.push_back(path);
        }
        pos1 = pos3 + 1;
      }
    }

    // return.
    vector<vector<string>> out;
    auto it = m.begin();
    while (it != m.end()) {
      vector<string>& v = it->second;
      if (v.size() > 1) {
        out.push_back(v);
      }
      it++;
    }
    return out;
  }
};
