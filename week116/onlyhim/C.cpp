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
using namespace std;


long long solve(const string& s, const string& target) {
    vector<int> posA, targetA;
    for (int i = 0; i < (int)s.size(); i++) {
        if (s[i] == 'A') posA.push_back(i);
        if (target[i] == 'A') targetA.push_back(i);
    }

    long long cost = 0;
    for (int i = 0; i < (int)posA.size(); i++) {
        cost += abs(posA[i] - targetA[i]);
    }
    return cost;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    string str;
    cin >> n >> str; // str 길이가 2n이라고 가정

    string target1, target2;
    for (int i = 0; i < 2 * n; i++) {
        target1 += (i % 2 == 0 ? 'A' : 'B'); // ABAB...
        target2 += (i % 2 == 0 ? 'B' : 'A'); // BABA...
    }

    long long ans1 = solve(str, target1);
    long long ans2 = solve(str, target2);

    cout << min(ans1, ans2) << "\n";
    return 0;
}
 
/*
* 정수 n과 길이가 2n인 문자열이 주어진다.
* s[i] = a or b일때, 1번의 연산으로 인접한 s[i]를 swap할 수 있다.
* 모든 s[i] != s[i+1]이 되도록 만들기 위한 최소 연산횟수
* 
* 가능한 경우는 abababab... or babababa...
* s와 각 경우를 비교하여 다른 개수를 센다.
* 
*/
