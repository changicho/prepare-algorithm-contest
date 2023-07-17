class Solution {
public:
	int maximumJumps(vector<int>& v, int k) {
		int n = v.size();
		vector<int> dp(n, 0);
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < i; j++) {
				if (abs(v[i] - v[j]) <= k) {
					if (j == 0 || (j!= 0 && dp[j] != 0))
					dp[i] = max(dp[i], dp[j] + 1);
				}
			}
		}
		return dp[n-1] == 0 ? -1 : dp[n-1];
	}
};


/*
dp[i] = 현재 위치가 i일 때 최소 jump 값
dp[] = {1, 0, 2, 1}
dp[1]은 갱신된 적이 없으므로 이용할 수 없다.
*/
