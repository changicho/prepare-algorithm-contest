#include <algorithm>
#include <cmath>
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

long getOrder(long num, long limit, long dist) {
  // (num + limit * x) % dist == 0
  long long origin = num;
  while (origin % dist != 0) {
    origin += limit;
  }
  return origin / dist;
}

long getMinimumCount(long a, long b, long limit, long dist) {
  // 0 ~ (limit-1)
  if (a == b) return 0;
  // limited loop
  if (gcd(limit, dist) != 1) {
    if (a % dist != b % dist) {
      return -1;
    }
    // in same loop
    long diff = abs(a - b);

    return diff / dist;
  }

  long aOrder = getOrder(a, limit, dist), bOrder = getOrder(b, limit, dist);
  long diff = abs(aOrder - bOrder);

  return min(diff, limit - diff);
}

int solution(long size, vector<long> &nums, long limit, long dist) {
  int answer = 0;
  int left = 0, right = size - 1;
  // minimum movement to make nums[left] == nums[right]

  while (left < right) {
    // do something
    int leftVal = nums[left], rightVal = nums[right];

    long minimumCount = getMinimumCount(leftVal, rightVal, limit, dist);
    if (minimumCount == -1) return -1;
    answer += minimumCount;

    left++, right--;
  }

  return answer;
}

int main() {
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  // freopen("./input.txt", "r", stdin);

  int T;
  cin >> T;

  for (int testCase = 1; testCase <= T; testCase++) {
    long W, N, D;
    cin >> W >> N >> D;

    vector<long> X(W);
    for (int i = 0; i < W; i++) {
      cin >> X[i];
      X[i]--;
    }

    auto answer = solution(W, X, N, D);

    cout << "Case #" << testCase << ": ";

    if (answer == -1) {
      cout << "IMPOSSIBLE" << endl;
    } else {
      cout << answer << endl;
    }
  }

  return 0;
}