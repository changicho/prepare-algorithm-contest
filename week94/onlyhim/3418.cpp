int n, m;
int dp[505][505][3];

int go(vector<vector<int>>& v, int y, int x, int neu) {
    if (y == n - 1 && x == m - 1) {
        if (v[y][x] < 0 && neu > 0) return 0;
        else return v[y][x];
    }
    if (y >= n || x >= m)   return -1e9;
    int& ret = dp[y][x][neu];
    if (ret != -1)    return ret;

    ret = v[y][x] + max(go(v, y + 1, x, neu), go(v, y, x + 1, neu));
    if (neu > 0 && v[y][x] < 0) {
        ret = max(ret, go(v, y + 1, x, neu - 1));
        ret = max(ret, go(v, y, x + 1, neu - 1));
    }
    return ret;
    
}

class Solution {
public:
    int maximumAmount(vector<vector<int>>& coins) {
        n = coins.size(), m = coins[0].size();
        for (int i = 0; i < n; i++) for (int j = 0; j < m;j++)  for (int k = 0; k < 3; k++) dp[i][j][k] = -1;
        return go(coins, 0, 0, 2);
    }
};
