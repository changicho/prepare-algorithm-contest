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
using namespace std;

int n, maxCal;

void go(vector<pair<int, int>>& v, vector<int>& dp, vector<int>& cal, int vit) {
    for (int i = 0; i < v.size(); i++) {
        if (v[i].first != vit)  continue;
        for (int j = maxCal; j >= cal[i]; j--)    dp[j] = max(dp[j], dp[j - cal[i]] + v[i].second);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> maxCal;
    vector<pair<int,int>> vit(n);
    vector<int> cals(n);
    for (int i = 0; i < n; i++) {
        cin >> vit[i].first >> vit[i].second >> cals[i];
        vit[i].first--;
    }
    vector<vector<int>> dp(3, vector<int>(maxCal + 3, 0));
    go(vit, dp[0], cals, 0);
    go(vit, dp[1], cals, 1);
    go(vit, dp[2], cals, 2);

    int ans = 0;
    for (int i = 1; i <= maxCal; i++) {
        for (int j = 1; j <= maxCal - i; j++) {
            int k = maxCal - i - j;
            ans = max(ans, min(dp[0][i], min(dp[1][j], dp[2][k])));
        }
    }
    cout << ans;
    return 0;
}

/*
*  정수 x와 크기가 n인 정수배열 v,a,c가 주어진다.
* v[i] = 비타민 종류(1,2,3)
* a[i] = 비타민 값
* c[i] = 칼로리
* 
* v를 조합하여 칼로리 합이 x를 넘지 않는 경우 중 비타민 값1~3중 최소값이 max인 경우를 계산해라
* 
* dp[i][j] = 현재 비타민 종류가 i이고, 칼로리가 j일 때 최대 비타민 값
* 
* 현재 확인하려는 비타민을 k라 하자. (k의 비타민 종류 = i)
* dp[i][j] = max(dp[i][j], dp[i][j-cal[k]] + a[k])

예를 들면, v[0] = v[1] = 1, c[0] = 5, c[1] = 3, a[0] = 1, a[1] = 2, x = 7

// k = 0
dp[7] = max(dp[7], dp[2] + a[0])    // c[0] = 5이므로 dp[7-c[0] = 2]
dp[6] = max(dp[6], dp[1] + a[0])
dp[5] = max(dp[5], dp[0] + a[0])

// k = 1
dp[7] = max(dp[7], dp[4] + a[1])    // c[1] = 3이므로 dp[7-c[1] = 4]
..
*/
