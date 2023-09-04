#include <iostream>
#include <vector>
using namespace std;

#define MOD 1000000007

int calcAll(vector<int>& dp, int n) {
	if (n < 0)	return 0;
	if (n == 0)	return 1;
	int& ret = dp[n];
	if (ret != -1)	return ret;
	ret = 0;
	ret = ((calcAll(dp, n - 1) + calcAll(dp, n - 2)) % MOD);
	return ret;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int tc, n;
	cin >> tc;
	while (tc--) {
		cin >> n;
		vector<int> dp(n+1, -1);
		dp[0] = 1;
		calcAll(dp, n);
		int numAll = dp[n];
		int numAsync;
		if (n % 2)	numAsync = dp[n / 2];
		else numAsync = (dp[n / 2] + dp[n / 2 - 1]) % MOD;
		int ret = (numAll - numAsync + MOD) % MOD;
		cout<<ret<<endl;
	}
	return 0;
}
