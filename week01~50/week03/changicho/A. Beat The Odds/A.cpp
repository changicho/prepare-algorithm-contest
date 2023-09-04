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

int solution(vector<int> &array) {
  // all number is even or all number is odd
  int size = array.size();
  int oddCount = 0;
  int evenCount = 0;

  for (int &n : array) {
    if (n % 2 == 0) {
      evenCount++;
    } else {
      oddCount++;
    }
  }

  return min(evenCount, oddCount);
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

    vector<int> array(N);
    for (int i = 0; i < N; i++) {
      cin >> array[i];
    }

    int ret = solution(array);
    cout << ret << "\n";
  }

  return 0;
}