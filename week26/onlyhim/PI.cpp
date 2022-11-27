#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

#define INF 10000007

int getScore(string& str, int pos, int sz) {
	bool is1 = 1;
	bool is4 = 1;
	bool isAritSequence = 1;
	vector<char> prev;
	prev.push_back(str[pos]);
	char prevVal = str[pos];
	char prevVal2 = str[pos + 1];
	int diff = prevVal - prevVal2;
	for (int i = pos+1; i < pos + sz; i++) {
		if (prev.back() != str[i])	is1 = 0;
		if (i - pos >= 2 && prev[i - pos - 2] != str[i])	is4 = 0;
		if (prev.back() - str[i] != diff) {
			isAritSequence = 0;
		}
		prev.push_back(str[i]);
	}
	if (is1)	return 1;
	else if (is4)	return 4;
	else if (isAritSequence) {
		if (diff == 1 || diff == -1)	return 2;
		else return 5;
	}
	else return 10;
}

int go(vector<int>& dp, string& str, int pos) {
	if (pos >= str.size())	return 0;
	int& ret = dp[pos];
	if (ret != INF)	return ret;
	ret = INF;
	for (int i = 3; i <= 5; i++) {
		if (pos + i <= str.size()) {
			ret = min(ret, getScore(str, pos, i) + go(dp, str, pos + i));
		}
	}
	return ret;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int tc;
	string str;
	cin >> tc;
	for (int i = 1; i <= tc; i++) {
		cin >> str;
		vector<int> dp(str.size(), INF);
		cout << go(dp, str, 0) << '\n';
	}
	return 0;
}
