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
        int n, d;
        cin >> n >> d;
		vector<pair<int,int>> eggs(n);
		vector<int> used(n);
        for (int i = 0; i < n; i++) {
            cin >> eggs[i].first;
			eggs[i].second = i;
        }
		for (int i = 0; i < n; i++) cin >> used[i];
        queue<vector<int>> q;
        for (int i = 0; i < n; i++) {
			q.push({ eggs[i].first, eggs[i].second });
            int usingEgg = used[i];

            while (!q.empty() && usingEgg > 0) {
				vector<int>& cur = q.front();
                
                if (usingEgg - cur[0] >= 0) {
					usingEgg -= cur[0];
                    q.pop();
                }
                else {
					cur[0] -= usingEgg;
                    usingEgg = 0;
                }
            }

            while (!q.empty() && i >= q.front()[1] + d)    q.pop();
        }

        int ans = 0;
        while(q.empty() == false) {
            ans += q.front()[0];
            q.pop();
		}
		cout << ans << '\n';
    }
    return 0;
}
 
/*
계란을 다음 순서로 처리한다.
1. 새로 구매한 계란을 큐에 넣는다.
2. 큐의 front가 현재 사용할 계란 보다 작으면 pop시키고, 아니면 사용할 값만큼 빼놓는다.
3. 큐의 front에서 유통기한을 체크하면서 pop시킨다.
*/
