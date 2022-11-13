# 백준. 2447. 별 찍기 - 10

[링크](https://www.acmicpc.net/problem/2447)

| 난이도 |
| :----: |
| 골드 V |

## 설계

### 시간 복잡도

입력받은 수를 N이라 하자.

N^2 크기의 판을 출력해야 하므로, 최종적으로 방문하는 최소 위치의 갯수는 N^2개가 된다.

이를 재귀호출을 이용해 구현할 수 있다.

따라서 O(N^2)의 시간 복잡도를 사용한다.

### 공간 복잡도

미리 판을 만들어 놓고 방문 후 갱신할 경우 O(N^2)의 공간 복잡도를 사용한다.

### 분할 정복

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|     100      |   O(N^2)    |   O(N^2)    |

현재 구역에 대해 다음과 같이 탐색할 수 있다.

```cpp
// 1 : 채워야 하는 영역
// 0 : 채우지 않아도 되는 영역
[1][1][1]
[1][0][1]
[1][1][1]
```

각 구역별로 재귀호출을 이용해 최소 단위까지 탐색을 이어가고, 최소 단위인 경우 해당 패턴을 채우고 호출을 종료한다.

이를 모든 구역에 대해서 반복한다.

이 때 각 구역마다 가운데 영역은 빈칸으로 둬야 하므로 0으로 채워넣는다.

```cpp
struct Axis {
  int y, x;
};

void recursive(Axis start, Axis end, vector<string> &board) {
  int third = (end.y - start.y) / 3;
  if (third == 1) {
    for (int y = start.y; y < end.y; y++) {
      for (int x = start.x; x < end.x; x++) {
        board[y][x] = '*';
      }
    }
    board[start.y + 1][start.x + 1] = ' ';
    return;
  }

  for (int y = start.y; y < end.y; y += third) {
    for (int x = start.x; x < end.x; x += third) {
      if (y == start.y + third && x == start.x + third) continue;

      recursive({y, x}, {y + third, x + third}, board);
    }
  }
}

vector<string> solution(int size) {
  vector<string> board(size, string(size, ' '));

  recursive({0, 0}, {size, size}, board);

  return board;
}
```

## 고생한 점
