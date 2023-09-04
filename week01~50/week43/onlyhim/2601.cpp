#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    bool primeSubOperation(vector<int>& v) {
        vector<int> primes;
        for (int i = 2; i <= 1000; i++) {
            bool isPrime = 1;
            for (int j = 2; j < i && isPrime; j++)   if (i % j == 0) isPrime = 0;
            if (isPrime)    primes.push_back(i);
        }
        for (int i = 0; i < v.size(); i++) {
            int diff = i == 0 ? v[i] : v[i] - v[i - 1];
            int l = 0, r = primes.size() - 1, sub = -1;
            while (l <= r) {
                int m = (l + r) / 2;
                if (primes[m] < diff) {
                    sub = max(sub, primes[m]);
                    l = m + 1;
                }
                else r = m - 1;
            }
            if (sub != -1)   v[i] -= sub;
            if (i != 0 && v[i - 1] >= v[i]) return false;
        }
        return true;
    }
};
