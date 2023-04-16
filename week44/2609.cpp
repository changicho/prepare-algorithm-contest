class Solution {
public:
    int findTheLongestBalancedSubstring(string s) {
        int n = s.size(), ans = 0;
        for (int i=0; i<s.size(); i++){
            int numZero = 0, numOne = 0, idx = i;
            while (idx < n && s[idx] == '0'){
                numZero++;
                idx++;
            }
            while (idx < n && s[idx] == '1'){
                numOne++;
                idx++;
            }
            if (numOne >= numZero)  ans = max(ans, numZero*2);
        }
        return ans;
    }
};
