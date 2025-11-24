#include<bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string s;
    cin >> s;

    long long result = 0;
    long long index = 0;
    while (index < s.length() - 1) {
        if ((char) (s[index] + 1) == s[index + 1]) {
            long long offset = 1;
            while ((int)(index - offset + 1) >= 0 && (int) (index + offset) < (int) s.length()) {
                if ((char) (s[index - offset + 1] + 1) == s[index + offset]) {
                    offset++;
                    if (s[index - offset + 1] != s[index - offset + 2]) {
                        break;
                    }
                } else {
                    break;
                }
            }
            result += offset - 1;
            index += offset - 2;
        }
        index++;
    }

    cout << result << endl;

    
    return 0;
}

//https://atcoder.jp/contests/abc433/tasks/abc433_c
