# B. Polycarp Writes a String from Memory

[링크](https://codeforces.com/contest/1702/problem/B)

문자열을 하나씩 순회하면서 set에 문자열을 넣는다. 만약 set에 있는 문자열이면 지나가고, 없는 문자열이면 set이 크기가 3이면 초기화하고 count 1증가후 삽입, 미만이면 그냥 set에 추가를 한다. 이 count를 반환하면 된다. 