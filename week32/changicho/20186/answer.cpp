#include <algorithm>
#include <climits>
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

const int MAX = 1e9 + 1;

int solution(int size, const vector<int> &array, int k) {
  // dp[i][k]; i번째 까지 선택하고 k개의 수를 선택했을 때의 최대값?
  // dp[0][1] = array[0];
  // dp[i][k] = max(dp[i-1][k], dp[i-1][k-1] + array[i] - (k-1))

  vector<int> curDp(size + 1, 0), beforeDp(size + 1, 0);

  for (int selected = 1; selected <= k; selected++) {
    curDp[selected] =
        beforeDp[selected - 1] + array[selected - 1] - (selected - 1);
    for (int i = selected + 1; i <= size; i++) {
      curDp[i] =
          max(curDp[i - 1], beforeDp[i - 1] + array[i - 1] - (selected - 1));
    }

    swap(beforeDp, curDp);
  }

  int answer = beforeDp[size];
  return answer;
}

void init() {}

void clear() {}

int main() {
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  // // decimal point
  // cout << fixed;
  // cout.precision(8);

  init();

  // freopen("./input.txt", "r", stdin);

  int N, K;
  cin >> N >> K;

  vector<int> array(N);

  for (int i = 0; i < N; i++) {
    cin >> array[i];
  }

  int answer = solution(N, array, K);

  cout << answer << "\n";

  return 0;
}
