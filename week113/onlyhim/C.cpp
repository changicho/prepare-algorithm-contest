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
    
    long long ans = 0;
    int n;
    cin >> n;
    vector<int> v(n+1);
    for (int i = 1; i <= n; i++) cin >> v[i];

    unordered_map<int, int> um;
    for (int i = 1; i <= n; i++) um[i + v[i]]++;
    for (int i = 1; i <= n; i++) {
        int key = i - v[i];
        if (um.count(key))  ans += um[key];
        um[i + v[i]]++;
    }
    cout << ans/2;
    return 0;
}

/*
* j-i == a[i] + a[j] -> j - a[j] == a[i] + i
* 1. 1~n을 순회하면서 a[i] + i인 경우의 수를 모두 계산한다. 
* 2. 1~n을 순회하면서 
*/
