#include <algorithm>
#include <cmath>
#include <cstring>
#include <functional>
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

// 2^i * j, 2^i * (j+1) - 1
int solution(int n, int left, int right) {
  int limit = 1 << n;

  right++;

  int sum = 0;
  int temp;

  int right2lefts[1 << 19];
  function<void()> preprocess = [&]() -> void {
    memset(right2lefts, -1, sizeof(right2lefts));
    queue<int> q;
    q.push(left);
    while (!q.empty()) {
      int curLeft = q.front();
      q.pop();

      for (int i = 1; i <= limit; i *= 2) {
        if (curLeft + i <= limit && right2lefts[curLeft + i] == -1) {
          right2lefts[curLeft + i] = curLeft;
          q.push(curLeft + i);
        }
        if (curLeft - i >= 0 && right2lefts[curLeft - i] == -1) {
          right2lefts[curLeft - i] = curLeft;
          q.push(curLeft - i);
        }
        if (curLeft & i) break;
      }
    }
  };

  preprocess();

  while (left != right) {
    int curLeft = right2lefts[right], curRight = right;

    int sign = 1;
    if (curLeft > curRight) {
      swap(curLeft, curRight);
      sign = -1;
    }

    int i = log2(curRight - curLeft);
    int j = curLeft / (curRight - curLeft);

    cout << "? " << i << " " << j << endl;
    cin >> temp;

    sum = (sum + temp * sign + 100) % 100;

    right = right2lefts[right];
  }
  return sum;
}

int main() {
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cout.precision(10);

  // freopen("./input.txt", "r", stdin);

  int N, L, R;
  cin >> N >> L >> R;

  int answer = solution(N, L, R);

  cout << "! " << answer << endl;

  return 0;
}