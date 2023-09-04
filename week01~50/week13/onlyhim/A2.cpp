#define _CRT_SECURE_NO_WARNINGS

#include <vector>
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

#define INF 1e9

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	string s;
	int t,k;
	cin >> t;
	for (int tc = 1; tc <= t; tc++) {
		cin >> s;
		vector<vector<int>> visit(26, vector<int>(26, INF));
		cin >> k;
		for (int i = 0; i < k; i++) {
			char a, b;
			cin >> a >> b;
			visit[a - 'A'][b - 'A'] = 1;
		}

		for (int k = 0; k < 26; k++) {
			for (int i = 0; i < 26; i++) {
				for (int j = 0; j < 26; j++) {
					visit[i][j] = min(visit[i][j], visit[i][k] + visit[k][j]);
				}
			}
		}

		int ans = INF;
		for (int i = 0; i < 26; i++) {
			int cnt = 0;
			bool isCan = 1;
			for (int j = 0; j < s.size() && isCan; j++) {
				int idx = s[j] - 'A';
				if (idx == i)	continue;
				if (visit[idx][i] == INF)	isCan = 0;
				else cnt += visit[idx][i];
			}
			if (isCan) {
				ans = min(ans, cnt);
			}
		}

		if (ans == 1e9)	cout << "Case #" << tc << ": " << -1 << '\n';
		else cout << "Case #" << tc << ": " << ans << '\n';
	}
}
