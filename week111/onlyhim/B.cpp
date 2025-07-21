#define _CRT_SECURE_NO_WARNINGS

#include <vector>
#include <iostream>
#include <string>
#include <algorithm>
#include <numeric>
#include <set>
#include <cmath>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <map>
#include <climits>
using namespace std;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string str;
    cin >> str;
    int prv = -1, cur;
    for (int i = 0; i < str.size(); i++) {
        if (str[i] == '.')  continue;
        if (prv == -1)  prv = i;
        else {
            cout << prv+1 << "," << i+1 << '\n';
            prv = -1;
        }
    }
    return 0;
}

/*
* O(N)
*/
