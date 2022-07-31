# C. Color the Picture

[링크](https://codeforces.com/contest/1711/problem/C)

| 난이도 |
| :----: |
| \*1500 |

## 설계

### 시간 복잡도

행의 수를 N, 열의 수를 M, 색의 수를 K라 하자.

각 좌표에서 인접한 3개 이상의 좌표가 같은 색이여야 하므로 인접한 행, 열을 같은 색으로 채울 수 있어야한다.

따라서 각 색을 순회하며 행, 열에 대해서 2줄 이상을 만들 수 있는지를 판별한다.

이 순회에 O(K)의 시간 복잡도를 사용한다.

### 공간 복잡도

각 색상을 저장할 공간이 필요하므로 O(K)의 공간 복잡도를 사용한다.

### 정리

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      61      |    O(K)     |    O(K)     |

연속된 2줄을 같은 색으로 채울 경우 문제의 조건을 만족한다.

따라서 각 행과 열에 대해서 인접한 2줄을 각 색으로 채울 수 있는지 판별한다.

여기서 행을 기준으로 정했을 때, 열의 갯수가 홀수일 수 있다.

이 경우 홀수줄을 채우기 위해선 최소 3줄이상 채울 수 있어야 하므로 이를 검사한다.

행과 열 중 어느것을 기준으로 잡는지에 따라 가능, 불가능 여부가 달라지므로 두 경우 모두 탐색한다.

```cpp
bool canFill(int rows, int cols, vector<int> colors) {
  bool overThree = false;
  long long filledCols = 0;

  for (int &color : colors) {
    int curCols = color / rows;

    if (curCols >= 3) overThree = true;
    if (curCols >= 2) filledCols += curCols;
  }

  if (filledCols < cols) return false;

  if (cols % 2 == 1 && overThree) return true;
  if (cols % 2 == 0) return true;
  return false;
}

bool solution(int n, int m, int k, vector<int> colors) {
  return canFill(n, m, colors) || canFill(m, n, colors);
}
```

## 고생한 점
