#include <vector>
#include <algorithm>
using namespace std;

bool cmp(pair<int,int>& a, pair<int, int>& b) {
    return a.first > b.first;
}

class Solution {
public:
    int miceAndCheese(vector<int>& reward1, vector<int>& reward2, int k) {
        int n = reward1.size();
        vector<pair<int,int>> diff;
        for (int i = 0; i < n; i++) {
            diff.push_back({ reward1[i] - reward2[i], i });
        }
        sort(diff.begin(), diff.end(), cmp);
        vector<int> visit(n, 0);
        for (int i = 0; i < n && i < k; i++) {
            visit[diff[i].second]++;
        }
        int ans = 0;
        for (int i = 0; i < n; i++) {
            ans += visit[i] ? reward1[i] : reward2[i];
        }
        return ans;
    }
};
