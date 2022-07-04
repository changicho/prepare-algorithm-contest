# Building Palindromes (6pts, 8pts)

[링크](https://codingcompetitions.withgoogle.com/kickstart/round/00000000008f4a94/0000000000b54d3b)

|    난이도    |
| :----------: |
| (6pts, 8pts) |

## 설계

### 시간 복잡도

s의 길이를 N이라 하자.

각 글자수에 대한 prefix sum을 미리 구하고 쿼리마다 팰린드롬을 만들 수 있는지 판단한다.

prefix sum을 만드는데 O(N)의 시간 복잡도를 사용하고, questions를 순회하는 데 O(Q)의 시간 복잡도를 사용한다.

따라서 시간 복잡도는 O(N + Q)이다.

### 공간 복잡도

prefix sum을 사용하는 데 O(N)의 공간 복잡도를 사용한다.

### prefix sum

| 시간 복잡도 | 공간 복잡도 |
| :---------: | :---------: |
|  O(N + Q)   |    O(N)     |

각 알파벳 갯수에 따른 prefix sum을 생성하고, 이후 question을 순회하며 L ~ R까지의 문자들로 팰린드롬을 생성할 수 있는지 판단한다.

## 고생한 점
