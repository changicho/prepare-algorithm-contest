#define _CRT_SECURE_NO_WARNINGS

#include <vector>
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t, n, k, tmp;
	cin >> t;
	for (int i = 1; i <= t; i++) {
		bool ans = 1;
		cin >> n >> k;
		vector<int> v(101, 0);
		for (int i = 0; i < n; i++) {
			cin >> tmp;
			v[tmp]++;
			if (v[tmp] > 2)	ans = 0;
		}
		if (n > k * 2)	ans = 0;
		string ss = ans == 1 ? "YES" : "NO";
		cout << "Case #" << i << ": " << ss << '\n';
	}
}

/*
입력으로 주어지는 배열 S[i]의 원소를 2개의 배열(x[i], y[i])중 1개로 할당 한다. 단, 각 배열에 최대 k개만 할당 가능하다.
1) x와 y에 중복되는 값이 없으며 2) S[i]를 모든 x,y에 할당 가능한가?
O(N) / O(1)
*/
