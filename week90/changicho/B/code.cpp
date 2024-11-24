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

vector<int> solution(string &s) {
  vector<int> ret;
  int temp = 0;
  for (char &c : s) {
    if (c == '|') {
      if (temp > 0) ret.push_back(temp);
      temp = 0;
    } else if (c == '-') {
      temp++;
    }
  }
  if (temp > 0) ret.push_back(temp);

  return ret;
}

int main() {
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  // freopen("./input.txt", "r", stdin);
  string S;
  cin >> S;

  vector<int> answer = solution(S);

  for (int &num : answer) {
    cout << num << " ";
  }
  cout << endl;

  return 0;
}