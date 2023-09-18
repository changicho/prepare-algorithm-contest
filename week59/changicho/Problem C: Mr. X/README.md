# Problem C: Mr. X

[링크](https://www.facebook.com/codingcompetitions/hacker-cup/2019/qualification-round/problems/C)

## 시간 복잡도

입력받은 문자열의 길이를 N이라고 하자.

x와 X는 서로 반대의 값이며 x에 0, 1을 대입했을 때 두 결과를 비교할 수 있다.

이 때 한번의 연산에 O(N)의 시간 복잡도를 사용한다.

이후 두 결과가 다른 경우에 대해 처리한다.

## 공간 복잡도

각 식에 대해 연산을 처리하기 위해 stack을 사용한다.

이에 O(N)의 공간 복잡도를 사용한다.

## 풀이

| 시간 복잡도 | 공간 복잡도 |
| :---------: | :---------: |
|    O(N)     |    O(N)     |

문제에서 주어진 경우 x, X에 따라 결과가 달라지는 경우는 다음 3가지 경우이다.

- 둘 중 하나가 "0"이면 "&"를 사용할 수 있다.
- 그렇지 않고 그 중 하나가 "1"이면 "|" 사용될 수 있다.
- 그렇지 않으면 둘 다 변수값이며 "^"를 사용할 수 있습니다.

x와 X는 서로 다른값이다. (0, 1)

x가 0인 경우와 X가 0인 경우 두가지에 대해서 각각 연산을 수행하고 결과를 받는다.

만약 두 결과가 같은 경우는 수정할 부분이 없으므로 0을 반환한다.

만약 두 결과가 다른 경우 (결과값은 0 또는 1) 두 결과를 같게 만들기 위해 한 부분을 수정해야 한다.

이는 결과적으로 정답에 영향을 주는 한 부분만을 수정하면 되므로 하나의 값을 수정하면 된다.

따라서 1을 반환한다.

```cpp
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
```
