# 문제

링크

| 난이도 |
| :----: |
|        |

## 설계

### 시간 복잡도

배열의 크기를 N, 좌표의 크기를 2000^2라 하자.

2차원 좌표의 diff array를 사용해 각 영역이 겹치는 부분과 겹치지 않은 부분의 index를 구한다.

이 경우 O(N + 2000^2)의 시간 복잡도를 가진다.

### 공간 복잡도

2차원 diff array를 사용하므로 O(2000^2)의 공간 복잡도를 가진다.

### diff array

| 내 코드 (ms) |  시간 복잡도  | 공간 복잡도 |
| :----------: | :-----------: | :---------: |
|      84      | O(N + 2000^2) |  O(2000^2)  |

2차원 좌표에 대해 diff array를 사용한다.

이 때 겹치는 갯수와 겹치는 구름의 key값을 각각 더하는 diff array를 만든다.

이후 누적합을 구해 각 좌표에 대해 겹치는 구름의 갯수와 key값을 구할 수 있다.

이 때 겹치지 않는 부분의 경우 key값은 해당 구름의 index가 된다.

(겹치지 않는 구름만 하나만 있는 경우 key값이 한번만 더해진다)

이후 각 좌표별로 구름이 한번만 존재하는 경우 해당 구름이 삭제되는 경우 삭제되므로 해당 구름의 index가 삭제될 때 사라지는 좌표의 갯수를 더해준다.

```cpp
struct Cloud {
  int u, d, l, r;
};

vector<int> solution(int size, vector<Cloud>& clouds) {
  vector<vector<int>> diffs(2002, vector<int>(2002, 0));
  vector<vector<int>> keyDiffs(2002, vector<int>(2002, 0));

  for (int i = 0; i < size; i++) {
    int key = i + 1;
    Cloud& cloud = clouds[i];

    diffs[cloud.u][cloud.l] += 1;
    diffs[cloud.u][cloud.r + 1] -= 1;
    diffs[cloud.d + 1][cloud.l] -= 1;
    diffs[cloud.d + 1][cloud.r + 1] += 1;

    keyDiffs[cloud.u][cloud.l] += key;
    keyDiffs[cloud.u][cloud.r + 1] -= key;
    keyDiffs[cloud.d + 1][cloud.l] -= key;
    keyDiffs[cloud.d + 1][cloud.r + 1] += key;
  }

  for (int y = 1; y <= 2000; y++) {
    for (int x = 1; x <= 2000; x++) {
      diffs[y][x] += diffs[y][x - 1];
      keyDiffs[y][x] += keyDiffs[y][x - 1];
    }
  }
  for (int y = 1; y <= 2000; y++) {
    for (int x = 1; x <= 2000; x++) {
      diffs[y][x] += diffs[y - 1][x];
      keyDiffs[y][x] += keyDiffs[y - 1][x];
    }
  }

  vector<int> answer(size, 0);
  int remain = 0;
  for (int y = 1; y <= 2000; y++) {
    for (int x = 1; x <= 2000; x++) {
      if (diffs[y][x] == 0) {
        remain++;
      } else if (diffs[y][x] == 1) {
        int key = keyDiffs[y][x];
        answer[key - 1]++;
      }
    }
  }
  for (int i = 0; i < size; i++) {
    answer[i] += remain;
  }

  return answer;
}
```

## 고생한 점
