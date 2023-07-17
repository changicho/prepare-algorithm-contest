int n;

int go(vector<int>& v1, vector<int>& v2, vector<vector<int>>& dp, int cur, int stat) {
    if (cur > n - 1) return 0;
    int& ret = dp[cur][stat];
    if (ret != -1)  return ret;
    ret = 0;
    if (stat == 0) {
        ret = max(ret, go(v1, v2, dp, cur + 1, 0));
        ret = max(ret, go(v1, v2, dp, cur + 1, 1) + 1);
        ret = max(ret, go(v1, v2, dp, cur + 1, 2) + 1);
    }
    else if (stat == 1) {
        if (v1[cur-1] <= v1[cur])   ret = max(ret, go(v1, v2, dp, cur + 1, 1) + 1);
        if (v1[cur-1] <= v2[cur])   ret = max(ret, go(v1, v2, dp, cur + 1, 2) + 1);
    }
    else if (stat == 2) {
        if (v2[cur-1] <= v1[cur])   ret = max(ret, go(v1, v2, dp, cur + 1, 1) + 1);
        if (v2[cur-1] <= v2[cur])   ret = max(ret, go(v1, v2, dp, cur + 1, 2) + 1);
    }
    return ret;
}

class Solution {
public:
    int maxNonDecreasingLength(vector<int>& v1, vector<int>& v2) {
        n = v1.size();
        vector<vector<int>> dp(n, vector<int>(4, -1));
        return go(v1, v2, dp, 0, 0);
    }
};
