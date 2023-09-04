#include <iostream>
#include <vector>
using namespace std;

void go(vector<vector<char>>& v, int n, int row, int col) {
	if (n == 3){
		v[row][col] = '*';
		v[row][col+1] = '*';
		v[row][col+2] = '*';
		v[row+1][col] = '*';
		v[row+1][col+2] = '*';
		v[row+2][col] = '*';
		v[row+2][col+1] = '*';
		v[row+2][col+2] = '*';
		return;
	}
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			if (i * 3 + j == 4)	continue;
			int r = i * (n / 3) + row;
			int c = j * (n / 3) + col;
			go(v, n / 3, r, c);
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	vector<vector<char>> v(n, vector<char>(n, ' '));
	go(v, n, 0, 0);
	for (int i = 0; i < v.size(); i++) {
		for (int j = 0; j < v[i].size(); j++) {
			cout << v[i][j];
		}
		cout << '\n';
	}
	return 0;
}
