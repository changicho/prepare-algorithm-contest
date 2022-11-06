#include <algorithm>
#include <climits>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct Expect {
  string number;
  int strike;
  int ball;
};

bool hasZero(string &number) {
  for (char &c : number) {
    if (c == '0') return true;
  }
  return false;
}

bool isDuplicated(string &number) {
  return number[0] == number[1] || number[1] == number[2] ||
         number[0] == number[2];
}

int main() {
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  // freopen("./input.txt", "r", stdin);

  int N;
  cin >> N;

  vector<Expect> expects(N);
  int answer = 0;
  for (int i = 0; i < N; i++) {
    cin >> expects[i].number >> expects[i].strike >> expects[i].ball;
  }

  for (int number = 111; number <= 999; number++) {
    string target = to_string(number);
    if (hasZero(target)) continue;
    if (isDuplicated(target)) continue;

    bool allPass = true;
    for (Expect &expect : expects) {
      int ball = 0, strike = 0;

      int counts[10] = {
          0,
      };
      for (char &c : target) {
        counts[c - '0']++;
      }
      for (int i = 0; i < 3; i++) {
        if (expect.number[i] == target[i]) {
          strike++;
          counts[expect.number[i] - '0']--;
        } else if (counts[expect.number[i] - '0'] > 0) {
          ball++;
          counts[expect.number[i] - '0']--;
        }
      }

      if (ball != expect.ball || strike != expect.strike) {
        allPass = false;
      }
    }

    if (allPass) {
      // cout << number << endl;
      answer++;
    }
  }

  cout << answer << "\n";

  return 0;
}