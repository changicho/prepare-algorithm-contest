# E. Binary Deque

[link](https://codeforces.com/problemset/problem/1692/E)

## 풀이

왼쪽에서부터 한칸씩 배열을 순회하면서 각 위치의 1의 개수를 센다. 반대로 오른쪽에서도 마찬가지로해서 배열 두개로 저장한다. 그리고 나서 먼저 오른쪽에서 1을 제거해서 목표점에 도달할수 있는 선까지 rightIndex를 움직이고, 그다음에 leftIndex와 rightIndex를 조합하면서 길이가 짧은 조합을 찾아낸다.