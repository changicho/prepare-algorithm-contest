#define _CRT_SECURE_NO_WARNINGS

#include <vector>
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

}

/*
문제 정의
N개의 바구니에 쿠키가 담겨있다. 같은 바구니에 있는 쿠키는 모두 무게가 동일하다. 
각 바구니에 들어있는 쿠키의 갯수를 C[i], 무게를 W[i]라 하자.
1. 이 쿠키를 모두 바닥에 뿌려놓고 랜덤하게 1개를 골라 저울에 올려놓는다.
2. 다른 쿠키를 저울의 반대 방향에 올려놓는다.
3. 1,2중 가벼운 쿠키를 버리고 2번으로 돌아간다.
4. 2~3을 K번 반복한다.
4번이 종료된 후 남아있는 쿠키가 1번 바구니에서 나왔을 확률을 계산해라

솔루션
1번 쿠키의 무게보다 가벼운, 같은, 무거운 쿠키들의 갯수를 각각 L, E, H라 하면
모든 쿠키의 갯수 = C[1] + L + E + H가 된다.
만약 C1 + L + E < K+1 이면 답은 0이 된다(= 항상 C1보다 무거운 쿠키를 골라야 하므로), 이 경우가 아니라면 답이 존재한다.

1. C1과 무게가 같은 쿠키(C1에서 0개 이상 선택)를 뽑는 경우의 수는 (C1+L+E)c(K+1) - (L)c(K+1) 이다. 
2. ....................

(N)c(K) = N! / K! * (N-K)!
N*C[i] <= 9*10^6이므로 1~9*10^6의 factorial을 계산해두면 모든 쿼리를 O(1)에 처리 가능하다.


*/
