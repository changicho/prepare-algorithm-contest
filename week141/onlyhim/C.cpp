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
#include <cmath>

using namespace std;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    string str;
    long long ans = 0;
    cin >> str;
    for (int i = 0; i < str.size(); i++) {
        if (str[i] == 'C') {
            int lefts = i;
            int rights = str.size() - 1 - i;
			int mins = min(lefts, rights);
			ans += mins+1;
        }
    }
    cout << ans << '\n';

    return 0;

}
 
/*
현재 문자가 C이면 양 옆의 문자가 몇개 있는지 세고, 작은 문자 갯수 값 기준으로 누적해간다.
*/
