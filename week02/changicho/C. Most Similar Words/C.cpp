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

// time : 20min

int getDiff(int length, string &a, string &b) {
  int count = 0;
  for (int i = 0; i < length; i++) {
    count += abs(a[i] - b[i]);
  }
  return count;
}

int getMinCost(int length, vector<string> &words) {
  int minimum = getDiff(length, words[0], words[1]);
  int size = words.size();

  for (int i = 0; i < size; i++) {
    for (int j = i + 1; j < size; j++) {
      int cur = getDiff(length, words[i], words[j]);
      minimum = min(minimum, cur);
    }
  }

  return minimum;
}

int main() {
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  // freopen("./input.txt", "r", stdin);

  int T;
  cin >> T;

  for (int testCase = 1; testCase <= T; testCase++) {
    int N, M;
    cin >> N >> M;

    vector<string> words(N);
    for (int i = 0; i < N; i++) {
      cin >> words[i];
    }

    int ret = getMinCost(M, words);

    cout << ret << "\n";
  }

  return 0;
}