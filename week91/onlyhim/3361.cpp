class Solution {
public:
    long long shiftDistance(string s, string t, vector<int>& nextCost, vector<int>& previousCost) {
        long long ans = 0;
        for (int i = 0; i < s.size(); i++) {
            long long nCost = 0, pCost = 0;
            int nextIdx = s[i] - 'a', prvIdx = s[i] - 'a', targetIdx = t[i] - 'a';
            while (nextIdx != targetIdx) {
                nCost += nextCost[nextIdx++];
                if (nextIdx >= 26)  nextIdx = 0;
            }
            while (prvIdx != targetIdx) {
                pCost += previousCost[prvIdx--];
                if (prvIdx < 0)  prvIdx = 25;
            }
            ans += min(nCost, pCost);
        }
        return ans;
    }
};

/*
    s[i] -> t[i]는 독립시행이므로 1. next로만 바꿀때 비용 2. prev로만 바꿀때 비용을 계산하고 min(1,2)를 답에 더해나간다.
    O(N)
*/
