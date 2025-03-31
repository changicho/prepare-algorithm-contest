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
	long long n;
	cin >> n;
	vector<long long> v;
	for (long long i = 1; i * i * i <= n; i++)	v.push_back(i*i*i);
	for (int i = v.size() - 1; i >= 0; i--) {
		vector<int> vv;
		long long val = v[i];
		while (val) {
			vv.push_back(val % 10);
			val /= 10;
		}
		int l = 0, r = vv.size() - 1;
		bool isPal = 1;
		while (l <= r) {
			if (vv[l] != vv[r])	isPal = 0;
			l++, r--;
		}
		if (isPal) {
			cout << v[i];
			return 0;
		}
	}
	return 0;
}

/*
	정수 n(<= 10^18)이 주어진다.
	x^3 = k (x>=1)이면서 palindrome인 n보다 작은 가장 큰 k값을 계산해라
	
	n<=10^18이므로, k는 최대 10^6이다.
	10^6인 후보중 팰린드롬인지 확인하는데 최대 O(1)이 소요된다.
	따라서 O(10^6)에 해결 가능하다.

*/
