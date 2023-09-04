#include <bits/stdc++.h>
 
using namespace std;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int ntc;
    cin >> ntc;
    
    for (int tc = 1; tc <= ntc; tc++)
    {
        int R, C, count_tree = 0;
        cin >> R >> C;

        for (int r = 0; r < R; r++)
        {
            for (int c = 0; c < C; c++)
            {   
                char temp;
                cin >> temp;
                if (temp == '^')
                {
                    count_tree++;
                } 
            }
        }
        if (count_tree == 0)
        {
            cout << "Case #" << tc << ": Possible" << '\n';

            for (int r = 0; r < R; r++)
            {
                for (int c = 0; c < C; c++)
                {   
                    cout << '.';
                }

                cout << '\n';
            }
        }
        else if (R == 1 || C == 1)
        {
            cout << "Case #" << tc << ": Impossible" << '\n';
        }
        else
        {
            cout << "Case #" << tc << ": Possible" << '\n';

            for (int r = 0; r < R; r++)
            {
                for (int c = 0; c < C; c++)
                {   
                    cout << '^';
                }

                cout << '\n';
            }
        }
    }
}