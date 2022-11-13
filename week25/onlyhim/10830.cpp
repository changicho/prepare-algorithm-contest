#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

typedef	vector<vector<int>> mat;

#define MOD 1000

mat calc(mat a, mat b) {
	int n = a.size();
	vector<vector<int>> ret(n, vector<int>(n));
;	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			for (int k = 0; k < n; k++) {
				ret[i][j] = (ret[i][j] + ((a[i][k] * b[k][j]) % MOD)) % MOD;
			}
		}
	}
	return ret;
}

mat go(unordered_map<long long, mat>& um, mat& v, long long b) {
	if (b == 1)	return v;
	if (um.find(b) != um.end())	return um[b];
	if (b % 2)	return um[b] = calc(go(um, v, b - 1), v);
	else return um[b] = calc(go(um, v, b/2), go(um, v, b/2));
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	unordered_map<long long, mat> um;
	int n;
	long long b;
	cin >> n >> b;
	vector<vector<int>> v(n, vector<int>(n));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> v[i][j];
		}
	}
	go(um, v, b);
	mat ans = um[b];
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << ans[i][j] << ' ';
		}
		cout << '\n';
	}
	return 0;
}
