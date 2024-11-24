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

string solution(int n, int k, string s) {
  vector<pair<char, int>> v;

  for (char &c : s) {
    if (v.empty() || v.back().first != c) {
      v.push_back({c, 1});
    } else {
      v.back().second++;
    }
  }

  int oneI = 0;
  for (int i = 0; i < v.size(); i++) {
    if (v[i].first == '1') {
      oneI++;

      if (oneI == k) {
        swap(v[i], v[i - 1]);
        break;
      }
    }
  }

  string answer = "";
  for (int i = 0; i < v.size(); i++) {
    answer += string(v[i].second, v[i].first);
  }
  return answer;
}

int main() {
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  // freopen("./input.txt", "r", stdin);

  int N, K;
  string S;
  cin >> N >> K >> S;

  // cout << N << " " << K << " " << S << '\n';

  string answer = solution(N, K, S);

  cout << answer << '\n';

  return 0;
}
