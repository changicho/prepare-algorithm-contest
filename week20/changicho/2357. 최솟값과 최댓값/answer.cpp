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

template <class T, class O>
struct SegmentTree {
  const T NULL_VALUE = {0, 1000000001};  // max, min
  int size;
  vector<O> arr;
  vector<T> tree;

  SegmentTree(vector<O> &array) {
    size = array.size();

    arr = array;
    tree.resize(size * 4);

    init(1, 0, size - 1);
  }

  T operation(T x, T y) {
    T ret = {max(x.first, y.first), min(x.second, y.second)};
    return ret;
  }

  T init(int node, int start, int end) {
    if (start == end) {
      return tree[node] = {arr[start], arr[start]};
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
};

vector<pair<int, int>> solution(vector<int> &nums,
                                vector<pair<int, int>> &queries) {
  int size = nums.size();

  SegmentTree<pair<int, int>, int> segment(nums);

  vector<pair<int, int>> answer;

  for (pair<int, int> &query : queries) {
    answer.push_back(segment.query(query.first - 1, query.second - 1));
  }
  return answer;
}

int main() {
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  // freopen("./input.txt", "r", stdin);

  int N, M;
  cin >> N >> M;

  vector<int> nums(N);
  for (int i = 0; i < N; i++) {
    cin >> nums[i];
  }

  vector<pair<int, int>> queries(M);
  for (int i = 0; i < M; i++) {
    cin >> queries[i].first >> queries[i].second;
  }

  vector<pair<int, int>> answer = solution(nums, queries);

  for (pair<int, int> &line : answer) {
    cout << line.second << " " << line.first << "\n";
  }

  return 0;
}