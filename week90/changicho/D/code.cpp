#include <algorithm>
#include <cmath>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

char calc(string &s, vector<long long> &halfs, long long query) {
  int size = s.size();

  while (query > halfs.back()) {
    halfs.push_back(halfs.back() * 2);
  }

  bool isToggled = false;
  for (int i = halfs.size() - 1; i >= 0; i--) {
    if (query > halfs[i]) {
      query = query - halfs[i];
      isToggled = !isToggled;
    }
  }

  int index = (query - 1 + size) % size;
  // cout << index << " " << isToggled << " " << endl;
  char target = s[index];

  if (!isToggled) {
    return target;
  }
  if (islower(target)) {
    return toupper(target);
  } else {
    return tolower(target);
  }
}

vector<char> solution(string &s, int q, vector<long long> &queries) {
  // aB
  // aBAbAbaBAbaBaBAb

  vector<char> answer(q);
  vector<long long> halfs;
  halfs.push_back(s.size());

  for (int i = 0; i < q; i++) {
    answer[i] = calc(s, halfs, queries[i]);
  }

  return answer;
}

int main() {
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  // freopen("./input.txt", "r", stdin);

  string S;
  int Q;

  cin >> S >> Q;

  vector<long long> queries(Q);

  for (int i = 0; i < Q; i++) {
    cin >> queries[i];
  }

  vector<char> answer = solution(S, Q, queries);

  for (char &c : answer) {
    cout << c << ' ';
  }
  cout << '\n';

  return 0;
}
