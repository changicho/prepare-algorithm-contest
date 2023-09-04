# 9663. N-Queen

[링크](https://www.acmicpc.net/problem/9663)

| 난이도  | 정답률(\_%) | 시간 제한(초) |
| :-----: | :---------: | :-----------: |
| 골드 IV |   47.172    |      10       |

## 설계

### 시간 복잡도

입력받은 판의 크기를 N이라 하자.

각 경우마다 모든 경우를 탐색할 경우 O(N!)의 시간 복잡도를 사용한다.

이는 각 과정마다 퀸이 놓인 행 또는 열을 사용 불가능하기 때문이다.

이 값은 매우 크므로 백트래킹을 사용한다.

### 공간 복잡도

DFS를 이용해 구현할 경우 O(N)의 공간 복잡도를 사용한다. (한 행, 열에 하나의 퀸만 존재 가능하므로)

또한 visited 배열에 O(N^2)의 공간 복잡도를 사용한다.

BFS의 경우 각 과정을 모두 큐에 저장하므로 O(N!)의 공간 복잡도를 사용한다.

## DFS & backtracking

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|     8032     |  <= O(N!)   |   O(N^2)    |

각 퀸은 각 행에 하나만 존재할 수 있다.

따라서 행에 대해서 DFS를 수행하며, 현재 행의 x좌표들 중에서 가능한 경우에 퀸을 배치하며 탐색을 이어나간다.

이 때 불가능한 경우들은 무시하며 시간 복잡도를 최적화한다.

이를 구현하면 다음과 같다.

```cpp
Axis dirs[4] = {{+1, +1}, {-1, -1}, {+1, -1}, {-1, +1}};

bool canLocate(int y, int x, int size, bool board[16][16]) {
  for (int i = 0; i < size; i++) {
    if (board[i][x]) return false;
  }

  for (Axis &dir : dirs) {
    Axis cur = {y, x};

    for (int i = 0; i < size; i++) {
      cur.y += dir.y;
      cur.x += dir.x;

      if (cur.y < 0 || cur.y >= size || cur.x < 0 || cur.x >= size) break;
      if (board[cur.y][cur.x]) return false;
    }
  }

  return true;
}

void recursive(int y, int x, int size, int &count, bool board[16][16]) {
  if (y == size) {
    count++;
    return;
  }

  for (int x = 0; x < size; x++) {
    if (board[y][x]) continue;
    if (!canLocate(y, x, size, board)) continue;

    board[y][x] = true;
    recursive(y + 1, x, size, count, board);
    board[y][x] = false;
  }
}

int solution(int size) {
  int count = 0;

  bool board[16][16] = {
      false,
  };

  recursive(0, 0, size, count, board);

  return count;
}
```

## 고생한 점
