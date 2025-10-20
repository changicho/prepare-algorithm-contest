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
#include <tuple>
#include <iomanip>
#include <array>
#include <bit>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q, minVal = 1e9, minNum = 0;
    cin >> n >> q;
    priority_queue<pair<int,int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    for (int i = 1; i <= n; i++) {
        pq.push({ i, 1 });
    }
    for (int i = 0; i < q; i++) {
        int x, y;
        cin >> x >> y;
        pair<int, int> next = { y, 0 };
        
        while (!pq.empty() && pq.top().first <= x) {
            pair<int, int> cur = pq.top();
            pq.pop();

            next.second += cur.second;
        }
        cout << next.second << '\n';
        pq.push(next);
    }

    return 0;
}

/*
1~N의 정수 배열이 존재
x,y가 쿼리로 주어지면 x >= v[i]인 모든 v[i]=y로 변경 (x<y)
각 쿼리마다 변경되는 v[i]의 갯수를 출력해라

heap에 오름차순으로 pair값을 넣는다. pair = { 인덱스, 갯수 }
오름차순 정렬되어 있으므로, heap의 top에는 쿼리 x값보다 작은 pair들이 들어있다.
전부 꺼내면서 pair의 second만큼 값을 더하고, 마지막에 다시 pq에 넣는다.
x >= v[i]인 모든 값들이 y로 변경됐기 때문

pair가 한 번 y로 변경된 경우, 이보다 작아지는 경우는 없으므로 O(nlogn)


*/
