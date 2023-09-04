#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std;

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
