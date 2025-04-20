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

    long long nPoints, nLines, a, b, slope;
    cin >> nPoints >> nLines;
    vector<long long> v(nPoints, 0);
    for (int i = 0; i < nLines; i++) {
        cin >> a >> b;
        v[(a + b) % nPoints]++;
    }
    long long ans = (nLines * (nLines - 1)) / 2;
    for (int i = 0; i < nPoints; i++)   ans -= (v[i] * (v[i] - 1)) / 2;
    cout << ans;
    return 0;
}

/*
* N^2에서 서로 수평인 쌍을 빼주면 된다.
* 현재를 (a,b)라 할 때, (a+X, b-X), (a-X, b+X)인 경우는 수평이다.
* 즉 a+b=c라 할 때 합이 c가 되는 모든 점은 수평이다.
* ex) (2,3) - (4,1)은 수평
* 
* 모든 쌍의 갯수는 N*(N-1)/2이므로, 여기서 a+b=c인 경우를 뺀다.
* O(N)
*/
