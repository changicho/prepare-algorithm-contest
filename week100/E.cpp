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

int ans;

void go(vector<pair<int, int>>& a, vector<pair<int, int>>& b, int idx, int cnt) {
    if (idx < 0 || b[idx].first == 0) {
        ans = min(ans, cnt);
        return;
    }
    
    for (int i = a.size() - 1; i >= 0; i--) {
        if (a[i].first != 0 && a[i].first <= b[idx].first) {
            int orga = a[i].first;
            int orgb = b[idx].first;
            a[i].first = 0;
            b[idx].first -= orga;
            go(a, b, idx - 1, cnt + orga);
            a[i].first = orga;
            b[idx].first += orga;
        }
    }

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    ans = 1e9;
    string a, b;
    cin >> n>> a >> b;
    vector<pair<int,int>> va(26);
    vector<pair<int, int>> vb(26);
    for (int i = 0; i < 26; i++) {
        va[i].first = vb[i].first = 0;
        va[i].second = vb[i].second = i;
    }
    for (int i = 0; i < n; i++) {
        va[a[i] - 'a'].first++;
        vb[b[i] - 'a'].first++;
    }

    sort(va.begin(), va.end());
    sort(vb.begin(), vb.end());

    for (int i = 0; i < 26; i++) {
        if (va[i].first == vb[i].first ) {
            int cnt = 0;
            for (int j = 0; j < n; j++) {
                if (a[j] == b[j] && a[j]-'a' == va[i].second)    cnt++;
            }
            if (cnt == va[i].first) {
                va[i].first = vb[i].first = 0;
            }
        }
    }

    go(va, vb, 25, 0);

    if (ans == 1e9) cout << -1;
    else cout << ans;

    return 0;
}

/*
  문자열 a,b,가 주어진다.
  한번의 연산으로 a의 알파벳 x->y로 바꿀수 있다. ex) aaab -> bbbb or cccb or dddb ...
  a == b가 되기 위한 연산의 최소횟수를 계산해라

  a,b의 문자 등장횟수를 각각 계산한다.(va, vb)
  최소 횟수를 계산해야 하므로, a와 b의 문자 등장이 일치하는게 있으면 제외시킨다 (60~67)
  이렇게 전처리를 해주고, 나머지 경우를 완탐 돌린다
  소문자 갯수가 26이므로 될줄 알았는데 26! 인가?
*/
