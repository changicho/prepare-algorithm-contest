#include<bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tCount;
    cin >> tCount;
    for (int temp = 0; temp < tCount; temp++) {
        long long n, h;
        cin >> n >> h;
        long long minUpper = h;
        long long maxLower = h;
        long long curTime = 0;
        bool result = true;
        for (int i = 0; i < n; i++) {
            long long t, l, u;
            cin >> t >> l >> u;
            long long offset = t - curTime;
            minUpper += offset;
            maxLower -= offset;
            if (maxLower < 0L) {
                maxLower = 0L;
            }

            if (minUpper < u) {
                if (minUpper < l) {
                    result = false;
                } else {
                    if (maxLower < l) {
                        maxLower = l;
                    }
                }
            } else {
                if (maxLower > u) {
                    result = false;
                } else {
                    minUpper = u;
                    if (maxLower < l) {
                        maxLower = l;
                    }
                }
            }
            curTime = t;
        }

        if (result) {
            cout << "Yes" << endl;
        } else {
            cout << "No" << endl;
        }
    }

    return 0;
}
