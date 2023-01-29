#include <iostream>
#include <vector>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	vector<int> psum(n, 0);
	long long ans = 0;
	for (int i = 0; i < n; i++) {
		cin >> psum[i];
		if (i != 0)	psum[i] += psum[i - 1];
	}
	if (psum[n - 1] % 4 == 0){
		if (psum[n - 1] == 0) {
			long long numOfpsumZero = 0;
			for (int i = 0; i < n; i++)	numOfpsumZero += psum[i] == 0;
			ans = (numOfpsumZero - 1) * (numOfpsumZero - 2) * (numOfpsumZero - 3) / 6;
		}
		else {
			int k = psum[n - 1] / 4;
			vector<long long> dp(5, 0);
			dp[0] = 1;
			for (int i = 0; i < n; i++) {
				int curK = psum[i] / k;
				if (curK < 1 || curK > 4 || psum[i] % k != 0)	continue;
				dp[curK] += dp[curK - 1];
			} 
			ans = dp[4];
		}
	}
	cout << ans;
}
