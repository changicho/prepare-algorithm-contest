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

int solution(vector<int> &nums) {
  int size = nums.size();

  vector<int> stk;

  for (int &num : nums) {
    if (stk.empty()) {
      stk.push_back(num);
      continue;
    }

    stk.push_back(num);
    while (stk.size() >= 2 && stk[stk.size() - 2] == stk[stk.size() - 1]) {
      int cur = stk.back() + 1;
      stk.pop_back();
      stk.pop_back();
      stk.push_back(cur);
    }
  }

  return stk.size();
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

  int answer = solution(A);

  cout << answer << "\n";

  return 0;
}