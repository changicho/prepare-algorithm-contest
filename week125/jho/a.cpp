#include<bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int x, y, z;

    cin >> x >> y >> z;

    double result = (double) (x - y * z) / (double) (z - 1);

    if (result >= 0.0 && floor(result) == result) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }

    /*
     *
     * (x + a) = (y + a) * z
     * x - yz = za - a
     * (x - yz)/(z - 1) = a
     *
     */
    
    return 0;
}

//https://atcoder.jp/contests/abc433/tasks/abc433_a
