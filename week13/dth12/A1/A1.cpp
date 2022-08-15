#include <bits/stdc++.h>
 
using namespace std;

int arr[5] = {'A', 'E', 'I', 'O', 'U'};

bool is_vowel(char c) {
    for (int i = 0; i < 5; i++)
    {
        if (arr[i] == c) return true;
    }

    return false;
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int tc;
    cin >> tc;

    for (int t = 1; t <= tc; t++)
    {
        int ans = 201;
        int l;
        string s;

        cin >> s;
        l = s.length();

        for (int i = 0; i < 26; i++)
        {
            char c1 = char('A' + i);
            int temp = 0;

            for (int j = 0; j < l; j++)
            {
                if (c1 == s[j]) continue;
    
                char c2 = s[j];
                bool c1_is_vowel = is_vowel(c1);
                bool c2_is_vowel = is_vowel(c2);

                if (c1_is_vowel == c2_is_vowel) temp += 2;
                if (c1_is_vowel != c2_is_vowel) temp += 1;
            }

            ans = min(ans, temp);
        }

        cout << "Case #" << t << ": " << ans << '\n';
    }
}