#include <iostream>
#include <vector>
using namespace std;

struct node {
	string name;
	int weight, cost;
};

int go(vector<node>& v, vector<vector<int>>& dp, int w, int i) {
	if (i == -1)	return 0;
	int& ret = dp[i][w];
	if (ret != -1)	return ret;
	if (w - v[i].weight >= 0)	ret = go(v, dp, w - v[i].weight, i - 1) + v[i].cost;
	ret = max(ret, go(v, dp, w, i - 1));
	return ret;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t, n, w;
	cin >> t;
	while (t--) {
		cin >> n >> w;
		vector<node> v(n);
		for (int i = 0; i < n; i++)	cin >> v[i].name >> v[i].weight >> v[i].cost;
		vector<vector<int>> dp(n, vector<int>(1005, -1));
		int ansCost, ansNum;
		ansCost = go(v, dp, w, n - 1);
		vector<string> ansList;
		int curW = w, curCost = 0;
		for (int i = n - 1; i >= 1; i--) {
			if (dp[i][curW] != dp[i - 1][curW]) {
				ansList.push_back(v[i].name);
				curW -= v[i].weight;
				curCost += v[i].cost;
			}
		}
		if (curCost != ansCost)	ansList.push_back(v[0].name);
		cout << ansCost << ' ' <<ansList.size() << '\n';
		for (int i = 0; i < ansList.size(); i++)	cout << ansList[i] << '\n';
	}
	return 0;
}
