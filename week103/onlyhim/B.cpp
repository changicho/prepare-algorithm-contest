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

    int t, cnt;
    cin >> t;
    string str;
    for (int i = 0; i < t; i++) {
        cin >> str;
        cnt = 0;
        int backIdx = str.size() - 1;
        while (backIdx >= 0 && str[backIdx] == '0') {
            backIdx--;
            cnt++;
        }
        backIdx--;
        while (backIdx >= 0) {
            if (str[backIdx] != '0')    cnt++;
            backIdx--;
        }
        cout << cnt << '\n';
    }
    return 0;
}

/*
* 정수 n의 digit중 아무거나 제거할 수 있다(leading zero 가능, 0보다 커야한다)
* 103554 -> 035
* 이를 통해 만들어진 정수를 m이라 할 때, m의 cost는 035/3+5 = 4.375라 한다.
* 
* cost가 최소값이 되기위해 제거해야 하는 digit의 최소 갯수는?
* 정수 1개만 남기는 경우가 항상 최소값이다. 
* 1. 뒤에서 부터 순회하면서 0이 있는 경우는 모두 제거한다.
* 2. 최초로 0이 아닌 정수가 나타난 경우, 해당 값을 건너뛴다.
* 3. 2에서 건너뛴 인덱스부터 다시 순회하면서 0인 경우를 제외하고 모두 제거한다 (leading zero가 가능하므로)
* 
* O(1)
* 
*/
