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
* 1~N의 정수 배열이 존재
* x,y가 쿼리로 주어지면 x >= v[i]인 모든 v[i]=y로 변경 (x<y)
* 각 쿼리마다 변경되는 v[i]의 갯수
* 
* - 주어진 x가 최소 값보다 작으면 0출력
* - 주어진 x가 최소 값보다는 크고, maxY보다  
*/
