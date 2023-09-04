class Solution {
public:
    vector<int> leftRigthDifference(vector<int>& v) {
        int n = v.size();
        vector<int> lsum(n, 0);
        for (int i=1; i<n; i++) lsum[i] = lsum[i-1] + v[i-1];
        vector<int> rsum(n, 0);
        for (int i=n-2; i>=0; i--)  rsum[i] = rsum[i+1] + v[i+1];
        vector<int> ans(n, 0);
        for (int i=0; i<n; i++) ans[i] = abs(lsum[i] - rsum[i]);
        return ans;
    }
};
