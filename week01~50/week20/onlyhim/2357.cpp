#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <queue>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;
#define INF 1e9+7
const int MAX = 3e5 + 3;
int segT_min[MAX] = {}, segT_max[MAX] = {}, ar[MAX] = {};
int init1(int pos, int S, int E) {
	if (S == E)	return segT_min[pos] = ar[S];
	int mid = (S + E) / 2;
	return segT_min[pos] = min(init1(pos * 2, S, mid), init1(pos * 2+1, mid + 1, E));
}
int init2(int pos, int S, int E) {
	if (S == E)	return segT_max[pos] = ar[S];
	int mid = (S + E) / 2;
	return segT_max[pos] = max(init2(pos * 2, S, mid), init2(pos * 2 + 1, mid + 1, E));
}
int retmin(int pos, int S, int E, int left, int right) {
	if (left > E || right < S)	return INF;
	if (left <= S && E <= right)	return segT_min[pos];
	int mid = (S + E) / 2;
	return min(retmin(pos * 2, S, mid, left, right), retmin(pos * 2 + 1, mid + 1, E, left, right));
}
int retmax(int pos, int S, int E, int left, int right) {
	if (left > E || right < S)	return -1;
	if (left <= S && E <= right)	return segT_max[pos];
	int mid = (S + E) / 2;
	return max(retmax(pos * 2, S, mid, left, right), retmax(pos * 2 + 1, mid + 1, E, left, right));
}
int main() {
	int n, m, a, b;
	cin >> n >> m;
	fill(segT_min, segT_min + MAX, INF), fill(segT_max, segT_max + MAX, -1);
	for (int i = 1; i <= n; i++)	scanf("%d", &ar[i]);
	init1(1, 1, n), init2(1, 1, n);
	for (int i = 1; i <= m; i++) {
		scanf("%d %d", &a, &b);
		printf("%d %d\n", retmin(1, 1, n, a, b), retmax(1, 1, n, a, b));
	}
}
