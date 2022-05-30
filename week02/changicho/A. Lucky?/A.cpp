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

// time : 10min

bool isLucky(string &number) {
  int sumFirst = 0, sumSecond = 0;
  for (int i = 0; i < 3; i++) {
    sumFirst += number[i] - '0';
    sumSecond += number[i + 3] - '0';
  }

  return sumFirst == sumSecond;
}

int main() {
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  // freopen("./input.txt", "r", stdin);

  int T;
  cin >> T;

  for (int testCase = 1; testCase <= T; testCase++) {
    string number;
    cin >> number;

    bool ret = isLucky(number);

    if (ret) {
      cout << "YES";
    } else {
      cout << "NO";
    }
    cout << "\n";
  }

  return 0;
}