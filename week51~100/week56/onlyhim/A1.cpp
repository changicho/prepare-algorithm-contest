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
	int t, n, k;
	cin >> t;
	for (int i = 1; i <= t; i++) {
		cin >> n >> k;
		vector<int> a(n);
		vector<int> b(n);
		int aidx, bidx;
		for (int i = 0; i < n; i++) {
			cin >> a[i];
			if (a[i] == 1)	aidx = i;
		}
		for (int i = 0; i < n; i++) {
			cin >> b[i];
			if (b[i] == 1)	bidx = i;
		}
		bool isFind = 1;
		if ((k == 0 && aidx != bidx) || (k == 1 && aidx == bidx))	isFind = 0;
		if (n == 2) {
			if ((k % 2 == 0 && aidx != bidx) || (k % 2 == 1 && aidx == bidx))	isFind = 0;
		}
		for (int i = 0; i < n && isFind; i++) {
			if (a[aidx] != b[bidx])	isFind = 0;
			aidx = (aidx + 1) % n;
			bidx = (bidx + 1) % n;
		}
		string ss = isFind ? "YES" : "NO";
		cout << "Case #" << i << ": " << ss << '\n';
	}
}

/*
1~N으로 이루어진 카드 더미 A,B가 주어진다.
카드 더미에서 A[i]~A[j](i<=j)를 정확히 K번 옮겨서 B를 만들 수 있는지 계산해라.

K=0일때, A!=B이면 false, K=1일때, A==B이면 false -> 29 lines
K>=2일때, B가 A의 rotation이면 true -> 33~36 lines
예외: N=2일때, (1,2) -> (2,1) -> (1,2) ... 이므로 k의 even / odd에 따라 처리 -> 29 lines
*/
