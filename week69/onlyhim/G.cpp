#include <bits/stdc++.h>
#include <atcoder/string>
using namespace std;
using namespace atcoder;
// Does s contain t as a substring?
bool contains(const string &s, const string &t) {
	int n = s.size(), m = t.size();
	vector<int> za = z_algorithm(t + s);
	for (int i = m; i <= n; i++) {
		if (za[i] >= m) return true;
	}
	return false;
}
int main() {
	int n;
	cin >> n;
	vector<string> s(n);
	for (int i = 0; i < n; i++) cin >> s[i];
	for (auto it = s.begin(); it < s.end();) {
		bool flag = false;
		for (auto jt = s.begin(); jt < s.end(); jt++) {
			if (jt != it) flag |= contains(*jt, *it);
		}
		if (flag) it = s.erase(it);
		else ++it;
	}
	n = s.size();
	vector d(n, vector<int>(n));
	for (int i = 0; i < n; i++) {
		string now = s[i];
		for (int j = 0; j < n; j++) {
			if (j != i) now += s[j];
		}
		vector<int> za = z_algorithm(now);
		int cur = s[i].size();
		for (int j = 0; j < n; j++) {
			if (j == i) continue;
			d[j][i] = s[i].size();
			for (int k = 0; k < s[j].size(); k++) {
				if (za[cur + k] >= s[j].size() - k) {
					d[j][i] = k + s[i].size() - s[j].size();
					break;
				}
			}
			cur += s[j].size();
		}
	}
	vector dp(1 << n, vector<int>(n, 1 << 30));
	for (int i = 0; i < n; i++) dp[1 << i][i] = s[i].size();
	for (int bit = 1; bit < (1 << n) - 1; bit++) {
		for (int i = 0; i < n; i++) {
			if (~bit >> i & 1) continue;
			for (int j = 0; j < n; j++) {
				if (bit >> j & 1) continue;
				dp[bit | 1 << j][j] = min(dp[bit | 1 << j][j], dp[bit][i] + d[i][j]);
			}
		}
	}
	cout << *min_element(dp.back().begin(), dp.back().end()) << endl;
}


/*
	n개의 문자열이 주어진다. 각각의 문자열은 s[i]라 하자.
	이 모든 문자열을 substring으로 가지는 문자열을 t라 할 때, t의 최소 길이를 계산해라.
	s[0] = snuke, s[1] = kensho, s[2] = uk. t = 9 (snukensho)
	n <= 20, s[i] <= 10^5

	1. 중복 문자열 제거
	2. d[x][y] = s[y]의 prefix와 s[x]의 suffix중 일치하는 문자의 최대 갯수 -> KMP or Z-algorithm
	3. dp[i][j] = 현재 포함된 문자열의 상태가 i이고 (bitmask), j번째 문자를 합성할 때의 최소값

*/
