#include <bits/stdc++.h>
 
using namespace std;

void cout_no(int tc) {
    cout << "Case #" << tc << ": " << "NO" << '\n';
}

void cout_yes(int tc) {
    cout << "Case #" << tc << ": " << "YES" << '\n';
}

bool is_existed_three(int* arr) {
    for (int i = 0; i < 101; i++)
    {
        if (arr[i] >= 3)
        {
            return true;
        }
    }

    return false;
}   

int style[101];

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int ntc;
    cin >> ntc;
    
    for (int tc = 1; tc <= ntc; tc++)
    {
        int N, K;
        cin >> N >> K;

        for (int i = 0; i < 101; i++)
        {
            style[i] = 0;
        }

        for (int i = 0; i < N; i++)
        {  
            int temp;
            cin >> temp;
            style[temp]++;
        }

        if (K * 2 < N)
        {
            cout_no(tc);
        }
        else if (is_existed_three(style))
        {
            cout_no(tc);
        }
        else
        {
            cout_yes(tc);
        }
    }
}