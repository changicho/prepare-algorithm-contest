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

int ans, n;

void go(vector<long long>& v, unordered_set<long long>& us, vector<bool>& visit, int idx) {
    if (idx == v.size()) {
        long long xors = 0;
        for (int i = 0; i < v.size(); i++)  xors ^= v[i];
        if (us.find(xors) == us.end()) {
            ans++;
            us.insert(xors);
        }
        return;
    }

    for (int i = 0; i < idx; i++) {
        if (visit[i] == 0) {
            visit[i] = 1;
            long long org = v[i];
            v[idx] += org;
            v[i] = 0;
            go(v, us, visit, idx + 1);
            v[i] = org;
            v[idx] -= org;
            visit[i] = 0;
        }
    }
    go(v, us, visit, idx + 1);

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ans = 0;
    cin >> n;
    vector<long long> v(n);
    unordered_set<long long> us;
    vector<bool> visit(n, 0);
    for (int i = 0; i < n; i++) cin >> v[i];
    go(v, us, visit, 0);
    cout << ans;
    return 0;
}

/*
* 크기가 n(<=12)인 정수배열 v(v[i] <= 10^17)가 주어진다. 
* v의 원소 중 2개를 골라 v[j] = v[i] + v[j], v[i] = 0으로 만드는 연산을 무한으로 할 수 있다.
* v[0] ^ v[1] ... ^ v[n-1] = x라 할 때, x의 경우의 수를 계산해라
* 
* 
* 현재 위치를 i라 할때, 0~i-1을 순회하면서 다음을 확인한다.
* 현재 순회 위치를 j라 하자.
* 1) v[j]를 연산하지 않는다
* 2) v[j]를 연산에 포함한다 (v[i] += v[j], v[j] = 0)
* 이 때, v[j]는 항상 0이 되므로, 이를 visit 처리 한다. 즉 한번 연산에 포함된 원소는 연산 대상에 포함하지 않아도 된다.
* ex) 1,2,3 -> 0,3,3으로 됐다면, v[2]의 연산 대상에 v[0]은 포함하지 않는다.
* 
* n=12이고 visit으로 인한 pruning이 되어있으므로, 최악의 경우가 크지 않다 (n=12인 경우 약 400만)
*/
