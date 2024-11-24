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

bool solution(int n) {
  string line = to_string(n);

  int one = 0, two = 0, three = 0;
  for (int i = 0; i < line.size(); i++) {
    if (line[i] == '1') {
      one++;
    } else if (line[i] == '2') {
      two++;
    } else if (line[i] == '3') {
      three++;
    }
  }

  if (one + two + three != 6) return false;
  if (one != 1 || two != 2 || three != 3) return false;
  return true;
}

int main() {
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  // freopen("./input.txt", "r", stdin);

  int N;
  cin >> N;

  bool answer = solution(N);

  cout << (answer ? "Yes" : "No") << '\n';

  return 0;
}
