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

const int BITS = 10;

bool isPrefix(string a, string b) {
  int length = min(a.size(), b.size());

  for (int i = 0; i < length; i++) {
    if (a[i] != b[i]) return false;
  }
  return true;
}

vector<string> solution(int n, string c1) {
  vector<string> answer;

  for (int i = 0; i < (1 << BITS) && answer.size() < n - 1; i++) {
    string s = bitset<BITS>(i).to_string();

    for (char &c : s) {
      if (c == '0') {
        c = '.';
      } else {
        c = '-';
      }
    }

    s = string(BITS - s.size(), '.') + s;

    if (!isPrefix(c1, s) && !isPrefix(s, c1)) {
      answer.push_back(s);
    }
  }
  return answer;
}

int main() {
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  freopen("./second_meaning_input.txt", "r", stdin);

  int T;
  cin >> T;
  for (int testCase = 1; testCase <= T; testCase++) {
    int N;
    string C1;
    cin >> N >> C1;

    vector<string> answer = solution(N, C1);

    cout << "Case #" << testCase << ": \n";

    for (string &s : answer) {
      cout << s << "\n";
    }
  }

  return 0;
}