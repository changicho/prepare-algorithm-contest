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

int lim, K;

int go(unordered_map<string, int>& dp, vector<int>& v, int idx, int prod, int sum, int prev, bool virgin) {
    if (idx >= v.size()) {
        if (sum == K && prod <= lim) {
            if (virgin) return -1;
            return prod;
        }
        return -1;
    }

    string key = to_string(idx) + "," + to_string(prod) + "," + to_string(sum) + "," + to_string(prev) + "," + to_string(virgin);
    if (dp.find(key) != dp.end())   return dp[key];

    int& ret = dp[key] = -1;

    ret = max(ret, go(dp, v, idx + 1, prod, sum, prev, virgin));
    if (virgin) prod = v[idx];
    else prod *= v[idx];
    if (prod > lim) prod = lim + 1;
    ret = max(ret, go(dp, v, idx + 1, prod, sum + (prev == 0 ? v[idx] : -v[idx]), !prev, 0));
    return ret;
}

class Solution {
public:
    int maxProduct(vector<int>& nums, int k, int limit) {
        int sum = 0;
        for (auto it : nums) sum += it;
        if (sum < abs(k)) return -1;
        int ans = 0;
        unordered_map<string, int> dp;
        K = k;
        lim = limit;
        ans = go(dp, nums, 0, 0, 0, 0, 1);
        return ans;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    Solution s;
    vector<int> v = { 10,10,9,0 };
    s.maxProduct(v, 1, 20);
}

/*
* 정수배열 v의 subsequence중 다음 조건을 만족하는 경우의 max product를 구해라
* 1. alternating sum = k
* 2. product of v`[i] <= limit
* 
* 
* dp[i][j][k][l] = 인덱스 i, 곱이 j, 합이 k, 이전 선택 flag가 l일때의 최대값
* 
* dbg point
* 1. 현재까지의 prod >= lim이여도 예외로 제외하면 안된다.
* ex) 10, 9, 0 -> 0을 곱하면 prod < lim이 되므로, 바로 제외하지 말고 prod = lim + 1로 
* 
* 2. 현재 모든 합을 더한다해도 k를 넘지 못할 때는 예외처리 해줘야 한다
* 없으면 TLE?
*/
