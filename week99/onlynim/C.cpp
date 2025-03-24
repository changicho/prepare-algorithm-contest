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


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, ansidx = -1, ansval = -1;
    cin >> n;
    unordered_map<int, int> um;
    vector<int> v(n);
    unordered_set<int> us;
    for (int i = 0; i < n; i++) {
        cin >> v[i];
        if (um.find(v[i]) == um.end())   um[v[i]] = 1;
        else um[v[i]]++;
    }
    for (auto i : um) {
        if (i.second == 1)  us.insert(i.first);
    }
    for (int i = 0; i < v.size(); i++) {
        if (us.find(v[i]) != us.end() && v[i] > ansval) {
            ansval = v[i];
            ansidx = i + 1;
        }
    }
    cout << ansidx;
    return 0;
}

/*
  hash table로 v[i]의 등장 횟수를 모두 카운팅 해놓는다.
  hash table을 순회하면서 등장 횟수가 1인 경우의 값을 모두 기억해놓는다(unordered_set)
  set을 순회하면서 가장 큰 값을 갱신한다.
  O(N) / O(N)
*/
