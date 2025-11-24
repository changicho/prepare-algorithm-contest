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
#include <tuple>
#include <iomanip>
#include <array>
#include <bit>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
   
    string s;
    long long ans = 0;
    cin >> s;
    for (int i=0; i<s.size()-1; i++) {
        if (s[i] == s[i+1]-1) {
            ans++;
            int l = i - 1, r = i + 2;
            while (l >= 0 && r < s.size() && s[l]==s[i] && s[r] == s[i + 1]) {
                ans++;
                l--;
                r++;
			}
        }
	}
    cout << ans;
    return 0;
}
 
/*
* 
*/
