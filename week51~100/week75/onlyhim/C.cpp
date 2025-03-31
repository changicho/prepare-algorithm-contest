#define _CRT_SECURE_NO_WARNINGS

#include <vector>
#include <iostream>
#include <string>
#include <algorithm>
#include <numeric>
#include <set>
#include <unordered_map>
#include <queue>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	cin >> n;
	vector<int> v(n+1);
	unordered_map<int, int> um;
	for (int i = 1; i <= n; i++) {
		cin >> v[i];
		um[v[i]] = i;
	}
	vector<pair<int, int>> ans;
	for (int i = 1; i <= n; i++) {
		if (v[i] != i) {
			ans.push_back({ min(i, um[i]), max(i, um[i])});
			um[v[i]] = um[i];
			swap(v[i], v[um[i]]);
		}
	}
	cout << ans.size() << '\n';
	for (int i = 0; i < ans.size(); i++)	cout << ans[i].first << ' ' << ans[i].second << '\n';
	return 0;
}

/*
	1~N의 permuation 배열이 주어진다. 
	최대 N-1번의 연산으로 이 배열을 1,2,...N 이 되도록 변경하려 한다.
	연산의 횟수와 결과를 출력해라.

	um[v[i]] = 값이 v[i]인 원소의 인덱스
	v[i] != i라면 swap
*/
