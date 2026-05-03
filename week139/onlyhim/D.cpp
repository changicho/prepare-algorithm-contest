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
#include <cmath>

using namespace std;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, q;
    cin >> n >> q;
    vector<int> child(n + 1, -1);
    vector<int> par(n + 1, -1);
    vector<int> first(n + 1, -1);
	for (int i = 1; i <= n; i++)    first[i] = i;
    for (int i = 0; i < q; i++) {
        int src, dst;
		cin >> src >> dst;

		if (first[src] == src)    
            first[src] = -1;
        if (child[src] != -1)
            par[child[src]] = -1;
        
		child[src] = dst;
		par[dst] = src;
    }
    for (int i = 1; i <= n; i++) {
        int cnt = 0;
        if (first[i] != -1) {
			int cur = first[i];
            while (cur != -1) {
                cnt++;
                cur = par[cur];
            }
        }
        cout << cnt << ' ';
    }
    return 0;
}
 
/*
* 한번 옮기면 쌓여있는 모든 카드가 같이 움직인다.
* 따라서, 현재 이동 대상의 parent, child만 가리키는 위치를 바꿔주고, src의 child도 -1로 처리해준다.
* 
* 
* 예외처리
* 현재 위치에서 모든 카드 더미가 없어지는 경우를 고려해야 한다 (first 배열)
* 문제에서 카드가 움직이는 경우는 항상 다른 카드 더미 -> 카드 더미이므로, 현재 크기가 0인 더미에 다시 쌓이는 경우는 없다.
* 
* 
*/
