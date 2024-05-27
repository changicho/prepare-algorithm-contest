#define _CRT_SECURE_NO_WARNINGS

#include <vector>
#include <iostream>
#include <string>
#include <algorithm>
#include <numeric>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <stack>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	cin >> n;
	vector<pair<int, int>> lefts(n);
	vector<int> rights(n);
	for (int i = 0; i < n; i++) {
		cin >> lefts[i].first;
		lefts[i].second = i;
		cin >> rights[i];
	}
	sort(lefts.begin(), lefts.end());
	long long ans = 0;
	for (int i = 0; i < n; i++) {
		int curLeftIdx = lefts[i].second;
		int curRight = rights[curLeftIdx];
		int maxIdx = -1;
		int l = i, r = n - 1;
		while (l <= r) {
			int m = (l + r) / 2;
			if (lefts[m].first > curRight)	r = m - 1; 
			else {
				maxIdx = max(maxIdx, m);
				l = m + 1;
			}
		}
		if (maxIdx != -1)	ans += maxIdx - i;
	}
	cout << ans;
}

/*
	크기가 n인 배열 a[i] = {x,y}가 주어진다. (x<=y)
	a[i], a[j]가 intersection되는 모든 pair의 갯수를 계산해라. 

	1. a[i]의 x를 오름차순으로 정렬한다. 이를 lefts라 한다.
	2. 현재 위치를 i라 할 때, 정렬된 배열에서 a[j].x >= a[i].y 인 j의 최대 값을 이분 탐색으로 찾는다.
	3. 2에서 찾은 j - i 만큼 답에 누적한다.

	O(nlogn) / O(n)
*/
