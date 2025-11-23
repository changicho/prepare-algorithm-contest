#include <algorithm>
#include <climits>
#include <cmath>
#include <functional>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

int MOD = 998244353;

long long myPow(long long base, long long expo) {
  long long result = 1;

  while (expo > 0) {
    if (expo % 2 == 1) {
      result *= base;
      result %= MOD;
    }
    base = (base * base) % MOD;
    expo /= 2;
  }
  return result;
}

long long solution(string& s) {
  int size = s.size();

  vector<long long> factorial(size * 2 + 10, 1);
  for (int i = 2; i < size * 2 + 10; i++) {
    factorial[i] = (factorial[i - 1] * i) % MOD;
  }

  function<long long(int, int)> combi = [&](int n, int k) -> long long {
    if (k > n || k < 0) return 0;
    if (k == 0 || k == n) return 1;

    long long numer = factorial[n] % MOD;
    long long denom = (factorial[k] * factorial[n - k]) % MOD;

    return numer * myPow(denom, MOD - 2) % MOD;
  };

  int countRight[10] = {0};
  for (int i = 0; i < size; i++) {
    countRight[s[i] - '0']++;
  }
  int countLeft[10] = {0};

  long long answer = 0;
  for (int i = 0; i < size; i++) {
    int cur = s[i] - '0';
    countRight[cur]--;
    countLeft[cur]++;

    if (cur == 9) continue;
    int leftPart = countLeft[cur] - 1;
    int rightPart = countRight[cur + 1];

    long long count = combi(leftPart + rightPart, leftPart + 1);

    count %= MOD;

    answer += count;
    answer %= MOD;
  }

  return answer;
}

int main() {
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cout.precision(10);

  // freopen("./input.txt", "r", stdin);

  string S;
  cin >> S;

  auto answer = solution(S);

  cout << answer << endl;
  // cout << (answer ? "Yes" : "No") << endl;
  // for (auto &line : answer) {
  //   cout << line << "\n";
  // }
  // cout << endl;

  return 0;
}