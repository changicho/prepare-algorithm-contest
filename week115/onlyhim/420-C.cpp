#define _CRT_SECURE_NO_WARNINGS

#include <vector>
#include <iostream>
#include <string>
#include <algorithm>
#include <numeric>
#include <set>
#include <cmath>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <map>
#include <climits>
#include <tuple>
using namespace std;

const int inf = 1000000001;
template<class T, class U> inline bool chmin(T& a, const U& b) { if (a > b) { a = b; return true; } return false; }

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q;
	long long sums = 0;
    cin >> n >> q;
	vector<int> a(n), b(n), mins(n);
	for (int i = 0; i < n; i++) cin >> a[i];
	for (int i = 0; i < n; i++) cin >> b[i];
	for (int i = 0; i < n; i++) mins[i] = min(a[i], b[i]);
    for (int i = 0; i < n; i++) sums += mins[i];

    for (int i = 0; i < q; i++) {
        char c;
        int x, v;
		cin >> c >> x >> v;
        x--;
        if (c == 'A') {
            sums -= mins[x];
            mins[x] = min(b[x], v);
            sums += mins[x];
            a[x] = v;
        }
        else {
            sums -= mins[x];
            mins[x] = min(a[x], v);
            sums += mins[x];
            b[x] = v;
        }

        
		cout << sums << '\n';
    }

    return 0;
}

/*
* 두 정수배열 a,b가 주어진다
* 쿼리 A; a[x] = v로 변경
* 쿼리 B; b[x] = v로 변경
* min(a[i], b[i])의 합을 매 쿼리마다 계산
* 
*/
