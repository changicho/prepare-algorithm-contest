#include <vector>
#include <algorithm>
using namespace std;

long long Count(vector<int>& v, int val) {
    long long ans = 0;
    for (int l = 0, r = v.size() - 1; l < r; l++) {
        while (l < r && v[l] + v[r] > val)  r--;
        ans += r - l;
    }
    return ans;
}

class Solution {
public:
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        sort(nums.begin(), nums.end());
        return Count(nums, upper) - Count(nums, lower - 1);
    }
};
