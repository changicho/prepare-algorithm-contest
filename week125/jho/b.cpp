#include<bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;

    vector<int> v;
    for (int i = 0; i < n; i ++) {
        int temp;
        cin >> temp;
        v.push_back(temp);
    }

    for (int i = 0; i < v.size(); i++) {
        bool result = false;
        for (int j = i - 1; j >= 0; j--) {
            if (v[i] < v[j]) {
                result = true;
                cout << j + 1 << endl;
                break;
            }
        }

        if (!result) {
            cout << - 1 << endl;
        }
    }
    
    return 0;
}

//https://atcoder.jp/contests/abc433/tasks/abc433_b
