class Solution {
public:
    int maxNumOfMarkedIndices(vector<int>& v) {
        sort(v.begin(), v.end());
        int ans = 0, idx = 0;
        for (int i = v.size()/2; i < v.size() && idx < v.size()/2; i++){
            if (v[idx] * 2 <= v[i]) ans+=2, idx++;
        }
        return ans;
    }
};
