#include <iostream>
#include <queue>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;
#define INF 1e9+7
const int MAX = 30;
int n, ans;
int ldiag[MAX], prevRow[MAX], rdiag[MAX];
void go(int row) {
	if (row == n) {
		ans++;
		return;
	}
	for (int i = 0; i < n; i++) {
		if (prevRow[i] || ldiag[row + i] || rdiag[row - i + n - 1]) continue;
		prevRow[i] = ldiag[row + i] = rdiag[row - i + n - 1] = 1;
		go(row + 1);
		prevRow[i] = ldiag[row + i] = rdiag[row - i + n - 1] = 0;
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n;
	go(0);
	cout << ans;
	return 0;
}
