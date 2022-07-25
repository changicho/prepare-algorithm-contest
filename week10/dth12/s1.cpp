#include <bits/stdc++.h>

using namespace std;

int arr[10001];
int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int tc;
    cin >> tc;

    for (int t = 1; t <= tc; t++) {
        float ans = 0.0;
        int N, M;
        cin >> N >> M;
        for (int i = 1; i <= N; i++) {
            int tmp;
            cin >> tmp;
            arr[i] = tmp;
        }
        
        int diff = N - M + 1;
        sort(arr, arr + N + 1);

        for (int i = N; i > diff; i--) {
            ans += arr[i];
        }
        
        if (diff % 2 == 1) {
            ans += arr[diff / 2 + 1];
        } else {
            ans += (arr[diff / 2 + 1] + arr[diff / 2]) / 2.0;
        }

        cout << "Case #" << t << ": " << ans;
    }
    
}