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
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        int n, k;
        cin >> n >> k;
        if (n > 1 && k > 1) {
            cout << "NO\n";
        }
        else if (n > 1 && k == 1) {
            bool isPrime = 1;
            for (int i = 2; i <= sqrt((double)n) && isPrime; i++) {
                if (n % i == 0) isPrime = 0;
            }
            if (isPrime)    cout << "YES\n";
            else cout << "NO\n";
        }
        else {
            if (k == 2) cout << "YES\n";
            else cout << "NO\n";
        }
    }
    return 0;
}

/*
* 새로 만들어진 값을 y라 하자.
* x>1이고, k>1이면 y는 항상 소수가 될 수 없다. 
* k=1인 경우, x가 소수인지를 체크하면 된다 -> O(logk)
* x=1인 경우, y = 11...1 이다. 이 때 소수는 11밖에 없다.
*/
