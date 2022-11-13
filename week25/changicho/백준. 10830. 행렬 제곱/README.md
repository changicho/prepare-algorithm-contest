# 백준. 10830. 행렬 제곱

[링크](https://www.acmicpc.net/problem/10830)

| 난이도  |
| :-----: |
| 골드 IV |

## 설계

### 시간 복잡도

입력받은 수를 B, 정방 행렬의 크기를 N이라 하자.

정방 행렬의 곱에 O(N^3)의 시간 복잡도를 사용한다.

B번 매번 곱할 경우 B가 매우 크므로 절반씩 나눠서 곱을 수행한다.

이 경우 총 O(log_2(B))번 곱을 수행하게 된다.

따라서 시간 복잡도는 O(N^3 \* log_2(B))가 된다.

### 공간 복잡도

행렬을 저장하는 데 O(N^2)의 공간 복잡도를 사용한다.

재귀함수의 call stack에 O(log_2(B))의 공간 복잡도를 사용한다.

각 호출마다 새로운 행렬을 생성하고 반환하므로 O(N^2 \* log_2(B))의 공간 복잡도를 사용한다.

### 분할 정복

| 내 코드 (ms) |    시간 복잡도     |    공간 복잡도     |
| :----------: | :----------------: | :----------------: |
|      0       | O(N^3 \* log_2(B)) | O(N^2 \* log_2(B)) |

```cpp
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
```

## 고생한 점
