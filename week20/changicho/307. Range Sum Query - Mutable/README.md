# 307. Range Sum Query - Mutable

[링크](https://leetcode.com/problems/range-sum-query-mutable/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

nums의 크기를 N이라 하자.

구간의 합을 매번 구할 경우 시간 복잡도는 O(N), 업데이트에 O(1)의 시간 복잡도가 소요된다.

이를 모든 쿼리(Q)에 대해 수행할 경우 최악의 경우 O(N \* Q)의 시간 복잡도가 소요되며 이는 제한시간 내에 불가능하다.

세그먼트 트리를 이용해 구간합을 최적화 할 수 있다.

이 경우 쿼리와 업데이트에 O(log_2(N))의 시간 복잡도를 사용하므로 O(Q \* log_2(N))의 시간 복잡도로 풀이가 가능하다.

### 공간 복잡도

세그먼트 트리를 생성하는데 O(N)의 공간이 필요하다.

### 세그먼트 트리

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|     1129      | O(log_2(N)) |    O(N)     |

세그먼트 트리는 구간에 대한 연산을 미리 구해놓고 업데이트마다 필요한 부분만 연산해 구간연산을 쉽게 구하는 방법이다.

배열의 각 값은 트리의 리프노드로, 루트 노드는 모든 값을 연산한 값으로 설정한다.

쿼리의 경우 range에 대해서 루트노드부터 순회하며 필요한 부분만 꺼내온다.

업데이트의 경우 range에 대해서 루트 노드부터 순회하며 필요한 부분만 업데이트한다.

세그먼트 트리를 다음과 같이 구현할 수 있다.

```cpp
template <class T, class O>
struct SegmentTree {
  const T NULL_VALUE = 0;
  int size;
  vector<O> arr;
  vector<T> tree;

  SegmentTree(vector<O> &array) {
    size = array.size();

    arr = array;
    tree.resize(size * 4);

    init(1, 0, size - 1);
  }

  T operation(T x, T y) { return x + y; }

  T init(int node, int start, int end) {
    if (start == end) {
      return tree[node] = arr[start];
    }
    int mid = (start + end) / 2;

    return tree[node] = operation(init(node * 2, start, mid),
                                  init(node * 2 + 1, mid + 1, end));
  }

  void update(int node, int start, int end, int index, T diff) {
    if (index < start || end < index) return;
    if (start == end) {
      tree[node] += diff;
      return;
    }

    int mid = (start + end) / 2;
    update(node * 2, start, mid, index, diff);
    update(node * 2 + 1, mid + 1, end, index, diff);

    tree[node] = operation(tree[node * 2], tree[node * 2 + 1]);
  }

  void update(int index, T diff) { update(1, 0, size - 1, index, diff); }

  void updateValue(int index, T newVal) {
    int diff = newVal - arr[index];
    arr[index] = newVal;
    update(1, 0, size - 1, index, diff);
  }

  T query(int node, int start, int end, int left, int right) {
    if (right < start || end < left) return NULL_VALUE;
    if (left <= start && end <= right) return tree[node];

    int mid = (start + end) / 2;
    return operation(query(node * 2, start, mid, left, right),
                     query(node * 2 + 1, mid + 1, end, left, right));
  }

  T query(int left, int right) { return query(1, 0, size - 1, left, right); }
};
```

이를 이용해 다음과 같이 구현할 수 있다.

```cpp
class NumArray {
 private:
  SegmentTree<int, int>* segment;

 public:
  NumArray(vector<int>& nums) {
    this->segment = new SegmentTree<int, int>(nums);
  }

  void update(int index, int val) { segment->updateValue(index, val); }

  int sumRange(int left, int right) { return segment->query(left, right); }
};
```

## 고생한 점