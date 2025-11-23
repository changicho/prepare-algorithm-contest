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

long long solution(string& s) {
  int size = s.size();

  vector<int> l2rLength(size, 0);
  vector<int> r2lLength(size, 0);

  int left = 0, right = 0;
  for (; right <= size; right++) {
    if (s[left] == s[right]) {
      continue;
    }

    while (left < right) {
      l2rLength[left] = right - left;
      left++;
    }
  }

  while (left < size) {
    l2rLength[left] = size - left;
    left++;
  }

  left = size - 1, right = size - 1;
  for (; left >= 0; left--) {
    if (s[left] == s[right]) {
      continue;
    }

    while (right > left) {
      r2lLength[right] = right - left;
      right--;
    }
  }
  while (right > left) {
    r2lLength[right] = right - left;
    right--;
  }

  long long answer = 0;
  for (int i = 0; i < size - 1; i++) {
    if (s[i] + 1 != s[i + 1]) continue;

    int leftLen = r2lLength[i];
    int rightLen = l2rLength[i + 1];

    answer += min(leftLen, rightLen);
  }

  return answer;
}

int main() {
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cout.precision(10);

  // freopen("./input.txt", "r", stdin);

  string S;
  cin >> S;

  auto answer = solution(S);

  cout << answer << endl;
  // cout << (answer ? "Yes" : "No") << endl;
  // for (auto &line : answer) {
  //   cout << line << "\n";
  // }
  // cout << endl;

  return 0;
}