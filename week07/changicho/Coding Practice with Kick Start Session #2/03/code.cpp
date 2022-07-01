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

vector<int> minusVector(vector<int> &a, vector<int> &b) {
  int size = a.size();
  vector<int> counts = a;

  for (int i = 0; i < size; i++) {
    counts[i] -= b[i];
  }
  return counts;
}

bool canMakePalindrome(vector<int> arr) {
  int oddCount = 0;
  for (int &a : arr) {
    if (a % 2 == 1) oddCount++;
  }

  return oddCount <= 1;
}

int solution(string &s, vector<vector<int>> &questions) {
  int length = s.length();
  int answer = 0;

  vector<vector<int>> prefixes(length + 1, vector<int>(26, 0));

  for (int i = 0; i < length; i++) {
    char cur = s[i];
    prefixes[i + 1] = prefixes[i];
    prefixes[i + 1][cur - 'A']++;
  }

  for (vector<int> &q : questions) {
    int left = q.front() - 1, right = q.back() - 1;
    // cout << left << "~" << right << endl;

    vector<int> cur = minusVector(prefixes[right + 1], prefixes[left]);

    // for (int &a : cur) {
    //   cout << a << " ";
    // }
    // cout << endl;

    if (canMakePalindrome(cur)) answer++;
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
    int N, Q;
    cin >> N >> Q;

    string S;
    cin >> S;

    vector<vector<int>> questions(Q, vector<int>(2));
    for (int i = 0; i < Q; i++) {
      cin >> questions[i][0] >> questions[i][1];
    }

    int answer = solution(S, questions);

    cout << "Case #" << testCase << ": " << answer << "\n";
  }

  return 0;
}