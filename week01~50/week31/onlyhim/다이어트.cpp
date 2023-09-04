#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct node {
	node() {
		a = 0;
		b = 0;
		c = 0;
		d = 0;
		cost = 0;
	}
	int a, b, c, d, cost;
};

bool judge(node target, node cur) {
	return cur.a >= target.a && cur.b >= target.b && cur.c >= target.c && cur.d >= target.d;
}

int ansCost, ansVisit;

void dfs(vector<node>& v, node& target, node& cur, int n ,int curPos, int& visit) {
	if (curPos >= n) {
		if (judge(target, cur)) {
			if (ansCost > cur.cost) {
				ansVisit = visit;
				ansCost = cur.cost;
			}
			else if (ansCost == cur.cost) 
				ansVisit = max(ansVisit, visit);
		}
		return;
	}
	if ((v[curPos].a == 0 && v[curPos].b == 0 && v[curPos].c == 0 && v[curPos].d == 0)) {
		dfs(v, target, cur, n, curPos + 1, visit);
	}
	else{
		cur.a += v[curPos].a;
		cur.b += v[curPos].b;
		cur.c += v[curPos].c;
		cur.d += v[curPos].d;
		cur.cost += v[curPos].cost;
		visit |= (1 << (15 - curPos));
		dfs(v, target, cur, n, curPos + 1, visit);
		cur.a -= v[curPos].a;
		cur.b -= v[curPos].b;
		cur.c -= v[curPos].c;
		cur.d -= v[curPos].d;
		cur.cost -= v[curPos].cost;
		visit &= ~(1 << (15 - curPos));
		dfs(v, target, cur, n, curPos + 1, visit);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	ansCost = 1e9;
	ansVisit = -1;
	int n, a, b, c, d;
	node target;
	cin >> n >> target.a >> target.b >> target.c >> target.d;
	vector<node> v(n);
	for (int i = 0; i < n; i++) cin >> v[i].a >> v[i].b >> v[i].c >> v[i].d >> v[i].cost;
	int visit = 0;
	node cur;
	dfs(v, target, cur, n, 0, visit);
	if (ansCost == 1e9)	cout << -1;
	else {
		cout << ansCost<<'\n';
		vector<int> ansList;
		for (int i = 0; i < n; i++)	if (ansVisit & (1 << (15 - i)))	ansList.push_back(i+1);
		for (int i = 0; i < ansList.size(); i++) {
			cout << ansList[i] << ' ';
		}
	}
	return 0;
}
