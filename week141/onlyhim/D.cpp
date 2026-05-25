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
#include <iomanip>
#include <array>
#include <bit>
#include <cmath>

using namespace std;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, q;
    cin >> n >> q;
	priority_queue<int, vector<int>, greater<int>> ups;
	priority_queue<int, vector<int>, less<int>> lows;

    for (int i = 0; i < q; i++) {
        int a, b;
        cin >> a >> b;
        if (i == 0) {
			vector<int> v = { n, a, b };
			sort(v.begin(), v.end());
            lows.push(v[0]);
            lows.push(v[1]);
			ups.push(v[2]);
        }
        else {
            if (min(a, b) > ups.top()) {
                lows.push(ups.top());
                ups.pop();
                ups.push(a);
                ups.push(b);
            }
            else if (max(a,b) < lows.top()) {
                ups.push(lows.top());
                lows.pop();
                lows.push(a);
                lows.push(b);
            }
            else {
                lows.push(min(a, b));
                ups.push(max(a, b));
			}
        }
		cout << lows.top() << "\n";
    }

    return 0;

}
 
/*
lows = 오름차순의 중앙값을 포함한 하위 값들
ups = 내림차순의 중앙값 이상의 상위 값들

*/
