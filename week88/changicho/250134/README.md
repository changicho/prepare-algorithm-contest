# [PCCP 기출문제] 4번 / 수레 움직이기

[링크](https://school.programmers.co.kr/learn/courses/30/lessons/250134)

| 난이도 |
| :----: |
|  LV3   |

## 설계

### 시간 복잡도

2차원 배열 maze의 행의 갯수를 R, 열의 갯수를 C라 하자.

하나의 수레에 대해 모든 경우를 탐색할 경우 O(R \* C)의 시간 복잡도가 소요된다.

이를 두 수레에 대해 탐색하므로 시간 복잡도는 O((R \* C)^2) 이다.

### 공간 복잡도

완전탐색시 방문 배열이 필요하다. 이에 O(R \* C)의 공간 복잡도가 필요하다.

### 완전 탐색

|  시간 복잡도  | 공간 복잡도 |
| :-----------: | :---------: |
| O((R \* C)^2) |  O(R \* C)  |

각 수레에 대해서 이동하는 모든 경우를 DFS로 탐색한다.

이는 최악의 경우 O(4^4) 이므로 256번 이내에 해결이 가능하다.

각 경우마다 도달 불가능한 경우는 다음과 같다.

- 수레가 교차하는 경우
- 수레가 같은 위치에 만나는 경우

또한 수레가 이미 도착위치에 도달한 경우 해당 수레는 더이상 움직이지 않는다.

```cpp
struct Axis {
  int y, x;

  const bool operator==(const Axis &b) { return y == b.y && x == b.x; }
  const bool operator!=(const Axis &b) { return y != b.y || x != b.x; }
};

Axis dirs[4] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

int solution(vector<vector<int>> maze) {
  int rows = maze.size(), cols = maze[0].size();

  Axis red, redEnd, blue, blueEnd;
  for (int y = 0; y < rows; y++) {
    for (int x = 0; x < cols; x++) {
      switch (maze[y][x]) {
        case 1: {
          red = {y, x};
          break;
        }
        case 2: {
          blue = {y, x};
          break;
        }
        case 3: {
          redEnd = {y, x};
          break;
        }
        case 4: {
          blueEnd = {y, x};
        }
      }
    }
  }

  int answer = INT_MAX;

  bool redVisited[4][4] = {
      false,
  };
  bool blueVisited[4][4] = {
      false,
  };
  redVisited[red.y][red.x] = true;
  blueVisited[blue.y][blue.x] = true;

  function<void(Axis, Axis, int)> recursive = [&](Axis red, Axis blue, int step) {
    if (step > answer) return;

    if (red == redEnd && blue == blueEnd) {
      answer = min(answer, step);
      return;
    }

    vector<Axis> redNexts, blueNexts;
    for (Axis &dir : dirs) {
      if (red == redEnd) {
        redNexts.push_back(red);
        break;
      }
      Axis next = {red.y + dir.y, red.x + dir.x};

      if (next.y < 0 || next.y >= rows || next.x < 0 || next.x >= cols)
        continue;
      if (maze[next.y][next.x] == 5) continue;
      if (redVisited[next.y][next.x]) continue;

      redNexts.push_back(next);
    }
    for (Axis &dir : dirs) {
      if (blue == blueEnd) {
        blueNexts.push_back(blue);
        break;
      }
      Axis next = {blue.y + dir.y, blue.x + dir.x};

      if (next.y < 0 || next.y >= rows || next.x < 0 || next.x >= cols)
        continue;
      if (maze[next.y][next.x] == 5) continue;
      if (blueVisited[next.y][next.x]) continue;

      blueNexts.push_back(next);
    }

    for (Axis &redNext : redNexts) {
      for (Axis &blueNext : blueNexts) {
        if (redNext == blueNext) continue;
        if (blueNext == red && redNext == blue) continue;

        redVisited[redNext.y][redNext.x] = true;
        blueVisited[blueNext.y][blueNext.x] = true;

        recursive(redNext, blueNext, step + 1);

        redVisited[redNext.y][redNext.x] = false;
        blueVisited[blueNext.y][blueNext.x] = false;
      }
    }
  };

  recursive(red, blue, 0);

  return answer == INT_MAX ? 0 : answer;
}
```

## 고생한 점
