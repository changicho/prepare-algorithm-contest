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
        string str;
        cin >> str;
        int cnt = 0;
        bool ans = 1;
        for (int i = 0; i < str.size() && ans; i++) {
            if (i != 0 && cnt == 0) ans = 0;
            if (str[i] == '(')  cnt++;
            else cnt--;
        }
        if (ans)    cout << "NO\n";
        else cout << "YES\n";
    }

    return 0;
}

/*
* 문자열 중간에 balanced bracket이 존재한다면, 한 개의 bracket을 제거하는 것으로 unbalanced 상태가 된다
*/
