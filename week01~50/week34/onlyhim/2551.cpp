#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    long long putMarbles(vector<int>& weights, int k) {
        int n = weights.size();
        if (k == 0 || k == n) return 0;
        vector<int> v;
        for (int i = 0; i < n - 1; i++) {
            v.push_back(weights[i] + weights[i + 1]);
        }
        sort(v.begin(), v.end());
        n = v.size();
        long long ans = 0;
        int lidx = 0, ridx = n - 1, copyK = k-1;
        while (copyK) {
            ans += v[ridx] - v[lidx];
            ridx--, lidx++;
            copyK--;
        }
        return ans;
    }
};
