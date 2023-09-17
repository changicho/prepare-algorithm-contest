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

int calc(char op, int x, int y) {
  if (op == '&') {
    return x & y;
  } else if (op == '|') {
    return x | y;
  } else if (op == '^') {
    return x ^ y;
  }
  return 0;
}

int evaluate(string& s, unordered_map<char, int>& lookup) {
  stack<int> stk;
  stack<char> operators;

  for (char& c : s) {
    if (lookup.find(c) != lookup.end()) {
      stk.push(lookup[c]);
    } else if (c == ')') {
      int right = stk.top();
      stk.pop();
      int left = stk.top();
      stk.pop();
      char op = operators.top();
      operators.pop();

      stk.push(calc(op, left, right));
    } else if (c != '(') {
      operators.push(c);
    }
  }

  return stk.top();
}

int mr_x(string& E) {
  unordered_map<char, int> lookup1{{'0', 0}, {'1', 1}, {'x', 0}, {'X', 1}};
  unordered_map<char, int> lookup2{{'0', 0}, {'1', 1}, {'x', 1}, {'X', 0}};

  return evaluate(E, lookup1) == evaluate(E, lookup2) ? 0 : 1;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  freopen("input.txt", "r", stdin);
  // freopen("mr_x_input.txt", "r", stdin);

  int T;
  cin >> T;
  for (int testCase = 1; testCase <= T; testCase++) {
    string E;
    cin >> E;

    long long answer = mr_x(E);
    cout << "Case #" << testCase << ": " << answer << "\n";
  }

  return 0;
}