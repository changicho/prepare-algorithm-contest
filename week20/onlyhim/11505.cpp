#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;
#define INF 1e9+7
#define ull unsigned long long
#define MID (S+E)/2
const int MAX = 1e6 + 7;
const int MOD = 1e9 + 7;
int seg[MAX * 4 + 7+MAX];
ull update(int pos, int idx, int val, int S, int E) {
	if (idx < S || idx > E)	return seg[pos];
	if (S == E)	return seg[pos] = val;
	return seg[pos] = (update(pos * 2, idx, val, S, MID)* update(pos * 2 + 1, idx, val, MID + 1, E)) % MOD;
}
ull query(int pos, int S, int E, int left, int right) {
	if (E<left || S>right)	return 1;
	if (left <= S && right >= E)	return seg[pos];
	return (query(pos * 2, S, MID, left, right) % MOD * query(pos * 2 + 1, MID + 1, E, left, right) % MOD) % MOD;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	fill(seg, seg + MAX * 4 + 7, 1);
	int n, m, k, a,b,c;
	cin >> n >> m >> k;
	for (int i = 1; i <= n; i++) {
		cin >> a;
		update(1, i, a, 1, n);
	}
	for (int i = 1; i <= m + k; i++) {
		cin >> a >> b >> c;
		if (a == 1) update(1, b, c, 1, n);
		else cout << query(1, 1, n, b, c) << '\n'; 
	}
}
