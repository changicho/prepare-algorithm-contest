#include <algorithm>
#include <climits>
#include <cmath>
#include <functional>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

long long solution(int size, long long m, vector<long long>& nums) {
  vector<unordered_map<long long, int>> digitCount(12);

  for (unsigned long long num : nums) {
    for (int count = 0; count <= 11; count++) {
      digitCount[count][num % m]++;

      num *= 10ULL;
    }
  }

  long long answer = 0;
  for (long long num : nums) {
    int length = log10(num) + 1;

    long long target = (m - (num % m)) % m;
    answer += digitCount[length][target];
  }

  return answer;
}

int main() {
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cout.precision(10);

  // freopen("./input.txt", "r", stdin);

  int N;
  long long M;
  cin >> N >> M;

  vector<long long> A(N);

  for (int i = 0; i < N; i++) {
    cin >> A[i];
  }

  auto answer = solution(N, M, A);

  cout << answer << endl;
  // cout << (answer ? "Yes" : "No") << endl;
  // for (auto &line : answer) {
  //   cout << line << "\n";
  // }
  // cout << endl;

  return 0;
}