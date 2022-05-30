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

// time : 15min

vector<int> minimumCounts(vector<int> &candies, vector<int> &queries) {
  int size = candies.size();
  sort(candies.begin(), candies.end(), greater<int>());

  vector<int> prefix(size);
  prefix[0] = candies.front();
  for (int i = 1; i < size; i++) {
    prefix[i] = prefix[i - 1] + candies[i];
  }

  vector<int> ret;

  for (int &q : queries) {
    auto it = lower_bound(prefix.begin(), prefix.end(), q);

    if (it == prefix.end()) {
      ret.push_back(-1);
    } else {
      ret.push_back(it - prefix.begin() + 1);
    }
  }

  return ret;
}

int main() {
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  // freopen("./input.txt", "r", stdin);

  int T;
  cin >> T;

  for (int testCase = 1; testCase <= T; testCase++) {
    int N, Q;
    cin >> N >> Q;

    vector<int> candies(N);
    vector<int> queries(Q);

    for (int i = 0; i < N; i++) {
      cin >> candies[i];
    }
    for (int i = 0; i < Q; i++) {
      cin >> queries[i];
    }

    vector<int> ret = minimumCounts(candies, queries);

    for (int &a : ret) {
      cout << a << "\n";
    }
  }

  return 0;
}