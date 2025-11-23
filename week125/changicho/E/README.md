# E - Max Matrix 2

[링크](https://atcoder.jp/contests/abc433/tasks/abc433_e)

| 난이도 |
| :----: |
|  450   |

## 설계

### 시간 복잡도

입력받은 2차원 배열의 행의 갯수를 N, 열의 갯수를 M이라 하자.

각 행과 열에 대해 탐역 알고리즘을 사용해 최선의 값을 구하는 데 O(R \* C) 시간복잡도를 사용한다.

이후 우선순위 큐를 사용해 정답을 구할 경우 O(RC \* log_2(RC))의 시간복잡도를 사용한다.

### 공간 복잡도

우선순위 큐에 O(RC)의 공간복잡도를 사용한다.

### 그리디 알고리즘 & 우선순위 큐

| 내 코드 (ms) |    시간 복잡도     | 공간 복잡도 |
| :----------: | :----------------: | :---------: |
|      48      | O(RC \* log_2(RC)) |    O(RC)    |

입력받은 X, Y에 중복된 값이 존재하는 경우 정답이 불가능하므로 이를 미리 체크한다.

각 행, 열에 대한 최대값중에서 동일한 값이 존재할 경우 해당 위치에 값을 채워넣는다.

이후 좌표를 순회하며 가능한 경우 해당 좌표에 대한 X, Y에 최대값들 중 작은 값을 채워넣는다.

이후 남은 좌표들에 대해 가능한 최대값과 (X, Y 최대값들 중 작은 값) 좌표를 우선순위 큐에 넣는다.

우선순위 큐는 최대값이 작은값이 top에 오도록 설정한다.

이후 1부터 순회하며 우선순위 큐에서 꺼낸 좌표에 대해 가능한 최대값 이하인 값을 채워넣는다.

각 과정에서 불가능한 경우를 판별하며 모든 값이 채워진 경우 가능한지 최종적으로 체크한다.

```cpp
struct Data {
  int maximum;
  int y, x;

  const bool operator<(const Data& d) const { return maximum > d.maximum; }
};

bool hasDuplicate(vector<int>& arr) {
  unordered_set<int> us;
  for (int& v : arr) {
    if (us.count(v)) {
      return true;
    }
    us.insert(v);
  }
  return false;
}

vector<vector<int>> solution(int rows, int cols, vector<int>& rowMax, vector<int>& colMax) {
  if (hasDuplicate(rowMax) || hasDuplicate(colMax)) {
    return {};
  }
  vector<vector<int>> answer(rows, vector<int>(cols, 0));

  vector<bool> usable(rows * cols + 1, true);

  for (int x = 0; x < cols; x++) {
    for (int y = 0; y < rows; y++) {
      if (rowMax[y] == colMax[x]) {
        if (!usable[rowMax[y]]) {
          return {};
        }

        answer[y][x] = rowMax[y];
        usable[rowMax[y]] = false;
      }
    }
  }

  // fill col max's in y
  for (int x = 0; x < cols; x++) {
    for (int y = 0; y < rows; y++) {
      if (!usable[colMax[x]]) continue;
      if (answer[y][x] != 0) continue;
      if (colMax[x] > rowMax[y]) continue;

      answer[y][x] = colMax[x];
      usable[colMax[x]] = false;
      break;
    }
  }
  // fill row max's in x
  for (int y = 0; y < rows; y++) {
    for (int x = 0; x < cols; x++) {
      if (!usable[rowMax[y]]) continue;
      if (answer[y][x] != 0) continue;
      if (rowMax[y] > colMax[x]) continue;

      answer[y][x] = rowMax[y];
      usable[rowMax[y]] = false;
      break;
    }
  }

  priority_queue<Data> pq;

  for (int y = 0; y < rows; y++) {
    for (int x = 0; x < cols; x++) {
      if (answer[y][x] == 0) {
        pq.push({min(rowMax[y], colMax[x]), y, x});
      }
    }
  }

  int num = 1;
  while (!pq.empty()) {
    Data cur = pq.top();
    pq.pop();

    while (num <= rows * cols && !usable[num]) {
      num++;
    }

    if (num > cur.maximum) {
      return {};
    }
    answer[cur.y][cur.x] = num;
    usable[num] = false;
  }

  // last check
  for (int y = 0; y < rows; y++) {
    for (int x = 0; x < cols; x++) {
      if (answer[y][x] == 0) {
        return {};
      }
      if (answer[y][x] > rowMax[y] || answer[y][x] > colMax[x]) {
        return {};
      }
    }
  }

  return answer;
}
```

## 고생한 점

X, Y 배열에서 중복된 원소가 존재할 수 있다.