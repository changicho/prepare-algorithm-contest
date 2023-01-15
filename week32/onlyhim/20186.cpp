#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, k;
	cin >> n >> k;
	vector<int> v(n);
	for (int i = 0; i < n; i++) cin >> v[i];
	sort(v.begin(), v.end());
	int idx = v.size() - 1;
	int ans = 0, cnt = 0;
	while (k) {
		ans += v[idx] - cnt;
		k--;
		cnt++;
		idx--;
	}
	cout << ans;
	return 0;
}
