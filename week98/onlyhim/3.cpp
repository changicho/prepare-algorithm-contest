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
using namespace std;

int solution(vector<vector<int>> info, int n, int m) {
	vector < vector<vector<int>>> visit(125, vector < vector<int>>(125, vector<int>(40, 1e9)));

    priority_queue<vector<int>> pq;
    if (info[0][0] < n) {
        pq.push({ -info[0][0], 0, 0});
        visit[info[0][0]][0][0] = info[0][0];
    }
    if (info[0][1] < m) {
        pq.push({ 0, info[0][1], 0});
        visit[0][info[0][1]][0] = info[0][1];
    }

    while (!pq.empty()) {
        vector<int> cur = pq.top();
        pq.pop();
        int aCost = -cur[0], bCost = cur[1], idx = cur[2];
        if (idx == info.size()-1) return aCost;
        int nextACost = info[idx + 1][0], nextBCost = info[idx + 1][1];

        if (nextACost + aCost < n && visit[aCost + nextACost][bCost][idx + 1] > visit[aCost][bCost][idx] + nextACost) {
            visit[aCost + nextACost][bCost][idx + 1] = visit[aCost][bCost][idx] + nextACost;
            pq.push({ -(aCost + nextACost), bCost, idx + 1 });
        }
        if (nextBCost + bCost < m && visit[aCost][bCost + nextBCost][idx + 1] > visit[aCost][bCost][idx] + nextBCost) {
            visit[aCost][bCost + nextBCost][idx + 1] = visit[aCost][bCost][idx] + nextBCost;
            pq.push({ -aCost, bCost + nextBCost, idx + 1 });
        }
    }

    return -1;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    //vector<vector<int>> v = {{1, 2}, {2, 3}, {2, 1}};
    vector<vector<int>> v = {{3, 3}, {3, 3}};
    solution(v, 6,1);
}

/*
* visit[i][j][k] = a의 흔적이 i, b의 흔적이 j, 현재 물건이 k일때 a도둑의 최소 흔적
* a의 흔적을 오름차순 우선순위로 하는 pq를 사용해 bfs
*/
