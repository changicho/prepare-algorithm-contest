#include <bits/stdc++.h>
 
using namespace std;
 
int cnt[200001];
int nums[200001];
int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
 
    int tc;
    cin >> tc;
 
    while(tc--)
    {
        int n, ans, total;
        total = 0;
        ans = 0;
        cin >> n;
 
        for (int i = 1; i <= n; i++)
        {
            cnt[i] = 0;
        }
 
        for (int i = 1; i <= n; i++)
        {
            int temp;
            cin >> temp;
            cnt[temp]++;
            nums[i] = temp;
 
            if (cnt[temp] == 2) total++;
        }
 
        for (int i = 1; i <= n; i++)
        {
            if (total == 0) break;
            int num = nums[i];
            cnt[num]--;
            ans++;
 
            if (cnt[num] == 1) total--;
        }
 
        cout << ans << '\n';
    }
}