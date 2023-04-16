#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {
        vector<int> v(201, 0);
        int n = 0;
        for (int i = 0; i < nums.size(); i++) {
            v[nums[i]]++;
            n = max(n, v[nums[i]]);
        }
        vector<vector<int>> ans(n);
        for (int i = 0; i < v.size(); i++) {
            if (v[i] == 0)  continue;
            int k = v[i];
            for (int j = 0; j < k; j++) {
                ans[j].push_back(i);
            }
        }
        return ans;
    }
};
