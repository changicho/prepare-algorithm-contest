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

bool isValid(vector<int> &counts, int limit, int n) {
  int size = counts.size();

  long long free = 0, need = 0;
  for (int i = 0; i < n; i++) {
    if (counts[i] <= limit) {
      free += (limit - counts[i]) / 2;
    } else {
      need += counts[i] - limit;
    }
  }
  return need <= free;
}

int solution(int n, int m, vector<int> &tasks) {
  vector<int> counts(n);

  for (int &t : tasks) {
    counts[t - 1]++;
  }

  int left = 0, right = m * 2;
  int answer = right;
  while (left < right) {
    int mid = left + (right - left) / 2;

    if (isValid(counts, mid, n)) {
      // pick left
      right = mid;
      answer = mid;
    } else {
      // pick right
      left = mid + 1;
    }
  }
  return answer;
}

int main() {
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  freopen("./input.txt", "r", stdin);

  int T;
  cin >> T;

  for (int testCase = 1; testCase <= T; testCase++) {
    int N, M;

    cin >> N >> M;

    vector<int> tasks(M);
    for (int i = 0; i < M; i++) {
      cin >> tasks[i];
    }

    int answer = solution(N, M, tasks);
    cout << answer << "\n";
  }

  return 0;
}