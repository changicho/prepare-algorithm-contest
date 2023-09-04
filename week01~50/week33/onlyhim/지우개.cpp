#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, val;
	cin >> n;
	queue<int> q;
	for (int i = 1; i <= n; i++) {
		q.push(i);
	}
	while (q.size() != 1) {
		int qsize = q.size();
		queue<int> tmpQ;
		for (int i = 0; i < qsize; i++) {
			if (i % 2)	tmpQ.push(q.front());
			q.pop();
		}
		q = tmpQ;
	}
	cout << q.front();
	return 0;
}
