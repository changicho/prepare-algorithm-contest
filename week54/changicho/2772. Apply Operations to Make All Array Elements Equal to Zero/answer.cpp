#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// use sliding window
// time : O(N)
// space : O(1)
class Solution {
 public:
  bool checkArray(vector<int>& nums, int k) {
    int size = nums.size();
    int diff = 0;
    for (int i = 0; i < size; i++) {
      if (diff > nums[i]) {
        return false;
      }

      nums[i] -= diff;
      diff += nums[i];

      if (i >= k - 1) {
        diff -= nums[i - k + 1];
      }
    }

    return diff == 0;
  }
};