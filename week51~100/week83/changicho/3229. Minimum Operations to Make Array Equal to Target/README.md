# 3229. Minimum Operations to Make Array Equal to Target

[링크](https://leetcode.com/problems/minimum-operations-to-make-array-equal-to-target/description/)

| 난이도 |
| :----: |
|  Hard  |

## 설계

### 시간 복잡도

배열의 크기를 N이라 하자.

왼쪽부터 순회하며 nums와 target의 해당 index값의 차이를 구하고 이를 갱신하며 정답을 구할 수 있다.

이 경우 순회에 O(N)의 시간 복잡도를 사용한다.

### 공간 복잡도

각 과정마다 최대값, 최소값을 구해야 하므로 이를 저장할 공간이 필요하다.

이에 O(1)의 공간 복잡도를 사용한다.

### 차이의 합

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|     128      |    O(N)     |    O(1)     |

[1526. Minimum Number of Increments on Subarrays to Form a Target Array](https://leetcode.com/problems/minimum-number-of-increments-on-subarrays-to-form-a-target-array/description/) 와 유사한 문제

연속된 상승 구간이 존재한다고 하자. (diff가 양수가 연속된 경우)

왼쪽부터 순횧며 현재 diff의 index를 시작점으로 하는 range를 가능한 최대로 선택한다.

이 경우 순회하며 diff를 갱신하고, 만약 이전 diff보다 현재 diff가 작은 경우 해당 차이만큼 정답에 더한다. (이전 diff에 대한 차이만큼 별도로 증가시켜줌)

각 과정마다 diff를 갱신한다.

이를 음수 diff에 대해서도 동일하게 진행한다.

```cpp
long long minimumOperations(vector<int>& nums, vector<int>& target) {
  int size = nums.size();
  long long increment = 0, decrement = 0;

  long long answer = 0;
  for (int i = 0; i < size; i++) {
    long long diff = target[i] - nums[i];

    if (diff > 0) {
      if (increment < diff) {
        answer += diff - increment;
      }

      increment = diff;
      decrement = 0;
    } else if (diff < 0) {
      if (diff < decrement) {
        answer += decrement - diff;
      }

      decrement = diff;
      increment = 0;
    } else {
      increment = 0;
      decrement = 0;
    }
  }

  return answer;
}
```

## 고생한 점
