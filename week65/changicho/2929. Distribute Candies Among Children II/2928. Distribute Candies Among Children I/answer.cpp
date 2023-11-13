#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// use combination
// time : O(1)
// space : O(1)
class Solution {
 private:
  long long combination(int n, int m) {
    if (n < m) return 0;
    return (long long)n * (n - 1) / m / (m - 1);
  }

 public:
  long long distributeCandies(int n, int limit) {
    long long answer = 0;
    answer += combination(n + 2, 2);
    answer -= 3 * combination(n - limit + 1, 2);
    answer += 3 * combination(n - 2 * limit, 2);
    answer -= combination(n - 3 * limit - 1, 2);
    return answer;
  }
};