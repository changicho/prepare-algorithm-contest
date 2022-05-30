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

// time : 5min

int getEatCount(int size, vector<int> &boxes) {
  int minimum = boxes.front();
  for (int &box : boxes) {
    minimum = min(box, minimum);
  }

  int count = 0;
  for (int &box : boxes) {
    count += abs(box - minimum);
  }
  return count;
}

int main() {
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  // freopen("./input.txt", "r", stdin);

  int T;
  cin >> T;

  for (int testCase = 1; testCase <= T; testCase++) {
    int N;
    cin >> N;

    vector<int> boxes(N);

    for (int i = 0; i < N; i++) {
      cin >> boxes[i];
    }

    int ret = getEatCount(N, boxes);

    cout << ret << "\n";
  }

  return 0;
}