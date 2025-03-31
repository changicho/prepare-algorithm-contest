#define _CRT_SECURE_NO_WARNINGS

#include <vector>
#include <iostream>
#include <string>
#include <algorithm>
#include <numeric>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <map>
#include <set>
#include <queue>
#include <stack>
using namespace std;

int n, m, k, ans;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n >> m >> k;
	ans = 0;
	vector<vector<int>> keyList;
	vector<char> keyStat(m);
	for (int i = 0; i < m; i++) {
		int curKeyNum,val;
		char curKeyPass;
		cin >> curKeyNum;
		vector<int> keys(curKeyNum);
		for (int j = 0; j < curKeyNum; j++) {
			cin >> keys[j];
			keys[j]--;
		}
		keyList.push_back(keys);
		cin >> keyStat[i];
	}
	for (int curKey = 0; curKey < (1 << n); curKey++) {
		bool isPossible = 1;
		for (int j = 0; j < m; j++) {
			int curKeyNum = 0;
			for (auto key : keyList[j]) {
				curKeyNum += (curKey >> key) & 1;
			}
			isPossible &= (curKeyNum >= k) == (keyStat[j] == 'o');
		}
		if (isPossible)	ans++;
	}
	cout << ans;
	return 0;
}


/*
	완전탐색으로 모든 키조합에 대해 valid한지 확인한다.
	valid확인은 주어지는 모든 test에 대해 
	현재 키의 개수가 k개 이상이며, test값이 o일 때

	O(2^N * M * N) <= 10^6

*/
