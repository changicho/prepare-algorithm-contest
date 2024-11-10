#define _CRT_SECURE_NO_WARNINGS

#include <string>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <map>
#include <set>
using namespace std;

int solution(vector<int> bandage, int health, vector<vector<int>> attacks) {
    int ans = 0, idx = 0;
    int bTime = bandage[0], recoverPerSecond = bandage[1], surplusRecover = bandage[2];
    int curHealth = health, surplusTime = 0;
    sort(attacks.begin(), attacks.end());
    for (int i = 0; idx < attacks.size(); i++) {
        if (attacks[idx][0] == i) {
            curHealth -= attacks[idx][1];
            if (curHealth <= 0)  return -1;
            surplusTime = 0;
            idx++;
        }
        else {
            curHealth = curHealth + recoverPerSecond;
            surplusTime++;
            if (surplusTime == bTime) {
                curHealth += surplusRecover;
                surplusTime = 0;
            }
            curHealth = min(curHealth, health);
        }
    }
    return curHealth;
}
