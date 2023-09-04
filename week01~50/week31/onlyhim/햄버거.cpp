#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, k;
	cin >> n >> k;
	vector<char> v(n);
	for (int i = 0; i < n; i++) cin >> v[i];
	int ans = 0;
	for (int i = 0; i < n; i++) {
		if (v[i] == 'P') {
			bool isFind = 0;
			for (int j = max(0, i - k); j <= min(n - 1, i + k) && !isFind; j++) {
				if (v[j] == 'H') {
					isFind = 1;
					ans++;
					v[j] = 'X';
				}
			}
		}
	}
	cout << ans;
}
