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

int targets[3] = {3, 13, 23};

bool solution(vector<int> &nums) {
  int size = nums.size();
  for (int i = 0; i < size; i++) {
    nums[i] %= 10;
  }

  int counts[10] = {
      0,
  };
  for (int &n : nums) {
    counts[n]++;
  }

  for (int i = 0; i < 10; i++) {
    counts[i]--;
    for (int j = 0; j < 10; j++) {
      counts[j]--;
      for (int k = 0; k < 10; k++) {
        counts[k]--;

        if ((i + j + k) % 10 == 3 && counts[i] >= 0 && counts[j] >= 0 &&
            counts[k] >= 0) {
          return true;
        }

        counts[k]++;
      }
      counts[j]++;
    }
    counts[i]++;
  }

  return false;
}

int main() {
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  // freopen("./input.txt", "r", stdin);

  int T;
  cin >> T;

  for (int testCase = 1; testCase <= T; testCase++) {
    int N;
    cin >> N;

    vector<int> arr(N);
    for (int i = 0; i < N; i++) {
      cin >> arr[i];
    }

    bool ret = solution(arr);

    if (ret) {
      cout << "YES\n";
    } else {
      cout << "NO\n";
    }
  }

  return 0;
}