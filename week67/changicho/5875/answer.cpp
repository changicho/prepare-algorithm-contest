#include <algorithm>
#include <cstring>
#include <iostream>
#include <map>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

int solution(string &s) {
  int size = s.size();
  int answer = 0;

  int opens = 0, closes = 0;
  int diff = 0;

  for (char &c : s) {
    if (c == '(') {
      opens += 1;
      diff += 1;

    } else {
      closes += 1;
      diff -= 1;
    }

    if (diff <= 1) {
      opens = 0;
    }

    if (diff == -1) {
      answer = closes;
      break;
    }
  }

  if (diff > 0) {
    answer = opens;
  }

  return answer;
}

int main() {
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  freopen("input.txt", "r", stdin);

  string S;
  cin >> S;

  int answer = solution(S);

  cout << answer << endl;

  return 0;
}