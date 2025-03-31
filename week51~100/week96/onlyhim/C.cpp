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

int n, m;
int minX, minY, maxX, maxY;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;
    vector<vector<char>> v(n, vector<char>(m));
    vector<vector<bool>> visit(n, vector<bool>(m, 0));

    minX = minY = 1e9;
    maxX = maxY = -1;
    for (int i = 0; i < n; i++) {
        string str;
        cin >> str;
        for (int j = 0; j < m; j++) {
            v[i][j] = str[j];
            if (str[j] == '#') {
                minX = min(minX, j);
                minY = min(minY, i);
                maxX = max(maxX, j);
                maxY = max(maxY, i);
            }
        }
    }

    for (int i = minY; i <= maxY; i++) {
        for (int j = minX; j <= maxX; j++) {
            if (v[i][j] == '.') {
                cout << "No\n";
                return 0;
            }
        }
    }
    cout << "Yes\n";
}

/*
* 크기가 n,m(<=10^3)인 2차원 배열이 주어진다. 각 cell은 black or white or ?
* ?로 표시된 cell은 black or white로 칠할 수 있다.
* 색칠한 모든 black cell이 직사각형인 경우가 존재하는가?
* 
* 1. 모든 black cell은 반드시 포함되어야 하므로, black cell의 최소 & 최대 x,y를 구해놓는다.
    ex.
    #.......
    ........
    .......#
    인 경우, 두 black cell이 포함된 직사각형은 최소 모든 cell을 포함해야 한다
* 2. miny ~ maxy, minx ~ maxx 를 순회하면서 white cell이 있는지 확인한다.
* 
* 
*/
