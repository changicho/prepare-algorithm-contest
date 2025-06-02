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

    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        string str;
        cin >> str;
        int numZero = 0, numOne = 0, numMismatch = 0;
        for (int i = 0; i < n / 2; i++) {
            if (str[i] == str[n - 1 - i]) {
                if (str[i] == '0')   numZero++;
                else numOne++;
            }
            else numMismatch++;
        }
        bool ans = 0;
        int sums = numZero + numOne;
        if (k > sums) {
            int diff = k - sums;
            if (diff % 2 == 0 && numMismatch / 2 * 2 + sums >= k) ans = 1;
        }
        else if (k < sums) {
            int diff = sums - k;
            if (diff % 2 == 0 && sums - min(numZero, numOne) * 2 <= k)  ans = 1;
        }
        else ans = 1;

        if (ans)    cout << "yes\n";
        else cout << "no\n";
    }

    return 0;
}

/*
    binary string이 주어진다.
    mismatch인 경우는 항상 0,1 or 1,0인 경우이므로 2개를 합쳐서 0,0, 1,1로 2개 만들 수 있다.
    sums = 이미 만들어진 0,0 / 1,1의 pair의 합이라 하자.

    1. k > sums
    mismatch는 항상 2개씩 만들어지므로 홀수인지 확인하고, 더 만들수 있는지 확인
    2. k < sums
    0,0과 1,1 을 분리하여 0,1 / 1,0을 만들 수 있으므로 반드시 각 한개씩 사용해야 한다.

*/
