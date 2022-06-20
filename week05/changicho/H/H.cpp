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

void solution(vector<int>& nums) {
  int size = nums.size();

  unordered_map<int, int> firstAppears;
  unordered_map<int, int> lastAppears;
  unordered_map<int, int> keepCount;

  int target = nums.front();
  int count = 1;
  int left = 0, right = 0;

  for (int i = 0; i < size; i++) {
    int cur = nums[i];

    if (firstAppears.count(cur) == 0) {
      firstAppears[cur] = i;
    }

    if (lastAppears.count(cur) > 0) {
      int diff = abs(i - lastAppears[cur]);
      keepCount[cur] -= diff - 1;
    }

    if (keepCount[cur] <= 0) {
      firstAppears[cur] = i;
      keepCount[cur] = 0;
    }
    keepCount[cur]++;
    lastAppears[cur] = i;

    if (keepCount[cur] > count) {
      count = keepCount[cur];
      target = cur;
      left = firstAppears[cur];
      right = lastAppears[cur];
    }
  }

  cout << target << " " << left + 1 << " " << right + 1 << "\n";
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

    solution(arr);
  }
  return 0;
}