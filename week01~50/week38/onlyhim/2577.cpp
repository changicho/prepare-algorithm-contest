int n, m;
int goy[4] = { 1, -1, 0, 0 };
int gox[4] = { 0,0,1, -1 };

bool judge(int y, int x) {
	return y >= 0 && x >= 0 && y < n && x < m;
}

struct cmp {
	bool operator()(vector<int>& a, vector<int>& b) {
		return a[0] > b[0];
	}
};

class Solution {
public:
	int minimumTime(vector<vector<int>>& v) {
		if (v[0][1] > 1 && v[1][0] > 1)	return -1;
		n = v.size(), m = v[0].size();
		vector<vector<int>> visit(n, vector<int>(m, 1e9));
		priority_queue<vector<int>, vector<vector<int>>, cmp> pq;
		pq.push({ 0, 0, 0 });
		visit[0][0] = 0;
		while (!pq.empty()) {
			vector<int> cur = pq.top();
			pq.pop();
			int curcost = cur[0], cury = cur[1], curx = cur[2];
			if (cury == n - 1 && curx == m - 1)	
				return curcost;
			for (int i = 0; i < 4; i++) {
				int ny = cury + goy[i], nx = curx + gox[i];
				if (judge(ny, nx) && visit[ny][nx] > curcost + 1) {
					if (v[ny][nx] > curcost + 1) {
						int dif = v[ny][nx] - curcost;
						if (dif % 2 == 0) {
							visit[ny][nx] = v[ny][nx] + 1;
						}
						else {
							visit[ny][nx] = v[ny][nx];
						}
					}
					else {
						visit[ny][nx] = curcost+1;
					}
					pq.push({ visit[ny][nx], ny, nx });
				}
			}
		}
		return -1;
	}
};
