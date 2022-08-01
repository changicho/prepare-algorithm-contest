#include <bits/stdc++.h>

using namespace std;

int arr[10001];
int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int tc;
    cin >> tc;

    while(tc--) 
    {
        int num;
        cin >> num;

        if (num % 2 == 0) 
        {
            for (int i = 1; i <= num / 2; i++ ) {
                int even = i * 2;
                
                cout << even << ' ' << even - 1 << ' ';
            }
            cout << '\n';
        }
        else 
        {   
            cout << num << ' ';
            for (int i = 1; i <= num / 2; i++ ) {
                int even = i * 2;
                
                cout << even - 1 << ' ' << even << ' ';
            }
            cout << '\n';
        }
    }
    
}