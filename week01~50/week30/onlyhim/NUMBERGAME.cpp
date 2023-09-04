#include <iostream>
#include <vector>
using namespace std;

constexpr auto INF = -1e9;

int go(vector<vector<int>>& dp, vector<int>& v, int l, int r) {
	if (l > r)	return 0;
	int& ret = dp[l][r];
	if (ret != INF)	return ret;
	ret = max(ret, v[l] - go(dp, v, l + 1, r));
	ret = max(ret, v[r] - go(dp, v, l, r-1));
	if (r - l + 1 >= 2) {
		ret = max(ret, -go(dp, v, l + 2, r));
		ret = max(ret, -go(dp, v, l, r - 2));
	}
	return ret;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t, n;
	cin >> t;
	while (t--) {
		cin >> n;
		vector<int> v(n);
		for (int i = 0; i < n; i++)	cin >> v[i];
		vector<vector<int>> dp(n, vector<int>(n, INF));
		cout<<go(dp, v, 0, n - 1)<<'\n';
	}
	return 0;
}
