# 2931. Maximum Spending After Buying Items

[링크](https://leetcode.com/problems/maximum-spending-after-buying-items/description/)

| 난이도 |
| :----: |
|  Hard  |

## 설계

### 시간 복잡도

shop의 갯수를 R, shop마다 파는 물건의 갯수를 C라 하자. 총 물건의 갯수는 R \* C가 되며 이를 N이라 하자.

문제의 조건에 따라 가장 값을 크게 만들기 위해선 value가 가장 큰 item을 나중에 선택하는 방법이 유효하다.

따라서 각 물건들을 정렬 후 작은 값부터 선택할 수 있다. 정렬에 O(N * log_2(N))의 시간 복잡도를 사용한다.

### 공간 복잡도

별도로 값들을 저장할 공간에 O(N)의 공간 복잡도를 사용한다.

정렬에 최악의 경우 O(N)의 공간 복잡도를 사용한다.

### 정렬

| 내 코드 (ms) |   시간 복잡도   | 공간 복잡도 |
| :----------: | :-------------: | :---------: |
|     162      | O(N * log_2(N)) |    O(N)     |

각 shop에서 물건들은 오름차순으로 정렬되어있다.

값이 작은 것들부터 우선 선택할 경우 해당 shop에서 선택되는 물건의 순서는 j가 증가하는 방향으로 선택할 수 있다.

가장 값을 크게 만들기 위해선 value가 가장 큰 item을 나중에 선택하는 방법이 유효하다.

이는 후에 선택하는 값이 d가 커진 상황에서 선택할 수 있기 때문이다.

이를 구현하면 다음과 같다.

```cpp
long long maxSpending(vector<vector<int>>& values) {
  int rows = values.size(), cols = values[0].size();

  vector<int> board(rows * cols);
  for (int y = 0; y < rows; y++) {
    for (int x = 0; x < cols; x++) {
      board[y * cols + x] = values[y][x];
    }
  }
  sort(board.begin(), board.end());

  long long answer = 0, dist = 1;
  for (int& b : board) {
    answer += dist * b;
    dist++;
  }
  return answer;
}
```

## 고생한 점
