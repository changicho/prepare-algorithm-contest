#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <algorithm>

using namespace std;

int goy[4] = { 1, -1, 0, 0 };
int gox[4] = { 0,0,1, -1 };

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int ans = 0;
	int n, m;
	cin >> n >> m;
	vector<vector<int>> v(n, vector<int>(m));
	vector<vector<bool>> visit(n, vector<bool>(m, 0));
	for (int i = 0; i < n; i++)	for (int j = 0; j < m; j++)	cin >> v[i][j];
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (visit[i][j] == 0 && v[i][j] != 1) {
				visit[i][j] = 1;
				int score = 0;
				queue<vector<int>> q;
				q.push({ i, j, v[i][j] == 0 ? 1 : -2 });
				while (!q.empty()) {
					int qsz = q.size();
					while (qsz--) {
						vector<int> cur = q.front();
						q.pop();
						int curY = cur[0], curX = cur[1], cost = cur[2];
						score += cost;
						for (int i = 0; i < 4; i++) {
							int nextY = curY + goy[i], nextX = curX + gox[i];
							if (nextY >= 0 && nextY < n && nextX >= 0 && nextX < m && visit[nextY][nextX] == 0 && v[nextY][nextX] != 1) {
								visit[nextY][nextX] = 1;
								q.push({ nextY, nextX, v[nextY][nextX] == 0 ? 1 : -2 });
							}
						}
					}
				}
				ans = max(ans, score);
			}
		}
	}
	cout << ans << '\n';
}
