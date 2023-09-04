#include <iostream>
#include <vector>
#include <string>
using namespace std;

int go(string& str, int l, int r, int& flag) {
	if (l > r) {
		if (flag)	return 1;
		else return 0;
	}
	if (str[l] != str[r]) {
		if (flag == 0) {
			flag++;
			if (go(str, l + 1, r, flag) == 1 || go(str, l, r - 1, flag) == 1)	return 1;
			else return 2;
		}
		else return 2;
	}
	else {
		return go(str, l + 1, r - 1, flag);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin >> t;
	while (t--) {
		string str;
		cin >> str;
		int l = 0, r = str.size() - 1;
		int flag = 0;
		int ans = go(str, l, r, flag);
		cout << ans << '\n';
	}
	return 0;
}
