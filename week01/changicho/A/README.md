# A. Number Transformation

[link](https://codeforces.com/contest/1674/problem/A)

time : 15min ~ 20min

## 풀이

> 약수를 찾아 풀이

x를 y로 만들기 위한 정수 두 쌍을 찾아야한다.

정수 쌍이 존재하기 위해선 y를 x로 나눈 나머지가 0이여야 한다. (x가 y의 약수여야함)

또한 분수, 음의 정수는 불가능하므로 y는 x이상이여야 한다.

정답은 어느것이여도 상관없으므로 1과 y/x 인 값을 한번 곱한 값의 쌍을 정답으로 반환한다.