#define _CRT_SECURE_NO_WARNINGS

#include <vector>
#include <iostream>
#include <algorithm>
#include <iomanip>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t,n,m;
	cin >> t;
	for (int j =1; j<=t; j++){
		cin >> n >> m;
		vector<int> v(n);
		for (int i = 0; i < n; i++)	cin >> v[i];
		sort(v.begin(), v.end());
		double ans = 0;
		int idx = n - 1;
		while (m) {
			if (m == 1) {
				vector<int> vv;
				for (int i = idx; i >= 0; i--)	vv.push_back(v[i]);
				if (vv.size() % 2)	ans += vv[vv.size() / 2];
				else {
					ans += (double)(vv[vv.size() / 2 - 1] + vv[vv.size() / 2])/2;
				}
			}
			else ans += v[idx--];
			m--;
		}
		cout << "Case #" << j << ": " << fixed<<setprecision(10) <<ans << '\n';
	}
}
