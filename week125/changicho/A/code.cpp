#include <algorithm>
#include <climits>
#include <cmath>
#include <functional>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

bool solution(int x, int y, int z) {
  // x + a == z * y + z * a
  // x - z * y = (z - 1) * a

  int parent = x - z * y;
  int child = z - 1;

  if (parent < 0) return false;
  return parent % child == 0;
}

int main() {
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cout.precision(10);

  // freopen("./input.txt", "r", stdin);

  int X, Y, Z;
  cin >> X >> Y >> Z;

  auto answer = solution(X, Y, Z);

  // cout << answer << endl;
  cout << (answer ? "Yes" : "No") << endl;
  // for (auto &line : answer) {
  //   cout << line << "\n";
  // }
  // cout << endl;

  return 0;
}