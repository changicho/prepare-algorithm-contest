class Solution {
public:
    vector<string> stringSequence(string str) {
        vector<string> ans;
        int idx = 0;
        string target = "";
        for (int i=0; i<str.size(); i++) {
            target += 'a';
            idx++;
            ans.push_back(target);
            while (target[idx-1] != str[i])    {
                target[idx-1] = target[idx-1] + 1 > 'z' ? 'a' : target[idx-1] + 1;
                ans.push_back(target);
            }
        }
        return ans;
    }
};

/*
    문자열 s가 주어진다.
    s를 만들기 위해 2가지 연산중 한개를 수행할 수 있다.
    1. 현재 문자열에 'a'를 더한다.
    2. 현재 문자열의 마지막 문자를 다음 문자로 변환한다 (ex. a->b, z->a)
    s를 만들기 위한 연산의 결과를 모두 계산해라

    1,2의 과정을 단순구현
    O(N) / O(N)
*/
