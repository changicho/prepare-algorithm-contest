#define _CRT_SECURE_NO_WARNINGS

#include <vector>
#include <iostream>
#include <string>
#include <algorithm>
#include <numeric>
#include <set>
#include <unordered_map>
#include <queue>
using namespace std;

long long n, a, x, y;
unordered_map<long long, double> dp;

double go(long long cur) {
	if (dp.count(cur))	return dp[cur];
	dp[cur] = min(go(cur / a) + x, (go(cur / 2) + go(cur / 3) + go(cur / 4) + go(cur / 5) + go(cur / 6) + 6 * y) / 5);
	return dp[cur];
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n >> a >> x >> y;
	dp.clear();
	dp[0] = 0;
	printf("%.7f", go(n));
	return 0;
}

/*
	정수 n,a,x,y가 주어진다.(n<=10^18, 2<=a<=6, x,y<=10^9)
	n을 0으로 만들기 위해 다음 2개의 연산을 수행할 수 있다.
	1. n=n/a 로 만들고 비용 x를 지불
	2. 주사위(1~6)을 던져 나온 값을 b라 할때, n=n/b로 만들고 비용 y를 지불
	n을 0으로 만들기 위한 최소의 기대값을 계산해라.
	기대값 = 각 사건의 결과와 확률을 곱한 것의 총합. 확률적 사건에 대한 평균의 의미
	주사위 1~6 = 1*1/6 + 2*1/6 + .. + 6*1/6 = 3.5

	최소 기대값을 f(n)이라 하면 2번 연산만 적용했을 때
	f(n) = y + 1/6*f(n/1) + 1/6*f(n/2) + 1/6*f(n/3) + 1/6*f(n/4) + 1/6*f(n/5) + 1/6*f(n/6)
	f(n/1) = f(n)이므로 왼쪽으로 옮기면
	5/6*f(n) = y + 1/6*f(n/2) + 1/6*f(n/3) + 1/6*f(n/4) + 1/6*f(n/5) + 1/6*f(n/6)
	좌우변에 6/5를 곱하면
	f(n) = (6*y + f(n/2) + f(n/3) + f(n/4) + f(n/5) + f(n/6)) * 1/5
	
	여기서 1번 연산을 적용하면
	f(n) = min( (x+n/a), (6*y + f(n/2) + f(n/3) + f(n/4) + f(n/5) + f(n/6)) * 1/5 )
	
	점화식 dp[i] = 현재 값이 i일 때의 기대값
*/
