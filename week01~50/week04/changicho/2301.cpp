#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

class Solution {
 public:
  bool matchReplacement(string s, string sub, vector<vector<char>>& mappings) {
    unordered_map<char, unordered_set<char>> table;
    for (vector<char>& mapping : mappings) {
      table[mapping.back()].insert(mapping.front());
    }

    int length = s.length();
    for (int i = 0; i <= length - sub.length(); i++) {
      if (s[i] == sub[0] || table[s[i]].count(sub[0])) {
        bool flag = true;
        for (int j = 0; j < sub.length(); j++) {
          if (s[i + j] == sub[j] || table[s[i + j]].count(sub[j])) {
            continue;
          }
          flag = false;
          break;
        }

        if (flag) return true;
      }
    }
    return false;
  }
};