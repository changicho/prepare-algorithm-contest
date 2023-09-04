#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <algorithm>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin >> t;
	while (t--) {
		int n, x1, y1, x2, y2;
		cin >> n >> x1 >> y1 >> x2 >> y2;
		int l1 = min(min(x1, n - x1 + 1), min(y1, n - y1 + 1));
		int l2 = min(min(x2, n - x2 + 1), min(y2, n - y2 + 1));
		cout << abs(l1 - l2) << '\n';
	}
	return 0;
}
