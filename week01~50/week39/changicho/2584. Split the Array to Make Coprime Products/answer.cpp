#include <algorithm>
#include <climits>
#include <cmath>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

class Solution {
 private:
  vector<int> factorize(int num) {
    vector<int> res;
    for (int divider = 2; num > 1 && divider < 1000; divider += 1 + (divider % 2)) {
      if (num % divider == 0) {
        res.push_back(divider);

        while (num % divider == 0) {
          num /= divider;
        }
      }
    }

    if (num > 1) res.push_back(num);
    return res;
  }

 public:
  int findValidSplit(vector<int>& nums) {
    int size = nums.size();

    unordered_map<int, int> left, right;

    for (int num : nums) {
      for (int factor : factorize(num)) {
        right[factor]++;
      }
    }

    for (int i = 0, common = 0; i < size - 1; i++) {
      int num = nums[i];

      for (int factor : factorize(num)) {
        common += (left[factor]++ == 0) - (left[factor] == right[factor]);
      }

      if (common == 0) return i;
    }

    return -1;
  }
};