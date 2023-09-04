#include <algorithm>
#include <iostream>
#include <queue>
#include <string>
#include <vector>

using namespace std;

class Solution {
 private:
  long long getCaseCount(int size) {
    if (size < 1) return 0;
    return (long long)size * (size + 1) / 2;
  }

 public:
  long long countSubarrays(vector<int>& nums, long long k) {
    int size = nums.size();
    // sliding window
    // size is i, count is
    // 1 : 1
    // 2 : 3 (2 + 1)
    // 3 : 3 + 2 + 1
    // 4 : 4 + 3 + 2 + 1

    // getCase(num) = num * (num + 1) / 2

    long long ret = 0;
    queue<int> q;
    long long sum = 0;

    vector<int> sizes;
    for (int i = 0; i < size; i++) {
      q.push(nums[i]);
      sum += nums[i];

      while (sum * q.size() >= k && !q.empty()) {
        sum -= q.front();
        q.pop();
      }

      sizes.push_back(q.size());
    }

    ret += getCaseCount(sizes[0]);
    for (int i = 1; i < sizes.size(); i++) {
      if (sizes[i - 1] < sizes[i]) {
        ret -= getCaseCount(sizes[i - 1]);
      } else {
        ret -= getCaseCount(sizes[i] - 1);
      }
      ret += getCaseCount(sizes[i]);
    }
    return ret;
  }
};