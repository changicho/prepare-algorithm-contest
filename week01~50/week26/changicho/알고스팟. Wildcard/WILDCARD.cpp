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

bool recursive(int pI, int wI, vector<vector<int>> &dp, string &word,
               string &pattern) {
  if (dp[pI][wI] != -1) return dp[pI][wI];

  if (wI < word.size() && pI < pattern.size() &&
      (pattern[pI] == '?' || pattern[pI] == word[wI])) {
    return dp[pI][wI] = recursive(pI + 1, wI + 1, dp, word, pattern);
  }

  if (pI == pattern.size()) {
    return dp[pI][wI] = wI == word.size();
  }

  if (pattern[pI] == '*') {
    if (recursive(pI + 1, wI, dp, word, pattern) ||
        (wI < word.size() && recursive(pI, wI + 1, dp, word, pattern))) {
      return dp[pI][wI] = 1;
    }
  }
  return dp[pI][wI] = 0;
}

bool isMatch(string word, string pattern) {
  vector<vector<int>> dp(101, vector<int>(101, -1));

  recursive(0, 0, dp, word, pattern);
  return dp[pattern.size()][word.size()] == 1;
}

vector<string> solution(string &pattern, vector<string> &words) {
  vector<string> answer;

  for (string &word : words) {
    if (isMatch(word, pattern)) {
      answer.push_back(word);
    }
  }
  sort(answer.begin(), answer.end());

  return answer;
}

int main() {
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  freopen("./input.txt", "r", stdin);

  int C;
  cin >> C;

  for (int testCase = 1; testCase <= C; testCase++) {
    string pattern;
    int N;
    cin >> pattern >> N;

    vector<string> words(N);
    for (int i = 0; i < N; i++) {
      cin >> words[i];
    }

    vector<string> answer = solution(pattern, words);

    for (string &word : answer) {
      cout << word << "\n";
    }
  }

  return 0;
}
