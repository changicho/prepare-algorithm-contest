# 10999. 구간 합 구하기 2

[링크](https://www.acmicpc.net/problem/10999)

|   난이도    | 정답률(\_%) |
| :---------: | :---------: |
| Platinum IV |   32.086    |

## 설계

### 시간 복잡도

원소의 갯수를 N, 갱신의 수를 M, 쿼리의 수를 K라 하자.

각 경우를 모두 브루트 포스로 구현할 경우 O(N \* (M + K))의 시간 복잡도를 사용하며 이는 제한시간 내에 불가능하다.

세그먼트 트리를 이용할 경우 생성에는 O(N)의 시간 복잡도를 사용한다. 갱신과 쿼리에 O(log_2(N))의 시간 복잡도로 수행 가능하다.

그러나 세그먼트 트리를 매번 업데이트를 직접 해주는 경우 시간초과가 발생한다.

따라서 업데이트를 할 때 lazy propagation을 이용한다.

[lazy propagation](https://www.acmicpc.net/blog/view/26)

### 공간 복잡도

세그먼트 트리에 O(N)의 공간 복잡도를 사용한다.

모든 수의 형태는 int형을 초과할 수 있으므로 long long 형으로 선언한다.

## 정리

| 내 코드 (ms) |
| :----------: |
|     604      |

lazy propagation을 이용한 세그먼트 트리를 생성한다.

```cpp
template <class T>
struct SegmentTree {
  const T NULL_VALUE = 0;
  int size;
  vector<T> tree;
  vector<T> lazyDiff;

  SegmentTree(vector<T> &array) {
    size = array.size();

    tree.resize(size * 4);
    lazyDiff.resize(size * 4);

    init(1, 0, size - 1, array);
  }

  // operation part

  T operation(T x, T y) { return x + y; }

  // initialize part

  void init(int node, int start, int end, vector<T> &array) {
    if (start == end) {
      tree[node] = array[start];
      return;
    }

    int mid = (start + end) / 2;
    init(node * 2, start, mid, array);
    init(node * 2 + 1, mid + 1, end, array);

    tree[node] = operation(tree[node * 2], tree[node * 2 + 1]);
  }

  // query part

  T query(int left, int right) { return query(1, 0, size - 1, left, right); }

  T query(int node, int start, int end, int left, int right) {
    // only use lazy propagation
    _lazy(node, start, end);

    if (right < start || end < left) {
      return NULL_VALUE;
    }
    if (left <= start && end <= right) {
      return tree[node];
    }

    int mid = (start + end) / 2;
    T leftPart = query(node * 2, start, mid, left, right);
    T rightPart = query(node * 2 + 1, mid + 1, end, left, right);
    return operation(leftPart, rightPart);
  }

  // update lazy part

  void _lazy(int node, int start, int end) {
    if (lazyDiff[node] == 0) {
      return;
    }

    tree[node] += (end - start + 1) * lazyDiff[node];
    if (start != end) {
      lazyDiff[node * 2] += lazyDiff[node];
      lazyDiff[node * 2 + 1] += lazyDiff[node];
    }
    lazyDiff[node] = 0;
  }

  void update(int index, T diff) { update(1, 0, size - 1, index, index, diff); }

  void update(int left, int right, T diff) {
    update(1, 0, size - 1, left, right, diff);
  }

  void update(int node, int start, int end, int left, int right, T diff) {
    _lazy(node, start, end);

    if (right < start || end < left) {
      return;
    }
    if (start == end) {
      tree[node] += diff;
      return;
    }
    if (left <= start && end <= right) {
      tree[node] += (end - start + 1) * diff;

      lazyDiff[node * 2] += diff;
      lazyDiff[node * 2 + 1] += diff;
      return;
    }

    int mid = (start + end) / 2;
    update(node * 2, start, mid, left, right, diff);
    update(node * 2 + 1, mid + 1, end, left, right, diff);

    tree[node] = operation(tree[node * 2], tree[node * 2 + 1]);
  }
};
```

## 고생한 점
