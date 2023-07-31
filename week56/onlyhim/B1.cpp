#define _CRT_SECURE_NO_WARNINGS

#include <vector>
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

const int MOD = 1000000007;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t, numTree, numWell, x, y;
	cin >> t;
	for (int i = 1; i <= t; i++) {
		vector<int> numTreeXaxis(3005, 0);
		vector<int> numTreeYaxis(3005, 0);
		cin >> numTree;
		for (int j = 0; j < numTree; j++) {
			cin >> x >> y;
			numTreeXaxis[x]++;
			numTreeYaxis[y]++;
		}
		cin >> numWell;
		int ans = 0;
		int wellXPos, wellYPos;
		for (int j = 0; j < numWell; j++) {
			cin >> wellXPos >> wellYPos;
			for (int k = 0; k <= 3000; k++) {
				int xVal = abs(wellXPos - k) * abs(wellXPos - k);
				int yVal = abs(wellYPos - k) * abs(wellYPos - k);
				ans = (ans + (xVal * numTreeXaxis[k]) % MOD) % MOD;
				ans = (ans + (yVal * numTreeYaxis[k]) % MOD) % MOD;
			}
		}
		cout << "Case #" << i << ": " << ans << '\n';
	}
	return 0;
}
