#define _CRT_SECURE_NO_WARNINGS

#include <vector>
#include <iostream>
#include <string>
#include <algorithm>
#include <numeric>
#include <set>
#include <cmath>
#include <queue>
using namespace std;

int d,n,m;
int goy[4] = {1, -1, 0 , 0};
int gox[4] = {0,0,1, -1};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
    int ans = 0;
    cin>>n>>m>>d;
    vector<vector<char>> v(n, vector<char>(m));
    priority_queue<vector<int>, vector<vector<int>>> pq;
    vector<vector<bool>> visit(n, vector<bool>(m, 0));
    for (int i =0; i<n; i++) {
        for (int j=0; j<m; j++) {
            cin>>v[i][j];
            if (v[i][j] == 'H') {
                pq.push({d, i, j});
                visit[i][j] = 1;
            }
        }
    }

    while (!pq.empty()) {
        vector<int> cur = pq.top();
        pq.pop();
        int curDist = cur[0], cy = cur[1], cx = cur[2];
        ans++;
        //cout<<cy<<' '<<cx<<endl;
        if (curDist == 0)   continue;
        for (int i=0; i<4; i++) {
            int ny = cy+ goy[i], nx = cx + gox[i];
            if (ny <0 || nx < 0 || ny >= n || nx >= m || visit[ny][nx] || v[ny][nx]=='#')  continue;
            visit[ny][nx] = 1;
            pq.push({curDist -1, ny, nx});
        }
    }
    cout<<ans;
}

/*
*/	
