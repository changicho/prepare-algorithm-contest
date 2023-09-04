#include <bits/stdc++.h>
 
using namespace std;
 
int arr[200001];
int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
 
    int tc;
    cin >> tc;
 
    while(tc--)
    {
        int n, H, M;
        int diff = 1451;
        cin >> n >> H >> M;
        int minutes = H * 60 + M;
 
        for (int i = 0; i < n; i++)
        {
            int th, tm;
            int temp_diff = 0;
            cin >> th >> tm;
            
            int temp_minutes = th * 60 + tm;
            while (minutes != temp_minutes)
            {   
                if (temp_minutes < 0) {
                    temp_minutes = 1439;
                }; 
                temp_minutes--;
                temp_diff++;
                
            }
 
            diff = min(diff, temp_diff);
        }
 
        cout << diff / 60 << ' ' << diff % 60 << '\n';
    }
}