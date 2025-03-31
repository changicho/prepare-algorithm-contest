class Solution {
public:
    int numberOfSubstrings(string s, int k) {
        int n = s.size(), ans = 0;
        for (int i = 0; i < n; i++) {
            vector<int> v(26, 0);
            for (int j = i; j < n; j++) {
                v[s[j] - 'a']++;
                int maxAppear = 0;
                for (auto it : v)    maxAppear = max(maxAppear, it);
                if (maxAppear >= k) ans++;
            }
        }
        return ans;
    }
};

/*
    문자열 s와 정수 k가 주어진다.
    s의 substring중 최소 k개의 any character가 등장하는 경우의 수를 계산해라. |s| <= 3000

    i = substring의 시작, j = substring의 끝, v[q] = 문자 q의 등장횟수라 하자. 
    i~j를 돌면서 v[i]를 하나씩 더해간다.
    가장 큰 v[i] 값 >= k 이면 답을 하나씩 더해간다.
    O(N^2) / O(N^2)


*/
