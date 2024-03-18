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
	string s;
	cin >> s;
	vector<vector<int>> cnt(26);
	long long ans = 0;
	for (int i = 0; i < s.size(); i++)	cnt[s[i] - 'a'].push_back(i);
	for (int i = 0; i < s.size(); i++) {
		for (int j = 0; j < 26; j++) {
			if (s[i] - 'a' == j)	continue;
			auto it = upper_bound(cnt[j].begin(), cnt[j].end(), i);
			ans += cnt[j].end() - it;
		}
	}
	bool b = false;
	for (int i = 0; i < 26; i++)	if (cnt[i].size() > 1)	b = 1;
	ans += b;
	if (ans == 0)	ans = 1;
	cout << ans;
}

/*
	문자열 s(|s| <= 10^6)가 주어진다. s[i]와 s[j]를 1번만 swap 할 수 있을 때, 그 결과로 나올 수 있는 문자열의 종류 갯수를 구해라
	
	cnt[i] = 문자 i의 인덱스 오름차순 벡터. (ex; abca일 때 cnt[0] = {0, 3})
	현재 위치를 i라 하자. cnt[0..25]를 돌면서 i<j인 j의 갯수를 이진탐색으로 찾는다.
	예외케이스; 특정 문자가 2개이면 해당 문자를 바꿨을떄도 원본 문자열을 1개로 셀 수 있다.
	O(nlogn) / O(n)
*/
