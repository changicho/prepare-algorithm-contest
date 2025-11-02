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

auto solution(int size, int a, int b, string& s) {
  vector<int> prefixSumA(size, 0);
  vector<int> prefixSumB(size, 0);

  if (s[0] == 'a') {
    prefixSumA[0] = 1;
  } else {
    prefixSumB[0] = 1;
  }
  for (int i = 1; i < size; i++) {
    prefixSumA[i] = prefixSumA[i - 1] + (s[i] == 'a');
    prefixSumB[i] = prefixSumB[i - 1] + (s[i] == 'b');
  }

  long long answer = 0;

  for (int left = 0; left < size; left++) {
    int needA = a;
    int needB = b;
    // add prefix of 0 ~ (left-1)
    if (left > 0) {
      needA += prefixSumA[left - 1];
      needB += prefixSumB[left - 1];
    }

    // find left ~ right
    // that right part remain 'a'
    // [] is right part
    // xxxxxxb[aaaa...]
    int idx1 = lower_bound(prefixSumA.begin(), prefixSumA.end(), needA) -
               prefixSumA.begin();
    int idx2 = lower_bound(prefixSumB.begin(), prefixSumB.end(), needB) -
               prefixSumB.begin();

    // count idx1 ~ idx2 cases
    if (idx1 < idx2) {
      answer += (idx2 - idx1);
    }
  }

  return answer;
}

int main() {
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cout.precision(10);

  // freopen("./input.txt", "r", stdin);

  int N, A, B;
  cin >> N >> A >> B;

  string S;
  cin >> S;

  auto answer = solution(N, A, B, S);

  cout << answer << endl;
  // cout << (answer ? "Yes" : "No") << endl;
  // for (auto &line : answer) {
  //   cout << line << "\n";
  // }
  // cout << endl;

  return 0;
}