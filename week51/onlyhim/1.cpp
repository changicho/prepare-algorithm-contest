#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <algorithm>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, v, w;
	cin >> n;
	unordered_map<int, pair<int, int>> um;
	for (int i = 1; i <= n; i++) {
		cin >> v >> w;
		if (um.find(v) == um.end())	um[v] = { w, i };
		else {
			if ((um[v].first == w && i > um[v].second) || um[v].first < w) {
				um[v] = { w,i };
			}
		}
	}
	long long ans = 0;
	for (auto it : um)	ans += it.second.second;
	cout << ans << '\n';
}
