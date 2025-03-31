#include <iostream>
#include <random>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

long long MOD = (1LL << 63);

long long subHash(long long a, long long b) { return (a - b + MOD) % MOD; }
long long addHash(long long a, long long b) { return (a + b) % MOD; }

class BIT {
 private:
  vector<long long> __bit;

 public:
  BIT(int n) : __bit(n + 1, 0) {}

  void add(int i, long long val) {
    i++;  // Extra one for dummy node.
    while (i < __bit.size()) {
      __bit[i] = addHash(__bit[i], val);  // modified
      i += (i & -i);
    }
  }

  long long query(int i) {
    i++;  // Extra one for dummy node.
    long long ret = 0;
    while (i > 0) {
      ret = addHash(ret, __bit[i]);  // modified
      i -= (i & -i);
    }
    return ret;
  }
};

long long my_hash(unordered_map<long long, long long>& lookup,
                 unordered_set<long long>& h_set, long long x) {
  if (lookup.find(x) == lookup.end()) {
    lookup[x] = rand() % MOD;
    h_set.insert(lookup[x]);
  }
  return lookup[x];
}

int perfectly_balanced_chapter_2() {
  int N;
  cin >> N;
  vector<long long> A(N);
  for (int i = 0; i < N; i++) {
    cin >> A[i];
  }

  unordered_map<long long, long long> lookup;
  unordered_set<long long> h_set;
  BIT bit(N);
  for (int i = 0; i < N; i++) {
    bit.add(i, my_hash(lookup, h_set, A[i]));
  }

  int result = 0;
  int Q;
  cin >> Q;
  for (int i = 0; i < Q; i++) {
    int type;
    cin >> type;
    if (type == 1) {
      int X, Y;
      cin >> X >> Y;
      X--;
      bit.add(X, -my_hash(lookup, h_set, A[X]));
      A[X] = Y;
      bit.add(X, my_hash(lookup, h_set, A[X]));
      continue;
    }
    int L, R;
    cin >> L >> R;
    L--;
    R--;
    if ((R - L + 1) % 2 == 0) {
      continue;
    }
    long long h1 = subHash(bit.query((L + R) / 2), bit.query(L - 1));
    long long h2 = subHash(bit.query(R), bit.query((L + R) / 2));
    if (h_set.find(subHash(h1, h2)) != h_set.end()) {
      result++;
      continue;
    }
    h1 = subHash(bit.query((L + R) / 2 - 1), bit.query(L - 1));
    h2 = subHash(bit.query(R), bit.query((L + R) / 2 - 1));
    if (h_set.find(subHash(h2, h1)) != h_set.end()) {
      result++;
      continue;
    }
  }

  return result;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  // freopen("./input.txt", "r", stdin);
  freopen("./perfectly_balanced_chapter_2_input.txt", "r", stdin);

  srand(0);
  int T;
  cin >> T;
  for (int caseNum = 1; caseNum <= T; caseNum++) {
    int answer = perfectly_balanced_chapter_2();
    cout << "Case #" << caseNum << ": " << answer << "\n";
  }

  return 0;
}
