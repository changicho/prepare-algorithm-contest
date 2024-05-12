#define _CRT_SECURE_NO_WARNINGS

#include <vector>
#include <iostream>
#include <string>
#include <algorithm>
#include <numeric>
#include <set>
#include <unordered_map>
#include <queue>
#include <stack>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n, val;
	stack<int> s;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> val;
		if (s.empty() || s.top() != val)	s.push(val);
		else {
			while (!s.empty()) {
				int nextVal = s.top() + 1;
				s.pop();
				if (s.empty() || nextVal != s.top()) {
					s.push(nextVal);
					break;
				}
			}
		}
	}
	cout << s.size();
	return 0;
}

/*
	길이가 n인 정수배열 v가 주어진다.
	empty sequence에 다음의 연산을 n번 수행했을 때 마지막 연산 후의 sequence의 크기를 구해라.
	1. 현재 sequence에 v[i]를 오른쪽에 추가한다.
	2. v[i]의 right most 값과 second right most값이 다르면 연산을 종료한다.
	3. 두 값이 같으면, 두 값을 제거 후 해당 값 + 1만큼 더해서 다시 rightmost에 추가한다.

	스택으로 구현
	O(N) / O(N)
*/
