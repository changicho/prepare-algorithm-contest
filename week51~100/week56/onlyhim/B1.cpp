#define _CRT_SECURE_NO_WARNINGS

#include <vector>
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

const int MOD = 1000000007;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t, numTree, numWell, x, y;
	cin >> t;
	for (int i = 1; i <= t; i++) {
		vector<int> numTreeXaxis(3005, 0);
		vector<int> numTreeYaxis(3005, 0);
		cin >> numTree;
		for (int j = 0; j < numTree; j++) {
			cin >> x >> y;
			numTreeXaxis[x]++;
			numTreeYaxis[y]++;
		}
		cin >> numWell;
		int ans = 0;
		int wellXPos, wellYPos;
		for (int j = 0; j < numWell; j++) {
			cin >> wellXPos >> wellYPos;
			for (int k = 0; k <= 3000; k++) {
				int xVal = abs(wellXPos - k) * abs(wellXPos - k);
				int yVal = abs(wellYPos - k) * abs(wellYPos - k);
				ans = (ans + (xVal * numTreeXaxis[k]) % MOD) % MOD;
				ans = (ans + (yVal * numTreeYaxis[k]) % MOD) % MOD;
			}
		}
		cout << "Case #" << i << ": " << ans << '\n';
	}
	return 0;
}


/*
나무의 좌표를 (x,y), 갯수를 n, 우물의 좌표를 (a,b), 갯수를 m이라 하자. (n,m <= 5*10^5, n+m <= 3*10^6)
모든 나무와 우물에 대해 sum( (a-x)^2 + (b-y)^2 )를 계산하면 된다.
brute force = O(nm)
x 좌표와 y좌표에 등장하는 나무의 수를 각각 기록해두고, 모든 우물에 대해 좌표에 존재하는 갯수 * 거리 를 계산한다.
-> O(3000 * m)
*/
