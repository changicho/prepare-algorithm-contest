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

// time :

// need to
// nums[i] < 2*nums[i+1]

int solution(vector<long long> &nums, int k) {
  int size = nums.size();

  vector<bool> isValid(size - 1, false);
  // is valid check that : nums[i] < 2 * nums[i+1]
  for (int i = 0; i < size - 1; i++) {
    if (nums[i] < 2 * nums[i + 1]) {
      isValid[i] = true;
    }
  }

  // for (bool v : isValid) {
  //   cout << v << " ";
  // }
  // cout << endl;

  int count = 0;
  vector<int> prefixes(size, 0);  // prefixes[i] = sum[0 ~ i-1]
  for (int i = 1; i < size; i++) {
    prefixes[i] = prefixes[i - 1] + isValid[i - 1];
  }

  // for (int &pre : prefixes) {
  //   cout << pre << " ";
  // }
  // cout << endl;

  for (int left = 0; left <= isValid.size() - k; left++) {
    int right = left + k - 1;
    if (isValid.size() <= right) continue;

    if (prefixes[right + 1] - prefixes[left] >= k) {
      // cout << left << "~" << right + 1 << endl;
      count++;
    }
  }

  return count;
}

int main() {
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  // freopen("./input.txt", "r", stdin);

  int T;
  cin >> T;

  for (int testCase = 1; testCase <= T; testCase++) {
    int N, K;
    cin >> N >> K;

    vector<long long> arr(N);
    for (int i = 0; i < N; i++) {
      cin >> arr[i];
    }

    int ret = solution(arr, K);
    cout << ret << "\n";
  }

  return 0;
}