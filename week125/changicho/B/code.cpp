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

vector<int> solution(int size, const vector<int>& nums) {
  vector<int> answer;

  stack<int> s;
  for (int i = 0; i < size; i++) {
    int target = -1;
    while (!s.empty() && nums[s.top()] <= nums[i]) {
      s.pop();
    }

    if (s.empty()) {
      answer.push_back(-1);
    } else {
      answer.push_back(s.top() + 1);
    }
    s.push(i);
  }

  return answer;
}

int main() {
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cout.precision(10);

  // freopen("./input.txt", "r", stdin);

  int N;
  cin >> N;

  vector<int> A(N);
  for (int i = 0; i < N; i++) {
    cin >> A[i];
  }

  auto answer = solution(N, A);

  // cout << answer << endl;
  // cout << (answer ? "Yes" : "No") << endl;
  for (auto& line : answer) {
    cout << line << "\n";
  }
  // cout << endl;

  return 0;
}