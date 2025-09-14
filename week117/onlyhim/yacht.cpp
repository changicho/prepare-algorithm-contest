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

using namespace std;

// 주사위 최대 5개, 값은 0~5
vector<int> A;

// 메모이제이션 키용 구조체 (남은 턴, 고정된 주사위 값들)
struct State {
    int turns;
    vector<int> kept; // 항상 정렬된 상태 유지

    bool operator==(const State& other) const {
        return turns == other.turns && kept == other.kept;
    }
};

// State를 unordered_map의 키로 쓰기 위한 해시
struct StateHash {
    size_t operator()(const State& s) const {
        size_t h = s.turns;
        for (int x : s.kept) {
            h = h * 31 + x;
        }
        return h;
    }
};

unordered_map<State, double, StateHash> memo;

// 기대값 계산 함수
double f(int turns_left, vector<int> kept) {
    if ((int)kept.size() == 5) {
        // 점수 계산
        map<int, int> maps;
        for (int x : kept) maps[x]++;
        int best = 0;
        for (int x : kept) {
            best = max(best, maps[x] * x);
        }
        return (double)best;
    }

    State st{ turns_left, kept };
    if (memo.count(st)) return memo[st];

    int rest = 5 - (int)kept.size();
    double ans = 0.0;

    // 모든 경우의 수 시뮬레이션
    int total = 1;
    for (int i = 0; i < rest; i++) total *= 6;

    for (int mask = 0; mask < total; mask++) {
        vector<int> roll;
        int tmp = mask;
        for (int i = 0; i < rest; i++) {
            roll.push_back(tmp % 6);
            tmp /= 6;
        }

        double prob = 1.0 / total;
        double M = 0.0;

        int subset_end = (turns_left == 1 ? 1 : (1 << rest));
        for (int subset = 0; subset < subset_end; subset++) {
            vector<int> newkept = kept;
            for (int i = 0; i < rest; i++) {
                if (turns_left == 1 || (subset >> i) & 1) {
                    newkept.push_back(roll[i]);
                }
            }
            sort(newkept.begin(), newkept.end());
            M = max(M, f(turns_left - 1, newkept));
        }

        ans += M * prob;
    }

    return memo[st] = ans;
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    A.resize(6);
    for (int i = 0; i < 6; i++) cin >> A[i];

    double res = f(3, {});
    cout << fixed << setprecision(10) << res << "\n";

    return 0;
}
 
/*
* 6면 주사위 5개가 주어진다.
* 총 3번을 굴릴 수 있고, 1번 굴릴 때 마다 나온 숫자를 킵할 수 있다.
* 나온 숫자의 (최대 값*나온 갯수)를 x라 하자. 모든 게임을 optimally 할 때의 기대값을 계산해라.
* 
* unorderd map -> key = state(남은 턴, 고정된 주사위 값), value = 기대값(double)
* state를 key로 쓰기 위해 hash 함수필요
* 
* 
*/
