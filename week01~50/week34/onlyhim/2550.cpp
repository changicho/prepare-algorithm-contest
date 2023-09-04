#include <vector>
using namespace std;

#define MOD 1000000007

long long powers(long long base, long long power) {
    long long result = 1;
    while (power > 0) {
        if (power % 2 == 1) {
            result = (result * base) % MOD;
        }
        base = (base * base) % MOD;
        power = power / 2;
    }
    return result;
}
class Solution {
public:
    int monkeyMove(int n) {
        long long ans = powers(2, n) % MOD;
        return ans == 0 ? 1000000007 : ans == 1 ? 1000000006 : ans - 2;
    }
};
