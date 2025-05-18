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

    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++)    cin >> v[i];
    vector<pair<char, long long>> cnt;
    for (int i = 0; i < n-1; i++) {
        if (v[i] > v[i + 1]) {
            if (cnt.empty() || cnt.back().first == '<') cnt.push_back({ '>', 1 });
            else cnt.back().second++;
        }
        else {
            if (cnt.empty() || cnt.back().first == '>') cnt.push_back({ '<', 1 });
            else cnt.back().second++;
        }
    }
    long long ans = 0;
    for (int i = 1; i < cnt.size() - 1; i++)  if (cnt[i].first == '>') ans += cnt[i - 1].second * cnt[i + 1].second;
    cout << ans;
    return 0;
}

/*
*   v[i] < v[i+1]일 때를 문자 '>', 반대의 경우를 '<'라 표현하자. (순열이므로 같은 경우는 존재하지 않음)
    그러면 v를 길이가 n-1인 문자열 v`로 표현할 수 있다. ex) v` = "<<><<><><<><"
    v`에서 같은 부호를 기호 + 숫자로 압축할수 있다. ex) <<< = { <, 3 }
    cnt는 위의 설명한 압축 문자열이다.

    cnt[i] = { >, x }라 하자.
    그렇다면 조건상 항상 cnt[i-1] = { <, y }, cnt[i+1] = { <, z }이여야 한다.
    이를 나타내면 
    v[0..y-1] < v[i] > v[i+1...i+x-1] < v[i+x...i+x+z] 이다.

         v[i]
       /     \          /
      /       \        /
     /         \      /
    /           v[i+x]

    따라서 cnt[i] = '>' 일 때, cnt[i-1].second * cnt[i+1].second 가 경우의 수로 존재할 수 있다. 


    ex) 1,2,5,3,4 = <2, >1, <1
    조건을 만족하는 경우는 1,2,5,3,4 / 2,5,3,4
    ex ) 1,2,3,7,6,4,5 = <3, >2, <1
    1,2,3 or 2,3, or 3 + 7,6,4, + 5
    ex ) 1,2,3,8,7,4,5,6 = <3, >2, <2
    1,2,3 or 2,3, or 3 + 8,7,4, + 5 or 5,6
*/
