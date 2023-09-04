#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <algorithm>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin >> t;
	while (t--) {
		int n, d;
		cin >> n >> d;
		string str;
		cin >> str;
		for (int i = 0; i < str.size(); i++) {
			if (str[i] - '0' < d) {
				str = str.substr(0, i) + (char)(d + '0') + str.substr(i, str.size() - i);
				break;
			}
			if (i == str.size() - 1) {
				str = str + (char)(d + '0');
				break;
			}
		}
		cout << str << '\n';
	}
	return 0;
}
