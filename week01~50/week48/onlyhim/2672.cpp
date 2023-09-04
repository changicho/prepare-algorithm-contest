#include <vector>
using namespace std;

class Solution {
public:
    vector<int> colorTheArray(int n, vector<vector<int>>& q) {
        vector<int> v(n, 0);
        vector<int> ans(q.size(), 0);
        if (n == 1)   return ans;
        for (int i = 0; i < q.size(); i++) {
            int idx = q[i][0], color = q[i][1], prevColor = v[idx];
            v[idx] = color;
            if (i == 0)   continue;
            int prevCnt = ans[i - 1];
            if (idx == 0) {
                if (prevColor != 0 && prevColor == v[idx + 1] && prevColor != color)    prevCnt--;
                if (prevColor != color && color == v[idx + 1])   prevCnt++;
                ans[i] = prevCnt;
            }
            else if (idx == n - 1) {
                if (prevColor != 0 && prevColor == v[idx - 1] && prevColor != color)    prevCnt--;
                if (prevColor != color && color == v[idx - 1])   prevCnt++;
                ans[i] = prevCnt;
            }
            else {
                if (prevColor != 0 && v[idx - 1] == prevColor && prevColor != color)    prevCnt--;
                if (prevColor != 0 && v[idx + 1] == prevColor && prevColor != color)    prevCnt--;
                if (prevColor != color && v[idx - 1] == color)  prevCnt++;
                if (prevColor != color && v[idx + 1] == color)  prevCnt++;
                ans[i] = prevCnt;
            }
        }
        return ans;
    }
};
