# A. NIT orz!

[링크](https://codeforces.com/contest/1696/problem/A)

## 설계

### 시간 복잡도

arr의 크기를 N이라 하자.

모든 원소를 비교하며 z에 대해 or연산을 수행한다. 여기서 제일 큰 값을 찾는다.

한번의 순회에 O(N)의 시간 복잡도를 사용한다.

### 공간 복잡도

주어진 배열에 or연산한 값들 중 가장 큰 값을 찾는데 별도의 배열등을 사용하지 않는다.

공간 복잡도는 O(1)이다.

### 순회

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      15      |    O(N)     |    O(1)     |

z에는 연산을 수행할 수록 and연산이 수행되므로 작아진다.

따라서 처음 z와 or연산을 수행했을 때 가장 큰 값이 연산 이후에도 가장 큰 값이 된다.

```cpp
int solution(int n, int z, vector<int> &arr) {
  for (int i = 0; i < n; i++) {
    arr[i] |= z;
  }

  int maximum = arr.front();
  for (int &n : arr) {
    maximum = max(maximum, n);
  }

  return maximum;
}
```

## 고생한 점
