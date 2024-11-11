#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <map>
#include <set>
#include <cstring>
using namespace std;

#define DESTRED 3
#define DESTBLUE 4
#define WALL 5

int n, m;
int dp[6][6][6][6];
int goy[4] = { 1, -1, 0, 0 };
int gox[4] = { 0,0,1, -1 };


int go(vector<vector<int>>& v, vector<vector<int>>& visitB, vector<vector<int>>& visitR, int by, int bx, int ry, int rx) {
	if (v[by][bx] == DESTBLUE && v[ry][rx] == DESTRED)  return 0;
	int& ret = dp[by][bx][ry][rx];
	if (ret != -1)   return ret;
	ret = 1e9;
	for (int i = 0; i < 4; i++) {
		int nby = by + goy[i], nbx = bx + gox[i];
		if (v[by][bx] == DESTBLUE)  nby = by, nbx = bx;

		if (nby >= 0 && nbx >= 0 && nby < n && nbx < m && v[nby][nbx] != WALL) {
			if (v[by][bx] == DESTBLUE || visitB[nby][nbx] == 0) {	//	이미 목적지에 도착했거나 방문한적이 없는 경우 

				for (int j = 0; j < 4; j++) {
					int nry = ry + goy[j], nrx = rx + gox[j];
					if (v[ry][rx] == DESTRED)  nry = ry, nrx = rx;	// 목적지 도착
					if (nry >= 0 && nrx >= 0 && nry < n && nrx < m && v[nry][nrx] != WALL) {
						if (v[ry][rx] == DESTRED || visitR[nry][nrx] == 0) {	//	이미 목적지에 도착했거나 방문한적이 없는 경우 
							if (nby == nry && nbx == nrx)   continue;	// 동시에 같은칸 x
							if (nby == ry && nbx == rx && nry == by && nrx == bx) continue;	// 수레끼리 자리 교환 x
							visitB[nby][nbx] = 1;
							visitR[nry][nrx] = 1;
							ret = min(ret, go(v, visitB, visitR, nby, nbx, nry, nrx) + 1);
							visitB[nby][nbx] = 0;
							visitR[nry][nrx] = 0;
						}
					}
				}
			}
		}
	}
	return ret;
}


int solution(vector<vector<int>> maze) {
	n = maze.size(), m = maze[0].size();
	vector<vector<int>> visitB(n, vector<int>(m, 0));
	vector<vector<int>> visitR(n, vector<int>(m, 0));
	memset(dp, -1, sizeof(dp));
	int by, bx, ry, rx;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (maze[i][j] == 1)    ry = i, rx = j;
			if (maze[i][j] == 2)    by = i, bx = j;
		}
	}
	visitR[ry][rx] = 1;
	visitB[by][bx] = 1;
	int ans = go(maze, visitB, visitR, by, bx, ry, rx);
	return ans >= 1e9 ? 0 : ans;
}

/*
	dp[a][b][c][d] = 빨간 수레의 위치가 (a,b), 파란 수레의 위치가 (c,d) 일 때의 최소 이동 횟수
*/
