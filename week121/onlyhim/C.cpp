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

    long long ans = 0;
    int n;
    cin >> n;
	map<int, int> mp;
    vector<int> visit(n + 1, 0);
	vector<int> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
        mp[v[i]]++;
    }
    for (int i = 0; i < n; i++) {
        int cur = v[i];
        if (mp.find(cur) == mp.end() || mp[cur] <= 1)   continue;
        if (visit[cur] == 0) {
            visit[cur]++;
        }
        else {
            visit[cur]++;
            long long diffNum = n - mp[cur];
			ans += diffNum * (long long)(mp[cur] - visit[cur] + 1);
        }
    }
    cout << ans;
    return 0;
}
 
/*
집합 (i,j,k)에서 i<j<k이고 v[i], v[j], v[k]에서 2개 원소의 값이 같고 1개만 다른 경우의 수를 구해라
v[i] = k인 갯수를 hash table로 계산해둔다.
v[i] = k인 갯수가 2이상인 원소가 있을 때만 다음의 연산을 한다.
1. 첫번째 방문인 경우, 아직 "2개 원소의 값이 같다"는 조건을 만족하지 못하므로 방문 처리만 한다.
2. 1번을 통과한 경우 조건을 만족하므로, 
현재 등장한 원소가 2개인 경우, k를 제외한 모든 원소가 대상이다.

ex) { 1,1,3,5}이고 i=1인 경우, {1,1,3}, {1,1,5}가 가능하다. 따라서 전체 원소 갯수 - k의 등장갯수를 계산한다.
이를 현재 원소의 등장횟수만큼 곱한다.
ex) { 1,1,3,5,1}이고 i=4인 경우, 새롭게 추가된 1을 포함하여 i=0,i=1을 섞어서 3,5와 조합할 수 있다.

O(N)


*/
