class Solution {
public:
    int minRectanglesToCoverPoints(vector<vector<int>>& points, int w) {
        set<int> sets;
        for (int i = 0; i < points.size(); i++) sets.insert(points[i][0]);
        int ans = 0, startX;
        bool isFirst = 0;
        for (auto it : sets) {
            if (isFirst == 0) {
                ans++;
                startX = it;
                isFirst = 1;
            }
            else {
                if (it - startX > w) {
                    ans++;
                    startX = it;
                }
            }
        }
        return ans;
    }
};

/*
    정수 w와 2차원 평면의 좌표 (x[i], y[i])가 주어진다.
    평면의 모든 좌표를 커버하는 직사각형의 최소 갯수를 계산해라.
    단 직사각형의 가로축의 최대길이는 w이다.
    
    set에 x좌표 넣고 순회하면서 다음 좌표값과의 거리가 w보다 커지면 값을 갱신
    O(n) / O(n)
*/
