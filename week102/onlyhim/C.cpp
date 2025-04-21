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
using namespace std;



int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int numIngredient, numDishs;
    int val, ingredient, ans = 0;
    cin >> numIngredient >> numDishs;
    vector<int> numIngPerDish(numDishs);
    map<int, vector<int>> maps;
    for (int i = 0; i < numDishs; i++) {
        cin >> val;
        numIngPerDish[i] = val;
        for (int j = 0; j < val; j++) {
            cin >> ingredient;
            maps[ingredient].push_back(i);
        }
    }
    for (int i = 0; i < numIngredient; i++) {
        cin >> val;
        for (auto j : maps[val]) {
            numIngPerDish[j]--;
            if (numIngPerDish[j] == 0)  ans++;
        }
        cout << ans << '\n';
    }
    return 0;
}

/*
* maps<int, vector<int>> = 재료 i가 포함되어 있는 dish의 vector
* numIngPerDish[i] = dish i에 들어있는 재료 갯수
* 
* 입력으로 들어오는 재료를 i라 할 때, map[i]에는 재료 i가 들어있는 dish 종류가 모두 들어있다
* map[i]=j라 할 때, numIngPerDish[j]를 1개씩 빼다가 0이 되면 해당 재료가 모두 없다는 것을 의미한다.
* 
* O(N+SUMK)
*/
