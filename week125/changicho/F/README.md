# F - 1122 Subsequence 2

[링크](https://atcoder.jp/contests/abc433/tasks/abc433_f)

| 난이도 |
| :----: |
|  500   |

## 설계

### 시간 복잡도

입력받은 문자열 S의 길이를 N이라 하자.

각 index에 대해 이전까지 값의 갯수와 index+1 ~ 까지의 값의 갯수를 저장한다.

이에 prefix sum, suffix sum을 사용할 경우 O(N)의 시간 복잡도를 사용한다.

이후 현재 index에 정답을 만족하는 경우의 수를 구할 수 있다.

이에 조합론을 사용할 수 있다.

조합론에서 페르마의 소정리를 사용할 수 있다. 이 경우 팩토리얼을 미리 구해두는데 O(N)의 시간 복잡도를 사용한다.

조합론으로 해당 값을 구하는데 O(1)의 시간 복잡도를 사용한다.

이후 순회하며 정답을 구하는데 O(N)의 시간 복잡도를 사용한다.

### 공간 복잡도

각 수별로 팩토리얼을 구하는데 O(N)의 공간 복잡도를 사용한다.

prefix sum을 저장하는데 O(N)의 공간 복잡도를 사용한다.

### 페르마의 소정리 & 조합론 & 누적합

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|     113      |    O(N)     |    O(N)     |

누적합을 이용해 특정 index까지의 각 숫자의 갯수를 저장할 수 있다.

이를 index를 변화시키며 누적합을 갱신한다. (0 ~ index, index+1 ~ N-1 두 부분에서 각 숫자의 갯수를 알 수 있다.)

이후 현재 index를 포함하는 정답의 경우의 수를 구한뒤 정답에 더할 수 있다.

이 경우 현재 숫자를 X라 할 때 왼쪽 부분에서 X의 갯수 - 1개, 오른쪽 부분에서 X + 1의 갯수를 사용해 조합론으로 경우의 수를 구할 수 있다.

각 갯수를 p, q라 할 때 각 숫자의 가능한 길이의 경우는 1 ~ min(p,q)개 이다. (11222 의 경우 12, 1122 두 경우만 가능하다.)

이 가능한 숫자를 k라고 두었을 때 구해야 하는 경우의 수는 다음과같다.

```cpp
for(int k=1; k<=min(p,q); k++) {
    answer += combi(p, k) * combi(q, k);
}

// 위 식을 변환하면
for(int k=1; k<=min(p,q); k++) {
    answer += combi(p, k) * combi(q, q - k);
}

// 결과적으로
answer += combi(p + q, p + 1);
```

따라서 각 이항계수의 합을 한번의 이항계수로 구할 수 있다.

여기서 이항계수를 빠르게 구하기 위해 페르마의 소정리를 사용한다.

```cpp
long long myPow(long long base, long long expo) {
  long long result = 1;

  while (expo > 0) {
    if (expo % 2 == 1) {
      result *= base;
      result %= MOD;
    }
    base = (base * base) % MOD;
    expo /= 2;
  }
  return result;
}

// 페르마의 소정리를 이용한 nCk 를 구하는 함수
function<long long(int, int)> combi = [&](int n, int k) -> long long {
  if (k > n || k < 0) return 0;
  if (k == 0 || k == n) return 1;

  long long numer = factorial[n] % MOD;
  long long denom = (factorial[k] * factorial[n - k]) % MOD;

  return numer * myPow(denom, MOD - 2) % MOD;
};
```

이를 이용해 정답을 구할 경우 다음과 같다.

```cpp
int MOD = 998244353;

long long myPow(long long base, long long expo) {
  long long result = 1;

  while (expo > 0) {
    if (expo % 2 == 1) {
      result *= base;
      result %= MOD;
    }
    base = (base * base) % MOD;
    expo /= 2;
  }
  return result;
}

long long solution(string& s) {
  int size = s.size();

  vector<long long> factorial(size * 2 + 10, 1);
  for (int i = 2; i < size * 2 + 10; i++) {
    factorial[i] = (factorial[i - 1] * i) % MOD;
  }

  function<long long(int, int)> combi = [&](int n, int k) -> long long {
    if (k > n || k < 0) return 0;
    if (k == 0 || k == n) return 1;

    long long numer = factorial[n] % MOD;
    long long denom = (factorial[k] * factorial[n - k]) % MOD;

    return numer * myPow(denom, MOD - 2) % MOD;
  };

  int countRight[10] = {0};
  for (int i = 0; i < size; i++) {
    countRight[s[i] - '0']++;
  }
  int countLeft[10] = {0};

  long long answer = 0;
  for (int i = 0; i < size; i++) {
    int cur = s[i] - '0';
    countRight[cur]--;
    countLeft[cur]++;

    if (cur == 9) continue;
    int leftPart = countLeft[cur] - 1;
    int rightPart = countRight[cur + 1];

    long long count = combi(leftPart + rightPart, leftPart + 1);

    count %= MOD;

    answer += count;
    answer %= MOD;
  }

  return answer;
}
```

## 고생한 점
