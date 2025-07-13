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
using namespace std;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int qry;
    cin >> qry;
    for (int i = 0; i < qry; i++) {
        int n;
        cin >> n;
        vector<pair<double,int>> v(n);
        for (int j = 0; j < n; j++) {
            cin >> v[j].first;
            v[j].second = v[j].first < 0 ? 0 : 1;
            v[j].first = abs(v[j].first);
        }
        sort(v.begin(), v.end());
        double k = v[1].first / v[0].first;
        int isMix = v[0].second + v[1].second == 1 ? 1 : 0;
        bool ans = 1;
        for (int j = 2; j < n; j++) {
            if (isMix) {
                if (v[j - 1].first * k != v[j].first) ans = 0;
                if (v[j].second + v[j - 1].second != 1)   ans = 0;
            }
            else
                if (v[j - 1].first * k != v[j].first) ans = 0;
        }
        if (ans)    cout << "Yes\n";
        else cout << "No\n";
    }
    return 0;
}

/*
* 항상 오름차순이라 가정한다.
* v[i] * k = v[j+1]이므로, k를 구하고 조건에 맞는지 확인한다.
* 
* 예외; 음 - 양 - 음 - 양인 경우
*/
