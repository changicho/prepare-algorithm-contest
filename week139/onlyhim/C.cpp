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
    
    int n, k;
    cin >> n >> k;
    map<int, long> maps;
    for (int i = 0; i < n; i++) {
        int val;
        cin >> val;
        maps[val] += val;
    }
    vector<long> v;
    for (auto i : maps) v.push_back(i.second);
    std::sort(v.begin(), v.end());
    long long ans = 0;
    for (int i = 0; i < max(0, (int)maps.size()-k); i++)   ans += v[i];
    cout << ans;
    return 0;
}
 
/*
* 한 번의 연산으로 같은 값을 모두 처리할 수 있으므로, 합을 더해놓고 hash table에 push
* O(nlogn)
*/
