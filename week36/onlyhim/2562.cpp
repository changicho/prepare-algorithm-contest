#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    long long findTheArrayConcVal(vector<int>& nums) {
        long long ans = 0;
        int l = 0, r = nums.size() - 1;
        while (l <= r) {
            if (l == r) {
                ans += nums[l];
                break;
            }
            string str = to_string(nums[l]) + to_string(nums[r]);
            ans += stoi(str);
            l++, r--;
        }
        return ans;
    }
};
