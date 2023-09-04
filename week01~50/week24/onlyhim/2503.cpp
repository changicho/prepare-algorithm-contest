#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

int CalcStrike(int a, int b) {
	int ans = (a / 100 == b / 100) + (((a / 10) % 10) == ((b / 10) % 10)) + (a % 10 == b % 10);
	return ans;
}

int CalcBall(int a, int b) {
	int ans = 0;
	int a100 = a / 100, a10 = (a / 10) % 10, a1 = a % 10;
	int b100 = b / 100, b10 = (b / 10) % 10, b1 = b % 10;
	if (a100 == b10 || a100 == b1)	ans++;
	if (a10 == b100 || a10 == b1)	ans++;
	if (a1 == b100 || a1 == b10)	ans++;
	return ans;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	unordered_set<int> sets;
	for (int i = 1; i <= 9; i++){
		for (int j = 1; j <= 9; j++) {
			if (i == j)	continue;
			for (int k = 1; k <= 9; k++) {
				if (i == k || j == k)	continue;
				sets.insert(i * 100 + j * 10 + k);
			}
		}
	}
	int query, val, numStrike, numBall;
	cin >> query;
	for (int i = 0; i < query; i++) {
		cin >> val >> numStrike >> numBall;
		vector<int> v;
		for (auto it : sets) {
			if (CalcStrike(it, val) != numStrike || CalcBall(it, val) != numBall) {
				v.push_back(it);
			}
		}
		for (auto it : v)	sets.erase(it);
	}
	cout << sets.size() << endl;
	return 0;
}
