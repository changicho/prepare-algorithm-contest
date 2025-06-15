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
#include <stack>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t = 1;
    
    while (t--) {
        int n, q, idx = 0;
        cin >> n >> q;
        vector<int> v(n + 1);
        for (int i = 0; i < n; i++)    v[i] = i+1;
        for (int i = 0; i < q; i++) {
            int key, targetIdx, val;
            cin >> key;
            if (key == 1) {
                cin >> targetIdx >> val;
                targetIdx--;
                targetIdx = (targetIdx + idx) % n;
                v[targetIdx] = val;
            }
            else if (key == 2) {
                cin >> targetIdx;
                targetIdx--;
                targetIdx = (targetIdx + idx) % n;
                cout << v[targetIdx] << '\n';
            }
            else {
                cin >> val;
                idx = (idx + val) % n;
            }
        }
    }

    return 0;
}

/*
    쿼리1; a[i] = x로 값 변경
    쿼리2; a[i] 출력
    쿼리3; a의 첫 원소를 k번 만큼 move to end
    
    a[0] a[1] a[2] a[3]에서 k = 2라면
    a[2] a[3] a[0] a[1]
    idx 0->2, 1->3, 2->0, 3->1로 변경된다.
    따라서 idx = (idx + k) % n으로 조절
*/
