#include <bits/stdc++.h>
 
using namespace std;
 
int nums[200001];
int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
 
    int tc;
    cin >> tc;
 
    while(tc--)
    {
        int n;
        int m = 9;
        int temp = 0;
        cin >> n;
 
        while (true)
        {
            if (temp + m >= n)
            {
                break;
            }
            else
            {
                temp += m;
                m--;
            }
        }
 
        for (int i = 0; i <= m; i++)
        {
            if (temp + i == n)
            {   
                cout << i;
                for (int j = m + 1; j <= 9; j++)
                {
                    cout << j;
                }
                cout << '\n';
                break;
            }
        }
    }
}