#define _CRT_SECURE_NO_WARNINGS

#include <vector>
#include <iostream>
#include <string>
#include <algorithm>
#include <numeric>
#include <set>
#include <cmath>
using namespace std;

bool cmp(pair<int, int>& a, pair<int, int>& b) {
	return a.first < b.first;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t;
	cin >> t;
	for (int i = 1; i <= t; i++) {
		int n, q;
		cin >> n >> q;
		vector<long long> a(n);
		vector<pair<int, int>> x(30);
		for (int i = 0; i < 30; i++) {
			x[i] = { 1e9, i };
		}
		for (int i = 0; i < n; i++)	cin >> a[i];
		int val;
		for (int i = 0; i < q; i++) {
			cin >> val;
			val--;
			x[val].first = min(i, x[val].first);
		}
		sort(x.begin(), x.end(), cmp);
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < 30; j++) {
				if (x[j].first == 1e9)	continue;
				if (a[i] % (long long)pow(2, x[j].second + 1) == 0)	a[i] += pow(2, x[j].second);
			}
		}
		for (int i = 0; i < n; i++) {
			cout << a[i] << ' ';
		}
		cout << '\n';
	}
	return 0;
}

/*
길이가 n인 정수배열 a, q인 정수배열 x가 주어진다.
a[i]가 2^q[j]로 나누어 떨어지면 a[i] += 2^(q[j]-1)이 된다.
모든 쿼리 종료시에 a의 결과를 계산해라

a[i]가 2^q[j]로 나누어 떨어진다고 가정하면, a[i] = 2^x[j] * y이다. 
1번 연산 후에 a[i] = 2^x[j] * y + 2^(x[j]-1) = 2^(x[j]-1] * (1+2y)이다. 
1+2y가 항상 홀수이므로 모든 a[i]는 1개 이상의 쿼리가 처리될 수 없다. 단 x[j] = 1인경우는 예외.
따라서 x[j] <= 30이므로 모든 a[i]에 대해 30번만 연산해보면 된다.
쿼리는 순차로 진행되므로 x[j]를 인덱스 오름차순 정렬한다.

O(n) / O(q)

*/
