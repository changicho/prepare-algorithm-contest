// Created on iPad.

#include <iostream>
#include <queue>
#include <vector>
#include <map>

using namespace std;

int main() {
    cin.tie(NULL);
    cout.tie(NULL);

    int n,first,last,a,b,ans = 0;
    cin>>n;
    vector<pair<int,int>> v(n);
    for (int i=0; i<n; i++) {
        cin>>v[i].first>>v[i].second;
    }
    ans = v[0].second;
    for (int i=1; i<n; i++) {
        int times = v[i].first - v[i-1].first;
        ans = max(0, ans - times);
        ans += v[i].second;
    }
    cout <<ans;
    return 0;
}
