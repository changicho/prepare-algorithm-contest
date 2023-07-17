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


/*
dp[i][j] = 현재 위치가 i이고 상태가 j일 때의 longest subarray
j=0 -> 선택한적이 없음, j=1 -> nums1을 선택함 j=2 -> nums2를 선택함
subarray이므로 이전에 선택한 경험이 있으면 반드시 sequential하게 진행되어야 한다 (Line 13~19)
이전에 선택한 적이 없으면 1) 다음 nums도 선택하지 않거나 2) nums1를 선택하거나 3) nums2를 선택할 수 있다 (Linke 8~11)
*/
