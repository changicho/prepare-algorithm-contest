#include <algorithm>
#include <climits>
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

vector<double> solution(int n, int m, vector<int>& a, vector<int>& b) {
  vector<double> answer(m);

  vector<vector<double>> weights(m + 1);
  for (int i = 0; i < n; i++) {
    weights[a[i]].push_back(b[i]);
  }

  for (int i = 1; i <= m; i++) {
    double sum = accumulate(weights[i].begin(), weights[i].end(), 0.0);
    answer[i - 1] = sum / weights[i].size();
  }

  return answer;
}

int main() {
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cout.precision(10);

  // freopen("./input.txt", "r", stdin);

  int N, M;
  cin >> N >> M;

  vector<int> A(N), B(N);

  for (int i = 0; i < N; i++) {
    cin >> A[i] >> B[i];
  }

  auto answer = solution(N, M, A, B);

  // cout << answer << endl;
  // cout << (answer ? "Yes" : "No") << endl;
  for (auto &line : answer) {
    cout << line << "\n";
  }
  cout << endl;

  return 0;
}