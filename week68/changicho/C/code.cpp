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

int main() {
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cout.precision(10);

  // freopen("./input.txt", "r", stdin);

  int N;
  string S;
  cin >> N;
  cin >> S;

  int Q;
  cin >> Q;
  vector<vector<char>> queries(Q, vector<char>(2));

  for (int i = 0; i < Q; i++) {
    cin >> queries[i][0] >> queries[i][1];
  }

  string temp = "";
  for (char c = 'a'; c <= 'z'; c++) {
    temp += c;
  }

  for (vector<char> &q : queries) {
    char a = q[0];
    char b = q[1];

    for (int i = 0; i < temp.size(); i++) {
      if (temp[i] == a) {
        temp[i] = b;
      }
    }
  }

  for (int i = 0; i < S.size(); i++) {
    char c = S[i];

    S[i] = temp[c - 'a'];
  }

  cout << S << "\n";

  return 0;
}