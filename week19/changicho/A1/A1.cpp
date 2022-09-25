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
// left ~ mid, mid + 1 ~ right
bool isAlmostPalin(vector<vector<int>> &subArraySums, int left, int mid,
                   int right) {
  vector<int> leftCount(256, 0), rightCount(256, 0);

  leftCount = subArraySums[mid];
  for (int i = 0; i < 256; i++) {
    leftCount[i] -= subArraySums[left - 1][i];
  }

  rightCount = subArraySums[right];
  for (int i = 0; i < 256; i++) {
    rightCount[i] -= subArraySums[mid][i];
  }

  // for (int i = 'a'; i <= 'z'; i++) {
  //   cout << (char)i << " " << leftCount[i] << ":" << rightCount[i] << endl;
  // }
  // cout << endl;

  int diffCount = 0;
  for (int i = 0; i < 256; i++) {
    diffCount += abs(leftCount[i] - rightCount[i]);
  }
  if (diffCount == 1) return true;
  return false;
}

int solution(string &s, vector<pair<int, int>> queries) {
  int size = s.size();
  vector<vector<int>> subArraySums(size + 1, vector<int>(256, 0));

  for (int i = 0; i < size; i++) {
    subArraySums[i + 1] = subArraySums[i];
    subArraySums[i + 1][s[i]]++;
  }

  int answer = 0;
  for (pair<int, int> &query : queries) {
    int left = query.first, right = query.second;

    if ((right - left + 1) % 2 == 0) continue;

    // 1 2 3 4 5 6, 7 8 9 10 11
    int mid = (left + right) / 2;

    if (isAlmostPalin(subArraySums, left, mid - 1, right) ||
        isAlmostPalin(subArraySums, left, mid, right)) {
      answer++;
    }
  }

  return answer;
}

int main() {
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  freopen("./perfectly_balanced_chapter_1_input.txt", "r", stdin);

  int T;
  cin >> T;
  for (int testCase = 1; testCase <= T; testCase++) {
    int Q;
    string S;
    cin >> S >> Q;

    vector<pair<int, int>> queries(Q);
    for (int i = 0; i < Q; i++) {
      cin >> queries[i].first >> queries[i].second;
    }

    int answer = solution(S, queries);

    cout << "Case #" << testCase << ": ";
    cout << answer << "\n";
  }

  return 0;
}