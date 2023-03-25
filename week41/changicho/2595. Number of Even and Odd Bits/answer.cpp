#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

// use convert and count
// time : O(log_10(N))
// space : O(log_10(N))
class Solution {
 private:
  string convert(int n) {
    string ret = "";
    while (n > 0) {
      ret += (n % 2) + '0';
      n /= 2;
    }
    return ret;
  }

 public:
  vector<int> evenOddBit(int n) {
    string bits = convert(n);
    int size = bits.size();
    // even, odd
    vector<int> ans = {0, 0};

    for (int i = 0; i < size; i++) {
      if (bits[i] == '1') {
        ans[i % 2]++;
      }
    }
    return ans;
  }
};