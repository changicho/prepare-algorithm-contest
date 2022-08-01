#include <algorithm>
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

// time :
long long solution(int n, int m, vector<int> &arr,
                   vector<pair<int, int>> &edges) {
  if (m % 2 == 0) return 0;

  vector<int> inDegree(n, 0);
  for (pair<int, int> &edge : edges) {
    int x = edge.first - 1, y = edge.second - 1;
    inDegree[x]++;
    inDegree[y]++;
  }

  int answer = accumulate(arr.begin(), arr.end(), 0);
  for (int node = 0; node < n; node++) {
    if (inDegree[node] % 2 == 1) {
      answer = min(answer, arr[node]);
    }
  }

  for (pair<int, int> &edge : edges) {
    int x = edge.first - 1, y = edge.second - 1;
    if (inDegree[x] % 2 == 0 && inDegree[y] % 2 == 0) {
      answer = min(answer, arr[x] + arr[y]);
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

    vector<int> A(N);
    for (int i = 0; i < N; i++) {
      cin >> A[i];
    }

    vector<pair<int, int>> edges(M);
    for (int i = 0; i < M; i++) {
      cin >> edges[i].first >> edges[i].second;
    }

    long long answer = solution(N, M, A, edges);
    cout << answer << "\n";
  }

  return 0;
}