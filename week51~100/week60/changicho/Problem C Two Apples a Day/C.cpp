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

typedef long long ll;

long long checkMissingInMiddle(vector<long long> &apples, int left, int right,
                               int skipChance, long long target) {
  while (left < right) {
    if (apples[left] + apples[right] != target) {
      if (skipChance == 0) {
        return -1;
      }

      long long leftSkip =
          checkMissingInMiddle(apples, left + 1, right, skipChance - 1, target);
      long long rightSkip =
          checkMissingInMiddle(apples, left, right - 1, skipChance - 1, target);

      // cout << leftSkip << " " << rightSkip << endl;

      if (leftSkip == -1 && rightSkip == -1) {
        return -1;
      }
      if (leftSkip == -1 && rightSkip != -1) {
        return target - apples[right];
      }
      if (leftSkip != -1 && rightSkip == -1) {
        return target - apples[left];
      }
      return -1;
    }

    left++;
    right--;
  }
  return target - apples[left];
}

long long solution(int size, vector<long long> &apples) {
  sort(apples.begin(), apples.end());
  // for (long long &a : apples) {
  //   cout << a << " ";
  // }
  // cout << endl;

  int appleSize = apples.size();

  // missing part in middle
  long long target = apples[0] + apples[appleSize - 1];
  long long missingInMiddle =
      checkMissingInMiddle(apples, 0, appleSize - 1, 1, target);

  if (missingInMiddle != -1 && missingInMiddle != 0) {
    return missingInMiddle;
  }

  // missing part in left
  target = apples[1] + apples[appleSize - 1];
  long long missingInLeft =
      checkMissingInMiddle(apples, 1, appleSize - 1, 0, target);
  if (missingInLeft != -1 && target != apples[0]) {
    return target - apples[0];
  }

  // missing part in right
  target = apples[0] + apples[appleSize - 2];
  long long missingInRight =
      checkMissingInMiddle(apples, 0, appleSize - 2, 0, target);
  if (missingInRight != -1 && target != apples[appleSize - 1]) {
    return target - apples[appleSize - 1];
  }

  return -1;
}

int main() {
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  // freopen("./input.txt", "r", stdin);
  // freopen("./two_apples_a_day_input.txt", "r", stdin);

  int T;
  cin >> T;
  for (int testCase = 1; testCase <= T; testCase++) {
    int N;
    cin >> N;

    vector<long long> A(2 * N - 1);
    for (int i = 0; i < A.size(); i++) {
      cin >> A[i];
    }

    long long answer = solution(N, A);

    cout << "Case #" << testCase << ": " << answer << "\n";
  }

  return 0;
}