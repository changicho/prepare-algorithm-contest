#define _CRT_SECURE_NO_WARNINGS
 
#include <vector>
#include <iostream>
#include <string>
#include <algorithm>
#include <numeric>
using namespace std;
 
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t, n, m;
	cin >> t;
	string str1, str2;
	for (int i = 1; i <= t; i++) {
		cin >> n >> m;
		cin >> str1 >> str2;
		bool isFind = 0;
		int ans = 0;
		if (str1.size() >= str2.size()) {
			while (1) {
				for (int i = 0; i + str2.size() <= str1.size(); i++) {
					bool isSame = 1;
					for (int j = 0; j < str2.size(); j++)	if (str1[i + j] != str2[j])	isSame = 0;
					if (isSame)	isFind = 1;
				}
				if (isFind || ans > 2)	break;
				str1 = str1 + str1;
				ans++;
			}
		}
		else {
			while (1) {
				for (int i = 0; i + str2.size() <= str1.size(); i++) {
					bool isSame = 1;
					for (int j = 0; j < str2.size(); j++)	if (str1[i + j] != str2[j])	isSame = 0;
					if (isSame)	isFind = 1;
				}
				if (isFind || str1.size() > str2.size() * 2)	break;
				str1 = str1 + str1;
				ans++;
			}
		}
		if (isFind == 0)	ans = -1;
		cout << ans << '\n';
	}
	return 0;
}


/*
문자열 a,b가 주어진다.
a를 여러번 이어붙였을 때 b가 되는지 확인하고, 그 최소값을 계산해라

문자열의 길이가 a >= b라면, a->b가 되는 경우는 항상 a를 2번 이하로 붙였을때 이다. (더 붙여도 계속 반복되므로)
else(a<b)라면, a->b가 되기 위해서는 a의 길이가 b의 2배가 넘는다면 더 붙여도 무의미하다. (이미 한바퀴 돌았으므로)


*/
