# B. All Distinct

[link](https://codeforces.com/problemset/problem/1692/B)

## 풀이

일단 set으로 모든 값을 다 저장. 그리고 원본 배열과 길이 비교를 한다. 길이의 차이가 짝수이면, 2개씩 지워도 set의 길이가 될수 있기 때문에 그대로 반환하고, 만약 홀수이면 숫자 하나를 더 지워야하기때문에 set의 사이즈 - 1을 반환한다.