#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <algorithm>

using namespace std;

struct node {
	int id, time, calc;
};

struct CMP {
	bool operator()(node a, node b) {
		if (a.time == b.time)	return a.calc < b.calc;
		return a.time > b.time;
	}
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, k;
	cin >> n >> k;
	vector<pair<int, int>> v(n);
	for (int i = 0; i < n; i++)	cin >> v[i].first >> v[i].second;
	priority_queue<node, vector<node>, CMP> pq;
	int vIdx = 0, kIdx = 1;
	for (; vIdx < min(n, k); vIdx++, kIdx++) {
		pq.push({ v[vIdx].first, v[vIdx].second, kIdx });
	}
	long long ans = 0, mul = 1;
	int elapsedTime = 0;
	priority_queue<int, vector<int>, greater<int>> calcPq;
	while (!pq.empty()) {
		node cnode = pq.top();
		pq.pop();
		int curTime = cnode.time, curId = cnode.id, curCalculator = cnode.calc;
		ans += (curId * (mul++));
		elapsedTime += (curTime - elapsedTime);
		calcPq.push(curCalculator);
		while (!pq.empty() && pq.top().time == curTime) {
			node cnode = pq.top();
			pq.pop();
			curTime = cnode.time, curId = cnode.id, curCalculator = cnode.calc;
			ans += (curId * (mul++));
			calcPq.push(curCalculator);
		}
		while (!calcPq.empty() && vIdx < n) {
			curCalculator = calcPq.top();
			calcPq.pop();
			pq.push({ v[vIdx].first, v[vIdx].second + elapsedTime, curCalculator });
			vIdx++;
		}
	}
	cout << ans;
	return 0;
}
