#define _CRT_SECURE_NO_WARNINGS

#include <vector>
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t, r, c, a, b;
	cin >> t;
	for (int i = 1; i <= t; i++) {
		cin >> r >> c>>a>>b;
		string ss = (r + c - 1 <= a && r + c - 1 <= b) ? "Possible" : "Impossible";
		cout << "Case #" << i << ": " << ss << '\n';
		int cost, lastCost;
		if (ss == "Possible") {
			vector<vector<int>> v(r, vector<int>(c, 1));
			int costA = a - r - (c - 2);
			int costB = b - r - (c - 2);
			v[0][0] = costA, v[r-1][0] = costB;

			for (int i = 0; i < r; i++) {
				for (int j = 0; j < c; j++) {
					cout << v[i][j] << ' ';
				}
				cout << '\n';
			}
		}
	}
}
