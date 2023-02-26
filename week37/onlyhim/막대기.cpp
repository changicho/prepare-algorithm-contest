#include <iostream>
#include <vector>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, ans = 1, curMins;
	cin >> n;
	vector<int> v(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i];
		if (i == n - 1)	curMins = v[i];
	}
	for (int i = n - 2; i >= 0; i--) {
		if (v[i] > curMins) {
			ans++;
			curMins = v[i];
		}
	}
	cout << ans;
}
