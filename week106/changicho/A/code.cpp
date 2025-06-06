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

int solution(int size, vector<int> &nums) {
  int answer = size - 1;

  sort(nums.begin(), nums.end());

  for (int i = 0; i < size; i++) {
    for (int j = i + 1; j < size; j++) {
      if ((nums[i] + nums[j]) % 2 == 0) {
        answer = min(answer, i + (size - j - 1));
      }
    }
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

  for (int test = 1; test <= T; test++) {
    int N;
    cin >> N;

    vector<int> A(N);
    for (int i = 0; i < N; i++) {
      cin >> A[i];
    }

    int answer = solution(N, A);

    cout << answer << endl;
    // cout << (answer ? "Yes" : "No") << endl;
    // for (auto &line : answer) {
    //   cout << line << "\n";
    // }
    // cout << endl;
  }

  return 0;
}