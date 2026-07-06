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
    
    int n, m;
    cin >> n >> m;
    map<int, pair<int,int>> birds;
    map<int, int> birdsColor;
    vector<vector<int>> days(m);
    for (int i = 0; i < n; i++) {
        int cur, day, next;
        cin >> cur >> day >> next;
        days[day-1].push_back(i);
        birds[i] = { cur, next };
    }

    for (auto i : birds) {
        birdsColor[i.second.first]++;
    }

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < days[i].size(); j++) {
            int curColor = birds[days[i][j]].first;
            int nextColor = birds[days[i][j]].second;
            birdsColor[curColor]--;
            if (birdsColor[curColor] == 0) birdsColor.erase(curColor);
            birdsColor[nextColor]++;
        }
        cout << birdsColor.size() << '\n';
    }

    return 0;
}

/*
* 새의 색은 1회만 바뀐다.
* 따라서 모든 새마다 변화의 날을 저장해둔다(days)
* 0~m까지 순회하면서 현재 날짜에서 어떤 새의 색이 변화되면 해시테이블에서 이전색-1, 현재색+1을 해둔다(birdsColor)
* O(m)
*/
