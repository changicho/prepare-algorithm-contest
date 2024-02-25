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
	int n,q;
	string str;
	cin >> n >> str >> q;
	vector<int> v(26);
	for (int i = 0; i < 26; i++)	v[i] = i;
	char from, to;
	for (int i = 0; i < q; i++) {
		cin >> from >> to;
		from -= 'a';
		to -= 'a';
		for (int j = 0; j < 26; j++) {
			if (v[j] == from)	v[j] = to;
		}
	}
	for (int i = 0; i < str.size(); i++) {
		int idx = str[i] - 'a';
		str[i] = v[idx] + 'a';
	}
	cout << str;
	return 0;
}

/*
	주어진 문자열 s의 s[i]를 쿼리에 맞게 변경
	결국 원하는 것은 최종문자열이므로 바뀌는 문자열을 다 기록해두고 한번에 변경
*/
