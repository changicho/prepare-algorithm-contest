#include <vector>
using namespace std;

int n;
int goy[8] = { -1,-2,-2,-1,1,2,2,1 };
int gox[8] = { -2,-1,1,2,2,1,-1,-2 };

bool judge(int y, int x) {
    return y >= 0 && x >= 0 && y < n&& x < n;
}

bool dfs(vector<vector<int>>& v, int y, int x, int cnt) {
    if (cnt == n*n-1) return true;
    for (int i = 0; i < 8; i++) {
        int ny = y + goy[i], nx = x + gox[i];
        if (judge(ny, nx) && v[ny][nx] == cnt + 1)    return dfs(v, ny, nx, cnt + 1);
    }
    return false;
}

class Solution {
public:
    bool checkValidGrid(vector<vector<int>>& grid) {
        n = grid.size();
        if (grid[0][0] != 0)    return 0;
        return dfs(grid, 0, 0, 0);
    }
};
