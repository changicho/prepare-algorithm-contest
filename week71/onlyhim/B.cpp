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
	long long n, ans = 0;
	cin >> n;
	long long mod = abs(n % 10);
	if (n > 0) {
		if (mod == 0)	ans = n / 10;
		else ans = n / 10 + 1;
	}
	else {
		ans = n / 10;
	}
	cout << ans;
}

/*
*/	
