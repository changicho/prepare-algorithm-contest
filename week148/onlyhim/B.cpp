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

using namespace std;

class Solution {
public:
    vector<int> maxPrimes(int n, int s) {
        vector<int> primes;
        int sums = 0;
        for (int i = 2; i <= s; i++) {
            if (i > n)  break;
            bool isPrime = 1;
            for (int j = 2; j <= sqrt(i) && isPrime; j++) {
                if (i % j == 0)  isPrime = 0;
            }
            if (isPrime) {
                sums += i;
                if (sums > s)   break;
                primes.push_back(i);
            }
        }
        return primes;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    Solution s;
    s.maxPrimes(3, 2);

    return 0;
}

/*
* n보다 작거나 같은 모든 소수의 최대 갯수일 때의 모든 소수 리스트를 계산한다.
* 이 때 합이 s보다 작거나 같아야 한다. 
* 
* x보다 작거나 같은 소수는 항상 sqrt(x)보다 작거나 같다.
* O(nlogm)
*/
