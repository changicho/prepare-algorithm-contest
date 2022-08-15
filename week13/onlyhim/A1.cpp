#define _CRT_SECURE_NO_WARNINGS

#include <vector>
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

bool isVowel(int idx) {
	return idx == 0 || idx == 4 || idx == 8 || idx == 14 || idx == 20;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	string s;
	int t;
	cin >> t;
	for (int i = 1; i <= t; i++) {
		cin >> s;
		int numVowel = 0, numCons = 0;
		int maxVowel = -1, maxVowelCnt = -1, maxCons = -1, maxConsCnt = -1;
		vector<int> v(26, 0);
		for (int i = 0; i < s.size(); i++) {
			int idx = s[i] - 'A';
			v[idx]++;
			if (isVowel(idx)) {
				numVowel++;
				if (v[idx] > maxVowelCnt)	maxVowel = idx, maxVowelCnt = v[idx];
			}
			else {
				numCons++;
				if (v[idx] > maxConsCnt)	maxCons = idx, maxConsCnt = v[idx];
			}
		}
		int ans1 = 0, ans2=0;
		for (int i = 0; i < s.size(); i++) {
			int idx = s[i] - 'A';
			if (isVowel(idx) && maxVowel != idx) ans1 += 2;
			else if (isVowel(idx) == 0)	ans1++;
		}
		for (int i = 0; i < s.size(); i++) {
			int idx = s[i] - 'A';
			if (isVowel(idx)) ans2 ++;
			else if (idx != maxCons)	ans2+=2;
		}
		cout << "Case #" << i << ": " << min(ans1, ans2) << '\n';
	}
}
