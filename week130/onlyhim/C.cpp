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

    long long n, k, x, ans = 0;
    cin >> n >> k >> x;
    vector<long long> v(n);
    for (int i = 0; i < n; i++)     cin >> v[i];
    sort(v.begin(), v.end(), greater<long long>());
    long long sums = 0;
    for (int i = 0; i < n; i++) {
        ans++;
        if (i < n - k)    continue;
        sums += v[i];
        if (sums >= x)  break;
    }

    if (sums < x)   cout << -1 << '\n';
    else cout << ans << '\n';

    return 0;
}

/*
* N개의 정수 배열이 주어진다
* 이중 K개의 컵은 술이 들어있다.
* 최소 X만큼은 마셔야 술인지 판단할 수 있다.
* N개중 최소 몇개의 컵을 마셔야 술인지 판단할 수 있는지 계산해라
* 
* k = 술 갯수, n-k = 물 갯수
* 내림차순으로 정렬한다음, 물 갯수만큼은 제외시킨다. (모든 경우를 고려해야 하므로)
* 제외시킨 후 나머지를 술로 채웠을 때, 내림차순 정렬 되어있으므로 그 값을 더해가면서 x를 초과하는지 확인
*/
