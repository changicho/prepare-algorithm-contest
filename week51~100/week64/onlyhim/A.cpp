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
	int t;
	cin >> t;
	vector<int> powOf2;
	powOf2.push_back(1);
	powOf2.push_back(2);
	powOf2.push_back(4);
	powOf2.push_back(8);
	powOf2.push_back(16);
	for (int i = 1; i <= t; i++) {
		int n;
		cin >> n;
		vector<int> v(n+1);
		for (int i = 1; i <= n; i++)	cin >> v[i];
		for (int i = powOf2.size() - 1; i >= 0; i--) {
			if (n <= powOf2[i])	continue;
			int mins = 1e9;
			for (int j = powOf2[i] + 1; j <= n; j++) {
				mins = min(v[j], mins);
			}
			int diffMax = -1;
			for (int j = 1; j <= powOf2[i]; j++) {
				if (v[j] > mins)	diffMax = max(diffMax, v[j] - mins);
			}
			if (diffMax != -1) {
				for (int j = 1; j <= powOf2[i]; j++) {
					v[j] -= diffMax;
				}
			}
		}
		bool isSorted = 1;
		for (int j = 2; j <= n && isSorted; j++)	if (v[j - 1] > v[j])	isSorted = 0;
		if (isSorted)	cout << "YES\n";
		else cout << "NO\n";
	}
	return 0;
}

/*
정수배열 v가 주어진다.
1번의 연산으로 2^m <= n인 m을 골라 v[1]~v[2^m]에 1을 뺄 수 있다.
이러한 연산을 무제한 수행하여 v를 non decreasing order로 만들 수 있는가?

v[i]에 1을 빼려면 1~i<=2^k에도 모든 값을 무조건 빼야한다. 

1. 2^k < n인 k를 찾는다.
2. v[2^k+1] ~ v[n]중 최소값을 찾는다. 이를 mins라 한다.
3. v[1] ~ v[2^k]는 항상 mins보다 작거나 같아야 하므로, 이보다 큰 값이 있는 경우 mins와의 차이값중 최대값을 계산한다. 
이를 diffMax라 한다. (모든 v[1]~v[2^k]에 동일한 값을 빼야하므로)
4. diffMax를 v[1]~v[2^k]에 모두 뺀다.
5. v의 order를 계산한다.

O(n^2) / O(1)

*/
