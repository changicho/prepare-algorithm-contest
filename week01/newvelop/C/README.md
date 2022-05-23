# C. Infinite Replacement

[link](https://codeforces.com/contest/1674/problem/C)

## 풀이

바꿀 문자열에 a가 들어있을 경우, 두가지 케이스로 나뉜다. a가 하나일 경우는 그냥 그자체로 변환하기 때문에 더이상 케이스가 늘어나지 않는다. 반면에 길이가 2 이상일 경우는 무한이다. 그리고 a가 없을 경우는 a의 개수만큼 변경이 가능하다. 따라서 2^n이다.