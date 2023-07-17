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
