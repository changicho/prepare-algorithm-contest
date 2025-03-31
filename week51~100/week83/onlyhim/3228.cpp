class Solution {
public:
    int maxOperations(string s) {
        int ans = 0, cnt = 0;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '0') {
                ans += cnt;
                while (i < s.size() && s[i] == '0') i++;
            }
            cnt++;
        }
        return ans;
    }
};

/*
    s[i] = 0인경우
    s[0..i-1]까지의 1의 갯수(=count)를 정답에 더한다.
    1110를 예를 들면, 1101 - 1011 - 0111 이 가능하기 때문
    문제의 조건이 next 1을 만나거나, end of string까지 이동하는 것이기 때문에 다음 s[i+1]이 0이 아닌 경우까지 skip한다.

    s[i] = 1인경우, count + 1


*/
