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

    int qry;
    cin >> qry;
    queue<pair<int, int>> q;
    for (int i = 0; i < qry; i++) {
        int val;
        cin >> val;
        if (val == 1) {
            int numVal, Val;
            cin >> numVal >> Val;
            q.push({ numVal,Val });
        }
        else {
            long long sums = 0;
            int k;
            cin >> k;
            while (!q.empty() && k) {
                pair<int, int> cur = q.front();
                if (cur.first > k) {
                    sums += (long long)(cur.second) * k;
                    q.front().first -= k;
                    k = 0;
                }
                else {
                    sums += (long long)(cur.second) * cur.first;
                    k -= cur.first;
                    q.pop();
                }
            }
            cout << sums << '\n';
        }
    }
    return 0;
}

/*
* 쿼리 1; 큐에 pair 형태로 push한다. O(1)
* 쿼리 2; 큐에서 pop 하면서 k를 감소시킨다. q.top > k 이면 top의 값을 조절해서 다시 push
* O(q)이지만 q<=10^5이고, 쿼리 1에서 항상 q는 1만큼만 증가
*/
