#define _CRT_SECURE_NO_WARNINGS

#include <vector>
#include <iostream>
#include <string>
#include <algorithm>
#include <numeric>
using namespace std;

bool isFind;

bool go(vector<int>& v, int cnt, int q) {
	if (isFind)	return 1;
	if (cnt < 0)	return 0;
	int val = v[0];
	bool isAllSame = 1;
	for (int i = 1; i < v.size(); i++) {
		if (val != v[i])	isAllSame = 0;
	}
	if (isAllSame)	isFind = 1;

	bool ans = 0;
	for (int i = 0; i < v.size(); i++) {
		if (v[i] != q) {
			int orig = v[i];
			v[i] = orig / 2;
			v.push_back(orig % 2 ? orig / 2 + 1 : orig /2);
			ans |= go(v, cnt - 1, q);
			v.pop_back();
			v[i] = orig;

			v[i] = orig - q;
			v.push_back(q);
			ans |= go(v, cnt - 1, q);
			v.pop_back();
			v[i] = orig;
		}
	}
	return ans;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t, a, b, c;
	cin >> t;
	for (int i = 1; i <= t; i++) {
		isFind = 0;
		vector<int> v(3);
		cin >> v[0] >> v[1] >> v[2];
		int minVal = min(v[0], min(v[1], v[2]));
		bool ans = go(v, 3, minVal);
		if (isFind == 1)	cout << "YES" << '\n';
		else cout << "NO" << '\n';
	}
	return 0;
}

/*
3개의 정수가 주어진다. 이 중 1개를 골라 x = a+b가 되도록 나눈다. 이 연산은 최대 3번 가능하다.
모든 정수가 같은 값이 될 수 있는지 확인해라

연산은 항상 값이 작아지게 되므로, 입력의 3개 정수중 최소 값으로 모든 값을 통일시킨다.
이를 위해 재귀로 1) 정수중 1개를 골라 반으로 자른다 or 2) 현재 탐색중인 정수 값이 최소값이 아니라면 x = 최소값 + k로 나눈다.

*/
