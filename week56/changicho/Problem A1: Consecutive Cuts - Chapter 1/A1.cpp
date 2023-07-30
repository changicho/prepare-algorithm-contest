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

int findIdx(vector<int> &a, int target) {
  int size = a.size();
  for (int i = 0; i < size; i++) {
    if (a[i] == target) return i;
  }
  return -1;
}

bool solution(int size, int k, vector<int> &cards, vector<int> &toBe) {
  if (k == 0) {
    for (int i = 0; i < size; i++) {
      if (cards[i] != toBe[i]) return false;
    }
    return true;
  }

  int start = findIdx(toBe, cards.front());

  if (k == 1 && start == 0) {
    return false;
  }

  if (size == 2) {
    int mod = k % 2;
    if (start == mod) {
      return true;
    }
    return false;
  }

  for (int i = 0; i < size; i++) {
    int j = (start + i) % size;
    if (cards[i] != toBe[j]) return false;
  }

  return true;
}

int main() {
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  freopen("./consecutive_cuts_chapter_1_input.txt", "r", stdin);

  int T;
  cin >> T;
  for (int testCase = 1; testCase <= T; testCase++) {
    int N, K;
    cin >> N >> K;

    vector<int> A(N), B(N);

    for (int i = 0; i < N; i++) {
      cin >> A[i];
    }
    for (int i = 0; i < N; i++) {
      cin >> B[i];
    }

    bool answer = solution(N, K, A, B);

    cout << "Case #" << testCase << ": ";
    cout << (answer ? "YES" : "NO") << "\n";
  }

  return 0;
}