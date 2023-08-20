#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

long long MOD = 1e9 + 7;

long long add(long long a, long long b) { return (a + b) % MOD; }

long long sub(long long a, long long b) { return (a - b + MOD) % MOD; }

long long mult(long long a, long long b) { return (a * b) % MOD; }

vector<long long> FACT(2, 1);
vector<long long> INV(2, 1);
vector<long long> INV_FACT(2, 1);

void lazy_init(int n) {
  while (INV.size() <= n) {
    FACT.push_back(FACT.back() * INV.size() % MOD);
    INV.push_back(INV[MOD % INV.size()] * (MOD - MOD / INV.size()) % MOD);
    INV_FACT.push_back(INV_FACT.back() * INV.back() % MOD);
  }
}

long long nCr(int n, int k, bool inverse = false) {
  if (!(0 <= k && k <= n)) {
    return 0;
  }
  lazy_init(n);
  if (!inverse) {
    return (FACT[n] * INV_FACT[n - k] % MOD) * INV_FACT[k] % MOD;
  } else {
    return (INV_FACT[n] * FACT[n - k] % MOD) * FACT[k] % MOD;
  }
}

long long inv(int n) {
  lazy_init(n);
  return INV[n];
}

long long balance_scale() {
  int N, K;
  cin >> N >> K;
  vector<pair<int, int>> C_W(N);
  for (int i = 0; i < N; i++) {
    cin >> C_W[i].first >> C_W[i].second;
  }
  int less = 0;
  int equal = 0;
  int total = 0;
  for (pair<int, int>& cw : C_W) {
    if (cw.second < C_W[0].second) {
      less += cw.first;
    } else if (cw.second == C_W[0].second) {
      equal += cw.first;
    }
    total += cw.first;
  }
  long long result = mult(mult(sub(nCr(less + equal, K + 1), nCr(less, K + 1)),
                               mult(C_W[0].first, inv(equal))),
                          nCr(total, K + 1, true));
  return result;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  // freopen("input.txt", "r", stdin);
  freopen("balance_scale_input.txt", "r", stdin);

  int T;
  cin >> T;
  for (int caseNum = 1; caseNum <= T; caseNum++) {
    cout << "Case #" << caseNum << ": " << balance_scale() << "\n";
  }

  return 0;
}