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

    int t;
    cin >> t;
    while (t--) {
        int n, ans = 0;
        long long total = 0;
        cin >> n;
		vector<vector<int>> v(n, vector<int>(3));
        for(int i = 0; i < n; i++) {
			cin >> v[i][1] >> v[i][2];
			v[i][0] = v[i][1] + v[i][2];
            total += v[i][2];
		}
        sort(v.begin(), v.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[0] < b[0];
            });
        for (int i = 0; i < n; i++) {
            if (total - v[i][0] >= 0) {
				total -= v[i][0];
                ans++;
            }
        }
        cout << ans << '\n';
    }
    

    return 0;
}
 
/*
* 모든 순록을 처음에 끄는쪽으로 둔다.
* 그 후에 순록 a[i]를 타는 쪽으로 바꾸면, 총 여유 무게에서 순록의 끄는 힘은 줄어들고, 타는 힘은 더해진다.
* 즉 총 여유 - a[i][0] - a[i][1]이 된다.
* 따라서 a[i][0] + a[i][1]을 오름차순 정렬해서 그리디하게 순록에서 뺀다.
*/
