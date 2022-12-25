#include <iostream>
#include <vector>
using namespace std;

int dp[1 << 25];

int goy2[2][2] = { {0, 1}, {0, 0} };
int gox2[2][2] = { {0, 0}, {0, 1} };

int goy3[4][3] = { {0, 1, 1}, {0, 0, 1}, {0, 1, 0}, {0, 1, 1} };
int gox3[4][3] = { {0, 0, 1}, {0, 1, 1}, {0, 0, 1}, {0, 0, -1} };

int calcPos(int y, int x) {
	return 1 << ((y * 5) + x);
}

bool judge(int y, int x, int stat) {
	return y >= 0 && x >= 0 && y < 5 && x < 5 && (stat & calcPos(y, x));
}


int go(int stat) {
	int& ret = dp[stat];
	if (ret != -1)	return ret;
	ret = 0;
	for (int y = 0; y < 5; y++) {
		for (int x = 0; x < 5; x++) {
			if (calcPos(y, x) & stat) {
				// two block
				for (int i = 0; i < 2; i++) {
					bool isEmpty = 1;
					for (int j = 0; j < 2; j++) {
						int ny = y + goy2[i][j], nx = x + gox2[i][j];
						if (!judge(ny, nx, stat))	isEmpty = 0;
					}
					if (isEmpty) {
						int origStat = stat;
						for (int j = 0; j < 2; j++) {
							int ny = y + goy2[i][j], nx = x + gox2[i][j];
							stat &= ~calcPos(ny, nx);
						}
						if (!go(stat))	ret = 1;
						stat = origStat;
					}
				}
				// three block
				for (int i = 0; i < 4; i++) {
					bool isEmpty = 1;
					for (int j = 0; j < 3; j++) {
						int ny = y + goy3[i][j], nx = x + gox3[i][j];
						if (!judge(ny, nx, stat))	isEmpty = 0;
					}
					if (isEmpty) {
						int origStat = stat;
						for (int j = 0; j < 3; j++) {
							int ny = y + goy3[i][j], nx = x + gox3[i][j];
							stat &= ~calcPos(ny, nx);
						}
						if (!go(stat))	ret = 1;
						stat = origStat;
					}
				}
			}
		}
	}
	return ret;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t, n;
	cin >> t;
	while (t--) {
		char a;
		int stat = 0;
		for (int i = 0; i < 5; i++)	for (int j = 0; j < 5; j++) {
			cin >> a;
			stat |= a == '.' ? 1 << (i * 5 + j) : 0;
		}
		for (int i = 0; i < sizeof(dp) / sizeof(int); i++)	dp[i] = -1;
		int ret = go(stat);
		if (ret == 0)	cout << "LOSING\n";
		else cout << "WINNING\n";
	}
	return 0;
}
