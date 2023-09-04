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
    vector<int> arr(N);

    for (int i = 0; i < N; i++) {
      cin >> arr[i];
    }

    int sums = 0;
    for (int &n : arr) {
      sums += n;
    }

    int answer = sums - (sums / M) * M;

    cout << "Case #" << testCase << ": ";
    cout << answer << "\n";
  }

  return 0;
}