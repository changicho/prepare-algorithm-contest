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

vector<int> solution(int n, vector<string>& graph) {
  vector<int> answer;

  vector<unordered_set<int>> preOrder(n);

  for (int node = 0; node < n; node++) {
    for (int before = node + 1; before < n; before++) {
      if (graph[node][before] == '0') preOrder[node].insert(before);
    }
  }

  for (int i = 0; i < n; i++) {
    answer.push_back(i);
  }

  sort(answer.begin(), answer.end(), [&](int a, int b) {
    if (a > b) {
      return preOrder[b].count(a) > 0;
    } else {
      return !(preOrder[a].count(b) > 0);
    }
  });

  for (int i = 0; i < n; i++) {
    answer[i]++;
    // cout << answer[i] << " ";
  }

  return answer;
}

int main() {
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cout.precision(10);

  // freopen("./input.txt", "r", stdin);

  int T;
  cin >> T;

  for (int testCase = 1; testCase <= T; testCase++) {
    int N;
    cin >> N;

    vector<string> graph(N);
    for (int i = 0; i < N; i++) {
      cin >> graph[i];
    }

    vector<int> answer = solution(N, graph);

    for (int& line : answer) {
      cout << line << " ";
    }
    cout << endl;
  }

  return 0;
}