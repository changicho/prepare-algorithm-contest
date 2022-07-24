#define _CRT_SECURE_NO_WARNINGS

#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
#define ll long long
#define INF -1e18

ll dp[35][35][35][35];

ll go(vector<int>& v1, vector<int>& v2, int v1l, int v1r, int v2l, int v2r, int K) {
	if (K < 0 || v1l >= v1.size() || v1r < 0 || v2l >= v2.size() || v2r < 0) return 0;
	ll& ret = dp[v1l][v1r][v2l][v2r];
	if (ret != -1)	return ret;
	ret = 0;
	ret = max(go(v1, v2, v1l + 1, v1r, v2l, v2r, K-1) + v1[v1l], go(v1, v2, v1l, v1r - 1, v2l, v2r, K - 1) + v1[v1r]);
	ret = max(ret, go(v1, v2, v1l, v1r, v2l + 1, v2r, K - 1) + v2[v2l]);
	ret = max(ret, go(v1, v2, v1l, v1r, v2l, v2r - 1, K - 1) + v2[v2r]);
	return ret;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t, n, m,k;
	cin >> t;
	for (int tc = 1; tc <= t; tc++) {
		cin >> n;
		vector<int> v1(n);
		for (int i = 0; i < n; i++)	cin >> v1[i];
		cin >> m;
		vector<int> v2(m);
		for (int i = 0; i < m; i++)	cin >> v2[i];
		cin >> k;
		memset(dp, -1, sizeof(dp));
		dp[1][0][0][0] = v1[0], dp[0][k - 1][0][0] = v1[n - 1], dp[0][0][1][0] = v2[0], dp[0][0][0][k - 1] = v2[m - 1];
		ll ans = go(v1, v2, 0, n - 1, 0, m - 1, k);
		cout << "Case #" << tc << ": " << ans << '\n';
	}
}
