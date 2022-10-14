#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<int> solution(string &line, string &pattern) {
  vector<int> answer;

  int length = line.size(), patternLength = pattern.size();
  vector<int> patternIndexArr(patternLength, 0);

  // 패턴 인덱스 배열을 만듬
  for (int curIdx = 1, patternIdx = 0; curIdx < patternLength; curIdx++) {
    while (patternIdx > 0 && pattern[curIdx] != pattern[patternIdx]) {
      patternIdx = patternIndexArr[patternIdx - 1];
    }
    if (pattern[curIdx] == pattern[patternIdx]) {
      patternIdx++;
      patternIndexArr[curIdx] = patternIdx;
    }
  }

  // 문자열을 순회하며 찾는 문자열들을 검색함
  for (int lineIdx = 0, patternIdx = 0; lineIdx < length; lineIdx++) {
    while (patternIdx > 0 && line[lineIdx] != pattern[patternIdx]) {
      patternIdx = patternIndexArr[patternIdx - 1];
    }

    if (line[lineIdx] == pattern[patternIdx]) {
      if (patternIdx == patternLength - 1) {
        answer.push_back(lineIdx - patternLength + 1);

        patternIdx = patternIndexArr[patternIdx];
      } else {
        patternIdx++;
      }
    }
  }

  return answer;
}

int main() {
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  string line, pattern;
  getline(cin, line);
  getline(cin, pattern);

  vector<int> answer = solution(line, pattern);

  cout << answer.size() << "\n";
  for (int answer : answer) {
    cout << answer + 1 << " ";
  }
  cout << "\n";

  return 0;
}