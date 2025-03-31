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
using namespace std;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int val;
    bool isTwo = 0, isThree = 0;
    vector<int> v(15, 0);
    for (int i = 0; i < 7; i++) {
        cin >> val;
        v[val]++;
    }
    for (int i = 0; i < v.size(); i++) {
        if (v[i] >= 2) {
            if (v[i] == 2)  isTwo = 1;
            else {
                if (!isThree)  isThree = 1;
                else isTwo = 1;
            }
        }
    }
    if (isThree && isTwo)   cout << "Yes";
    else cout << "No";
}

/*
  v[i] = 숫자 i가 등장한 횟수
  v[i] >= 2인 경우는 2의 경우 1번만 만족한다
  v[i] >= 3인 경우는 2인 경우와 3인 경우 둘다 만족시킬 수 있다. 따라서 3을 먼저 만족시킨 후에 2가 나온적 없으면 체크
*/
