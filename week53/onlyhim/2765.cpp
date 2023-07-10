class Solution {
public:
    int alternatingSubarray(vector<int>& v) {
        int ans = -1;
        for (int i=1; i<v.size(); i++){
            if (v[i] - v[i-1] == 1){
                int len = 2, idx = i+1;
                while (idx < v.size() && v[idx] == v[idx-2])    {
                    idx++;
                    len++;
                }
                ans = max(ans, len);
            }
        }
        return ans;
    }
};
