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

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, ans = 0;
    cin >> n;
    vector<int> v(n);
	for (int i = 0; i < n; i++) cin >> v[i];
    vector<int> dom(n, 0);
    int lastIdx = 0;
    for (int i = 0; i < n; i++) {
        if (i == 0 || dom[i] == -1) {
            int k = lastIdx - i;
            while (lastIdx < n && k < v[i]) {
                dom[lastIdx++] = -1;
				k++;
            }
        }
        else
            break;
    }
	for (int i = 0; i < n; i++) if (dom[i] == -1) ans++;
    cout << ans;
    return 0;
}
 
/*
현재 위치를 0, 도미노 크기를 k라 할때 0~k-1만큼 도미노가 넘어진다.
처음 것을 넘어뜨리고, 해당 도미노의 크기만큼 모두 -1 처리해둔다. 이를 dom 배열, 마지막으로 넘어진 dom 배열을 lastIdx라 하자.
현재 위치를 i라 할 때, dom[i]가 이미 -1이면 현재 도미노도 넘어갔다는 뜻이므로, dom을 갱신시킨다.
이를 갱신시킬 때 남은 길이는 lastIdx - i이다.
O(n)
*/
