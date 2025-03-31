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
using namespace std;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, rank = 1, val, curVal, srank = 1;
    cin >> n;
    vector<pair<int, int>> v(n);
    vector<int> ans(n);
    for (int i = 0; i < n; i++) {
        cin >> val;
        v[i] = { val, i };
    }
    sort(v.begin(), v.end());
    curVal = v[n - 1].first;
    ans[v[n - 1].second] = rank;
    srank = rank++;
    for (int i = n - 2; i >= 0; i--) {
        if (v[i].first == curVal) {
            ans[v[i].second] = srank;
        }
        else {
            srank = rank;
            ans[v[i].second] = srank;
            curVal = v[i].first;
        }
        rank++;
    }
    for (int i = 0; i < ans.size(); i++)    cout << ans[i] << '\n';
    return 0;
}

/*
    길이가 n인 정수배열이 주어질 때, 이 배열의 rank를 계산해라 (동일 순위 존재)
    ex) 3 12 9 9 -> 4 1 2 2

    v = { 값, 인덱스 }
    v를 오름차순 정렬하고, 뒤에서 부터 순회한다.
    현재 값이 이전 값과 동일하면 이전의 값과 동일한 rank값으로 처리
    다르면 여태 증가시킨 rank값으로 처리
*/
