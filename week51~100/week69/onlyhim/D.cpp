#define _CRT_SECURE_NO_WARNINGS

#include <vector>
#include <iostream>
#include <string>
#include <algorithm>
#include <numeric>
#include <set>
#include <cmath>
#include <unordered_map>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n, k;
	cin >> n >> k;
	unordered_map<long long, int> um;
	um[0] = n;
	vector<long long> prev(n);
	for (int i = 0; i < n; i++)	prev[i] = 0;
	for (int i = 0; i < k; i++) {
		int idx, val;
		cin >> idx >> val;
		idx--;
		long long prevVal = prev[idx];
		um[val + prevVal]++;
		um[prevVal]--;
		if (um[prevVal] == 0)	um.erase(prevVal);
		prev[idx] = val + prevVal;
		cout << um.size() << '\n';
	}
	return 0;
}

/*
	정수 n,k과 k개의 ar[1..k] = (a, b)가 입력으로 주어진다.
	처음에 v[1..i] = 0이고, x초 뒤에 v[a] += b로 바뀐다.
	1..k마다 unique한 v[i]의 갯수를 계산해라.
	예를들어, y초 뒤에 v[i] = {10, 20, 0, 20}이면 답은 3이다.

	key = 값, value = key 갯수인 hash table을 유지한다.
	초기값 um[0] = n개로 초기화
	prev[i] = v[i]의 이전값
	매 쿼리마다 um을 갱신하고 um의 사이즈를 출력
*/
