#define _CRT_SECURE_NO_WARNINGS

#include <vector>
#include <iostream>
#include <string>
#include <algorithm>
#include <numeric>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <stack>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n, t;
	cin >> n >> t;
	vector<int> v(t + 1);
	for (int i = 1; i <= t; i++) cin >> v[i];
	int l = 1, r = t;
	int ans = 1e9;
	while (l <= r) {
		int m = (l + r) / 2;
		unordered_map<int, int> row, col;
		unordered_set<int> diag;
		bool isBingo = 0;
		for (int i = 1; i <= m; i++) {
			int curRow = (v[i]-1) / n;
			int curCol = (v[i]-1) % n;
			row[curRow]++;
			col[curCol]++;
			diag.insert(v[i]);
		}
		for (auto j : row)	if (j.second >= n) isBingo = 1;
		for (auto j : col)	if (j.second >= n) isBingo = 1;
		bool isDiagBingo = 1;
		for (int j = 1; j <= n * n; j += n+1) {
			if (diag.find(j) == diag.end())	isDiagBingo = 0;
		}
		if (isDiagBingo)	isBingo = 1;
		isDiagBingo = 1;
		for (int j = n; j <= n * (n-1)+1; j += n - 1) {
			if (diag.find(j) == diag.end())	isDiagBingo = 0;
		}
		if (isDiagBingo)	isBingo = 1;
		if (isBingo) {
			ans = min(ans, m);
			r = m - 1;
		}
		else l = m + 1;
	}
	if (ans == 1e9)	cout << -1;
	else cout << ans;
	return 0;
}

/*
	2차원 배열 v가 주어진다.
	길이가 t인 배열 a[i] = 표시되는 v.
	처음으로 빙고가 되는 i를 찾아라.

	이분탐색으로 최소 t를 찾는다.
	빙고는 1. 가로 2. 세로 3. 대각선의 경우가 존재한다.
	입력된 값을 통해 몇 번째 col, row인지 알 수 있다.
	해시테이블로 이 값들을 저장하고, 그 값이 n보다 크면 1 or 2의 조건을 만족한다.
	3의 경우 2개의 경우밖에 없다. 

	O(logT*T) / O(T)
*/
