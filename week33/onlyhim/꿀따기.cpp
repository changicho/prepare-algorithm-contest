#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	vector<int> v(n);
	for (int i = 0; i < n; i++)	cin >> v[i];
	vector<int> sums(n);
	sums[0] = v[0];
	for (int i = 1; i < n; i++)	sums[i] = sums[i - 1] + v[i];
	int ans = 0;
	// bee - basket - bee
	for (int i = 1; i < n - 1; i++) {
		ans = max(ans, sums[i] - v[0] + (sums[n - 1] - sums[i-1] - v[n-1]));
	}
	// bee - bee - basket
	for (int i = 1; i < n; i++) {
		ans = max(ans, sums[n - 1] - v[i] - v[0] + sums[n - 1] - sums[i]);
	}
	// basket - bee - bee
	for (int i = 1; i < n - 1; i++) {
		ans = max(ans, sums[i] - v[i] + sums[n - 1] - v[i] - v[n - 1]);
	}
	cout << ans;
	return 0;
}
