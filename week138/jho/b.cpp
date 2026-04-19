
#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, M;
    cin >> N >> M;

    vector<int> F(N);
    for (int i = 0; i < N; i++) {
        cin >> F[i];
    }

    // set으로 중복 제거
    set<int> s(F.begin(), F.end());
    
    if ((int)s.size() == N) {
        cout << "Yes\n";
    } else {
        cout << "No\n";
    }
    
    bool all_exist = true;
    for (int i = 1; i <= M; i++) {
        if (s.find(i) == s.end()) {
            all_exist = false;
            break;
        }
    }

    if (all_exist) {
        cout << "Yes\n";
    } else {
        cout << "No\n";
    }

    return 0;
}
