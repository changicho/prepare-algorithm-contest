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
    
    int n;
    cin >> n;
    map<int, int> maps;
    for (int i = 0; i < n; i++) {
        int h, l;
        cin >> h >> l;
        if (maps.find(l) == maps.end()) maps[l] = h;
        else maps[l] = max(h, maps[l]);
    }
    vector<vector<int>> v;
    for (auto i : maps) {
        v.push_back({ i.first, i.second });
    }

    sort(v.begin(), v.end());

    int maxHeight = -1;
    for (int i = v.size() - 1; i >=0; i--) {
        if (maxHeight < v[i][1]) {
            maxHeight = v[i][1];
        }
        v[i].push_back(maxHeight);
    }
    sort(v.begin(), v.end());
    int q, curTime;
    cin >> q;
    for (int i = 0; i < q; i++) {
        int l = 0, r = v.size()-1, target = v.size() - 1;
        cin >> curTime;
        while (l <= r) {
            int m = (l + r) / 2;
            if (v[m][0] <= curTime) {
                l = m + 1;
            }
            else {
                target = min(target, m);
                r = m - 1;
            }
        }
        cout << v[target][2] << '\n';
    }

    return 0;
}


/*
v[i] = {현재 시간, 현재 키, 현재 시간에서의 최대 키 값}
쿼리마다 이분탐색으로 curTime을 초과하는 최소 시간을 찾는다.
O(qlogn)
*/
