# C. Where's the Bishop?

[link](https://codeforces.com/problemset/problem/1692/C)

## 풀이

귀찮게 풀었던 문제. 가장자리에서 비숍이 배치될 일이 없기 때문에, 이를 감안해서 규칙을 찾아보면

1. 맨위와 맨아래에 비숍이 갈 수 있는 경로가 둘다 2개 있으면, 위 아래 상관없이 가운데 쪽으로 향해서 경로가 한개가 되는 곳까지 내려가고 그 위치가 답이다.
2. 위나 아래 둘중에 한곳이 경로가 1이면 2인 쪽에서 부터 가운데 쪽으로 읽어내려가서 1이 되는 곳으로 간다.
3. 둘다 1로 시작하면 1 -> 2 가 되는 구간을 찾고 다시 2-> 1이 되는 구간을 찾아서 이 때 1이 비숍의 위치이다.

이 규칙을 조건문으로 해서 해결했다.