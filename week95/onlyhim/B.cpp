#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <map>
#include <set>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t, n;
    cin >> t;
    for (int i = 0; i < t; i++) {
        cin >> n;
        vector<vector<int>> adj(n, vector<int>(n, 0));
        vector<int> ans(n);
        for (int i = 0; i < n; i++)    ans[i] = i;
        for (int j = 0; j < n; j++) {
            string str;
            cin >> str;
            for (int k = 0; k < n; k++) {
                adj[j][k] = str[k] - '0';
            }
        }
        for (int i = 0; i < n; i++) {
            for (int j = i - 1; j >= 0; j--) {
                int a = ans[j], b = ans[j+1];
                if (adj[a][b] == 0 && a < b) {
                    swap(ans[j], ans[j + 1]);
                }
            }
        }

        for (int i = 0; i < n; i++) cout << ans[i] + 1 << ' ';
        cout << '\n';
    }
    return 0;
}


/*
    무향그래프 G와 2차원 배열 E가 주어진다. G는 1~n의 정점으로 구성된다. n <= 10^3
    E[i][j] = 1인경우, 정점 i,j는 연결되어 있다.

    다음의 조건을 만족하는 정수배열 P를 구해라. 
    - P는 1~n으로 구성된 permutation이다.
    - i < j이고 P[i] < P[j]를 만족하는 P[i], P[j]는 인접해있다.
    - 이러한 P는 유일하다.

    1. P = { 1, 2, ... n }의 형태로 정렬한다.
    2. P[0]부터 순회하면서 다음을 확인한다.
    - i < j 이고 i,j가 연결되어 있지 않다면 p[i], p[j]를 swap

*/
