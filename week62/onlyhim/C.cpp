#define _CRT_SECURE_NO_WARNINGS

#include <vector>
#include <iostream>
#include <string>
#include <algorithm>
#include <numeric>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t, n;
	cin >> t;
	for (int i = 1; i <= t; i++) {
		cin >> n;
		vector<vector<char>> v(n, vector<char>(n));
		for (int i = 0; i < n; i++)	for (int j = 0; j < n; j++)	cin >> v[i][j];
		int ans = 0;
		for (int i = 0; i < n/2; i++) {
			for (int j = i; j < n-1-i; j++) {
				char a = v[i][j];
				char b = v[j][n - 1-i];
				char c = v[n - 1-i][n - 1 - j];
				char d = v[n - 1 - j][i];
				char maxVal = max(a, max(b, max(c, d)));
				ans += maxVal - a;
				ans += maxVal - b;
				ans += maxVal - c;
				ans += maxVal - d;
			}
		}
		cout << ans << '\n';
	}
	return 0;
}
