# B. Dictionary

[link](https://codeforces.com/contest/1674/problem/B)

## 풀이

계산식을 세워서 푼다. 두자리 문자열 xy 중 x를 계산하고자 한다면 y 가 25개가 존재할 수 있기 때문에 x * 25 가 일단 본인의 순서가 된다. 그리고 y를 이용하여 계산하면 되는데 만약 x가 y보다 작을 경우는 그냥 알파벳 순 + 1을 계산하면 된다. 반면에 x가 y보다 클경우는 y자리에 x 가 하나 빠지기 때문에 알파벳순을 더해준다.