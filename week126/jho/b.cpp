#include<bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    vector<int> v(m + 1, 0);
    vector<int> countV(m + 1, 0);
    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        v[a] += b;
        countV[a]++;
    }

    for (int i = 1; i < v.size(); i++) {
        cout << (double) v[i] / (double) countV[i] << endl;
    }
    
    return 0;
}
