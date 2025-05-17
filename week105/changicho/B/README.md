# B - Product Calculator

[링크](https://atcoder.jp/contests/abc406/tasks/abc406_b)

| 난이도 |
| :----: |
|  200   |

## 설계

### 시간 복잡도

### 공간 복잡도

### 나눗셉 연산

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      1       |             |             |

```cpp
long long solution(int n, int k, vector<long long> &nums) {
  long long answer = 1;

  long long limit = 1;
  for (int i = 0; i < k; i++) {
    limit *= 10;
  }
  limit -= 1;

  for (long long &num : nums) {
    if (answer > (limit / num)) {
      answer = 1;
    } else {
      answer *= num;
    }
  }

  return answer;
}
```

### 큰수 연산

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      1       |             |             |

```cpp
string multiply(string s1, string s2) {
  int n1 = s1.size(), n2 = s2.size();
  if (n1 == 0 || n2 == 0) return "0";

  vector<int> temp(n1 + n2, 0);
  int i1 = 0;
  int i2 = 0;
  for (int i = n1 - 1; i >= 0; i--) {
    int carry = 0;
    int n1 = s1[i] - '0';
    i2 = 0;

    for (int j = n2 - 1; j >= 0; j--) {
      int n2 = s2[j] - '0';

      int sum = n1 * n2 + temp[i1 + i2] + carry;
      carry = sum / 10;

      temp[i1 + i2] = sum % 10;

      i2++;
    }

    if (carry > 0) temp[i1 + i2] += carry;

    i1++;
  }

  int i = temp.size() - 1;
  while (i >= 0 && temp[i] == 0) i--;
  if (i == -1) return "0";

  string s = "";
  while (i >= 0) s += to_string(temp[i--]);

  return s;
}

string solution(int n, int k, vector<string> &A) {
  string answer = "1";
  for (string &num : A) {
    answer = multiply(answer, num);

    if (answer.size() > k) {
      answer = "1";
    }
  }

  return answer;
}
```

## 고생한 점
