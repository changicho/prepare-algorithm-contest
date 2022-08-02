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

// time :
// 0 : 0
// 1 : 2 4 8 6 ...
// 2 : 2 4 8 6 ...
// 3 : 2 4 8 6 ...
// 4 : 2 4 8 6 ...
// 5 : 0 ...
// 6 : 2 4 8 6 ...
// 7 : 2 4 8 6 ...
// 8 : 2 4 8 6 ...
// 9 : 2 4 8 6 ...
bool solution(int n, vector<int> &arr) {
  if (n == 1) return true;

  sort(arr.begin(), arr.end());
  vector<int> zeros;
  vector<int> fives;
  vector<int> twos;

  for (int &n : arr) {
    if (n % 10 == 0) {
      zeros.push_back(n);
    } else if (n % 10 == 5) {
      fives.push_back(n);
    } else {
      twos.push_back(n);
    }
  }

  if (!zeros.empty() || !fives.empty()) {
    if (!twos.empty()) return false;

    set<int> nums;
    for (int &zero : zeros) {
      nums.insert(zero);
    }
    for (int &five : fives) {
      nums.insert(five + 5);
    }

    return nums.size() == 1;
  }

  set<int> groupA, groupB;
  for (int &two : twos) {
    int key = (two / 10) % 2;
    if (two % 10 == 6 || two % 10 == 3) {
      groupB.insert(key);
    } else {
      if (two % 10 == 7 || two % 10 == 9) {
        key++;
        key %= 2;
      }
      groupA.insert(key);
    }
  }

  if (groupA.size() == 2 || groupB.size() == 2) return false;

  if (groupA.size() > 0 && groupB.size() == 0) return true;
  if (groupA.size() == 0 && groupB.size() > 0) return true;

  if (groupA.count(1) && groupB.count(1)) return false;
  if (groupA.count(0) && groupB.count(0)) return false;

  return true;
}

int main() {
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  freopen("./input.txt", "r", stdin);

  int T;
  cin >> T;
  for (int testCase = 1; testCase <= T; testCase++) {
    int N;
    cin >> N;

    vector<int> A(N);
    for (int i = 0; i < N; i++) {
      cin >> A[i];
    }

    bool answer = solution(N, A);
    cout << (answer ? "Yes" : "No") << "\n";
  }

  return 0;
}