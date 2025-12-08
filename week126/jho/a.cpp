#include<bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int w, b;

    cin >> w >> b;

    int num = w * 1000 / b;
    cout << num + 1 << endl;
    
    return 0;
}
