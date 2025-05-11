# A. Kamilka and the Sheep

[링크](https://codeforces.com/contest/2092/problem/A)

| 난이도 |
| :----: |
|  800   |

## 설계

### 시간 복잡도

배열 nums의 크기를 N이라 하자.

nums의 최소값과 최대값을 구하는데 O(N)의 시간이 걸린다.

이를 이용해 정답을 구할 경우 총 O(N)의 시간이 걸린다.

### 공간 복잡도

최대값, 최소값을 저장하는데 O(1)의 공간이 필요하다.

### 수학

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      62      |    O(N)     |    O(1)     |

```cpp
int solution(int size, vector<int> &nums) {
  int maximum = *max_element(nums.begin(), nums.end());
  int minimum = *min_element(nums.begin(), nums.end());

  return maximum - minimum;
}
```

## 고생한 점
