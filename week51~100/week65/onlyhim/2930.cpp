#define MOD 1000000007
#define L 1
#define T 8
#define E 2
#define EE 4
#define LEET 15

long long go(vector<vector<long long>>& dp, int cur, int mask) {
    if (cur < 0) {
        return mask == LEET;
    }
    long long& ret = dp[cur][mask];
    if (ret != -1)  return ret;
    ret = 0;
    ret = (ret + go(dp, cur - 1, mask | L)) % MOD;
    ret = (ret + go(dp, cur - 1, mask | T)) % MOD;
    if ((mask & E) == E)    ret = (ret + go(dp, cur - 1, mask | EE)) % MOD;
    else ret = (ret + go(dp, cur - 1, mask | E))%MOD;
    ret = (ret + (23 * go(dp, cur - 1, mask)%MOD))%MOD;
    return ret;
}

class Solution {
public:
    int stringCount(int n) {
        if (n < 4)    return 0;
        if (n == 4)   return 12;
        vector<vector<long long>> dp(n, vector<long long>(16, -1));
        return go(dp, n-1, 0);
    }
};

/*
dp[i][j] = 현재 인덱스가 i이고 mask값이 j일때 경우의 수
j=1; l이 1개 등장
j=2; e가 1개 등장
j=4; e가 2개 등장
j=8; t가 1개 등장
따라서, 인덱스가 n이고 j=15일때 leet가 모두 등장했으므로 경우의 수가 1개 추가
점화식은 dp[i][j] = dp[i+1][j | 1] + dp[i+1][j | 8] + (j&2 == 2 ? dp[i][j | 4] : dp[i][j | 2])
O(n) / O(n)

*/
