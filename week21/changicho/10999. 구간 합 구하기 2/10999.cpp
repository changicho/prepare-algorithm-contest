#include <algorithm>
#include <cmath>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

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

int main() {
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  // freopen("./input.txt", "r", stdin);

  int N, M, K;
  cin >> N >> M >> K;

  vector<long long> arr(N);
  for (int i = 0; i < N; i++) {
    cin >> arr[i];
  }

  SegmentTree<long long> segment(arr);

  for (int i = 0; i < M + K; i++) {
    int command, left, right;
    long long diff;
    cin >> command;

    if (command == 1) {
      cin >> left >> right >> diff;

      segment.update(left - 1, right - 1, diff);
    } else {
      cin >> left >> right;

      cout << segment.query(left - 1, right - 1) << endl;
    }
  }
  cout << endl;

  return 0;
}