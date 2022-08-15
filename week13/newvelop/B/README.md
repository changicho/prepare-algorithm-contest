# Problem B: Xs and Os

[링크](https://www.facebook.com/codingcompetitions/hacker-cup/2021/qualification-round/problems/B)


## 설계

각 문자배열을 순회하면서, O가 있는지 체크하고 한개도 없으면 .의 개수를 카운트한다. 만약 .의 개수가 현재 최소인경우, 답의 후보군이기 때문에 저장한다. 만약 .의 최소값이 1이 되면 십자가 모양으로, 하나의 원소를 통해 두곳이 가로 세로 다 빙고 한줄이 만들어질수 있다. 따라서 1일 경우 이 중복을 제거하기 위해 좌표를 저장하고 이 개수를 값으로 한다.