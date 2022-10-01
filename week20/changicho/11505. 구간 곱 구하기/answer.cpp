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

const int MOD = 1000000007;

template <class T, class O>
struct SegmentTree {
  const T NULL_VALUE = 1;  // X * 1 = X
  int size;
  vector<O> arr;
  vector<T> tree;

  SegmentTree(vector<O> &array) {
    size = array.size();

    arr = array;
    tree.resize(size * 4);

    init(1, 0, size - 1);
  }

  T operation(T x, T y) { return (x * y) % MOD; }

  T init(int node, int start, int end) {
    if (start == end) {
      return tree[node] = arr[start];
    }
    int mid = (start + end) / 2;

    return tree[node] = operation(init(node * 2, start, mid),
                                  init(node * 2 + 1, mid + 1, end));
  }

  T query(int node, int start, int end, int left, int right) {
    if (right < start || end < left) return NULL_VALUE;
    if (left <= start && end <= right) return tree[node];

    int mid = (start + end) / 2;
    return operation(query(node * 2, start, mid, left, right),
                     query(node * 2 + 1, mid + 1, end, left, right));
  }

  T query(int left, int right) { return query(1, 0, size - 1, left, right); }

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
};

vector<int> solution(vector<int> &nums, vector<vector<int>> &queries) {
  int size = nums.size();
  SegmentTree<long long, int> segment(nums);

  vector<int> answer;

  for (vector<int> &query : queries) {
    if (query[0] == 1) {
      segment.updateValue(query[1] - 1, query[2]);
    } else {
      answer.push_back(segment.query(query[1] - 1, query[2] - 1));
    }
  }
  return answer;
}

int main() {
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  // freopen("./input.txt", "r", stdin);

  int N, M, K;
  cin >> N >> M >> K;

  vector<int> nums(N);
  for (int i = 0; i < N; i++) {
    cin >> nums[i];
  }

  vector<vector<int>> queries;
  for (int i = 0; i < M + K; i++) {
    int type, from, to;
    cin >> type >> from >> to;
    queries.push_back({type, from, to});
  }

  vector<int> answer = solution(nums, queries);

  for (int &val : answer) {
    cout << val << "\n";
  }

  return 0;
}