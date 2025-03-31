#define _CRT_SECURE_NO_WARNINGS

#include <vector>
#include <iostream>
#include <string>
#include <algorithm>
#include <numeric>
#include <set>
#include <cmath>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n, q,a,b;
	cin >> n;
	vector<pair<int,int>> v(n+1);
	for (int i = 0; i < n; i++) {
		cin >> a;
		v[a].first = i;
		v[a].second = a;
	}
	cin >> q;
	for (int i = 0; i < q; i++) {
		cin >> a >> b;
		if (v[a].first > v[b].first)	cout<<v[b].second << '\n';
		else cout << v[a].second << '\n';
	}
	return 0;
}

/*
	v[i] = i번째 사람에 대한 정보.
	v[i].first = i번째 사람이 몇번째 서 있는지. v[i].second = i번째 사람의 번호가 무엇인지
*/
