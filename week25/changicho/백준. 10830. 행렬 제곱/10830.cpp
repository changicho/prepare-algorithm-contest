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

vector<vector<int>> multiply(vector<vector<int>> &a, vector<vector<int>> &b) {
  int size = a.size();
  vector<vector<int>> ret(size, vector<int>(size, 0));

  for (int y = 0; y < size; y++) {
    for (int x = 0; x < size; x++) {
      int sum = 0;

      for (int i = 0; i < size; i++) {
        sum += a[y][i] * b[i][x];
        sum %= 1000;
      }

      ret[y][x] = sum;
    }
  }

  return ret;
}

vector<vector<int>> recursive(long long left, vector<vector<int>> matrix) {
  if (left == 1) {
    return matrix;
  }

  vector<vector<int>> half = recursive(left / 2, matrix);
  vector<vector<int>> ret = multiply(half, half);
  if (left % 2 == 1) {
    ret = multiply(ret, matrix);
  }
  return ret;
}

vector<vector<int>> solution(int N, long long B, vector<vector<int>> &board) {
  vector<vector<int>> answer = recursive(B, board);

  return answer;
}

int main() {
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  freopen("./input.txt", "r", stdin);

  int N;
  long long B;

  cin >> N >> B;

  vector<vector<int>> board(N, vector<int>(N, 0));
  for (int y = 0; y < N; y++) {
    for (int x = 0; x < N; x++) {
      cin >> board[y][x];
      board[y][x] %= 1000;
    }
  }

  vector<vector<int>> answer = solution(N, B, board);

  for (int y = 0; y < N; y++) {
    for (int x = 0; x < N; x++) {
      cout << answer[y][x] << " ";
    }
    cout << "\n";
  }

  return 0;
}