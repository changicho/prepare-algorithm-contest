#define _CRT_SECURE_NO_WARNINGS

#include <vector>
#include <iostream>
#include <string>
#include <algorithm>
#include <numeric>
#include <set>
#include <cmath>
using namespace std;


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	string str;
	cin >> str;
	vector<int> leftLegs;
	vector<int> rightLegs;
	for (int i = 0; i < str.size() - 1; i++) {
		if (str[i] == '(' && str[i + 1] == '(')	leftLegs.push_back(i);
		if (str[i] == ')' && str[i + 1] == ')')	rightLegs.push_back(i);
	}
	long long ans = 0;
	int rightLegsIdx = 0;
	for (int i = 0; i < leftLegs.size(); i++) {
		while (rightLegsIdx < rightLegs.size() && rightLegs[rightLegsIdx] <= leftLegs[i])	rightLegsIdx++;
		ans += rightLegs.size() - rightLegsIdx;
	}
	cout << ans;
	return 0;
}

/*
	((가 있는 idx, ))가 있는 idx를 모두 계산해놓는다.
	((의 idx 배열을 leftLegs, ))의 idx 배열을 rightLegs라 한다.
	))는 항상 (( 왼쪽에 있어야 하므로 leftLegs[i]의 값보다 큰 rightLegs의 갯수를 답에 더한다.
	O(N) / O(N)
*/
