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

long long ans;

void go(vector<vector<int>>& v, vector<int>& zooCnt, vector<int>& animCnt, vector<int>& costv, int curZoo, long long cost) {
    if (cost >= ans) return;
    bool isAllSeen = 1;
    for (int i = 0; i < animCnt.size() && isAllSeen; i++)
        if (animCnt[i] > 0) isAllSeen = 0;

    if (isAllSeen && ans > cost) {
        ans = min(ans, cost);
        return;
    }

    if (curZoo >= zooCnt.size())    return;


    go(v, zooCnt, animCnt, costv, curZoo+1, cost);
    for (int i = 0; i < v[curZoo].size(); i++) {
        int curAnim = v[curZoo][i];
        animCnt[curAnim]--;
    }
    go(v, zooCnt, animCnt, costv, curZoo + 1, cost + costv[curZoo]);
    for (int i = 0; i < v[curZoo].size(); i++) {
        int curAnim = v[curZoo][i];
        animCnt[curAnim]++;
    }
    for (int i = 0; i < v[curZoo].size(); i++) {
        int curAnim = v[curZoo][i];
        animCnt[curAnim]-=2;
    }
    go(v, zooCnt, animCnt, costv, curZoo + 1, cost + costv[curZoo] * 2);
    for (int i = 0; i < v[curZoo].size(); i++) {
        int curAnim = v[curZoo][i];
        animCnt[curAnim] += 2;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ans = LONG_MAX;
    int numZoo, numAnimal;
    cin >> numZoo >> numAnimal;
    vector<int> costv(numZoo);
    for (int i = 0; i < numZoo; i++)    cin >> costv[i];
    vector<vector<int>> zooAnimList(numZoo);
    for (int i = 0; i < numAnimal; i++) {
        int val;
        cin >> val;
        for (int j = 0; j < val; j++) {
            int zoo;
            cin >> zoo;
            zoo--;
            zooAnimList[zoo].push_back(i);
        }
    }
    vector<int> animCnt(numAnimal, 2);
    vector<int> zooCnt(numZoo, 2);
    go(zooAnimList, zooCnt, animCnt, costv, 0, 0);
    cout << ans;
    return 0;
}

/*
    동물원수 = n<=10, 동물수 = m<=100
    특정 동물원은 최대 2번만 방문해도 된다.
    따라서 방문하는 경우의수는 0,1,2 = 3가지
    각 방문마다 모든 동물을 2번씩 봤는지 확인하고 비용을 갱신한다. 
    O(3^n * n * m) = 약 10^7

    단 zoo를 순회하는 방법은 TLE
*/
