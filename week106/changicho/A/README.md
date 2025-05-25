# A. Fashionable Array

[링크](https://codeforces.com/contest/2110/problem/A)

| 난이도 |
| :----: |
|  500   |

## 설계

### 시간 복잡도

배열 nums의 크기를 N이라 하자.

정렬 후 각 쌍에 대해서 정답을 만족하는 쌍을 찾으며 정답을 갱신한다.

이에 정렬에 O(N \* log_2(N)), 각 쌍에 대해서 O(N^2)의 시간 복잡도를 가지므로 전체 시간 복잡도는 O(N^2)이다.

### 공간 복잡도

정렬에 O(N)의 공간 복잡도를 사용하므로 전체 공간 복잡도는 O(N)이다.

### 정렬 & 브루트 포스

| 내 코드 (ms) |   시간 복잡도    | 공간 복잡도 |
| :----------: | :--------------: | :---------: |
|      62      | O(N \* log_2(N)) |   O(N^2)    |

```cpp
int solution(int size, vector<int> &nums) {
  int answer = size - 1;

  sort(nums.begin(), nums.end());

  for (int i = 0; i < size; i++) {
    for (int j = i + 1; j < size; j++) {
      if ((nums[i] + nums[j]) % 2 == 0) {
        answer = min(answer, i + (size - j - 1));
      }
    }
  }

  return answer;
}
```

## 고생한 점
