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

// 0 0 0 0 a a a 0 0 a a a 0 0 a a a 0 0 0
int solution(int n, vector<int>& arr) {
  // vector<bool> isZero(n, false);
  // for (int i = 0; i < n; i++) {
  //   isZero[i] = arr[i] == 0;
  // }

  int left = 0, right = n - 1;
  while (left < n && arr[left] == 0) {
    left++;
  }
  while (right >= 0 && arr[right] == 0) {
    right--;
  }

  // cout << left << " " << right << endl;

  if (left == n) return 0;

  int answer = 1;
  bool flag = false;
  for (int i = left; i <= right; i++) {
    if (arr[i] == 0) flag = true;
  }

  if (flag) answer++;

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
    int n;
    cin >> n;
    vector<int> arr(n);

    for (int i = 0; i < n; i++) {
      cin >> arr[i];
    }

    int ret = solution(n, arr);
    cout << ret;
    cout << "\n";
  }

  return 0;
}