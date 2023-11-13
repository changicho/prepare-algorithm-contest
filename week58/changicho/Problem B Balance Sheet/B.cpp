#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

long long MOD = 1e9 + 7;

struct Event {
  int day;
  int price;
  char type;  // buy or sell
  int eventIdx;

  bool operator<(const Event& other) const {
    if (day != other.day) return day > other.day;
    if (price != other.price) return price > other.price;
    // sell first
    if (type != other.type) return type > other.type;
    return eventIdx > other.eventIdx;
  }
};

// pick top size elements from a and b
vector<long long> merge(vector<long long>& a, vector<long long>& b, int size) {
  vector<long long> result;
  int i = 0, j = 0;
  while ((i < a.size() || j < b.size()) && result.size() < size) {
    if (j == b.size() || (i < a.size() && a[i] > b[j])) {
      result.push_back(a[i]);
      i++;
    } else {
      result.push_back(b[j]);
      j++;
    }
  }
  return result;
}

long long solution(int N, int K, vector<Event>& events) {
  sort(events.begin(), events.end());

  // dp[i]; until ith event, max profit
  vector<vector<long long>> dp(N, vector<long long>(1, 0));
  vector<long long> buy;

  for (int idx = 0; idx < events.size(); idx++) {
    int day = events[idx].day;
    int price = events[idx].price;
    char type = events[idx].type;
    int eventIdx = events[idx].eventIdx;

    if (type == 'B') {
      vector<long long> temp = dp[eventIdx];
      for (int j = 0; j < temp.size(); j++) {
        temp[j] += price;
      }

      buy = merge(buy, temp, K);
    } else {
      vector<long long> temp = buy;
      for (int j = 0; j < temp.size(); j++) {
        temp[j] -= price;
      }

      dp[eventIdx] = merge(dp[eventIdx], temp, K);
    }

    // if day changed, clear buy
    if (idx + 1 < events.size() && events[idx + 1].day != day) {
      buy.clear();
    }
  }

  long long result = 0;
  vector<long long> allMergedDp;
  for (vector<long long>& cur : dp) {
    allMergedDp = merge(allMergedDp, cur, K);
  }
  for (long long val : allMergedDp) {
    result = (result + val) % MOD;
  }

  return result;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  // freopen("input.txt", "r", stdin);
  freopen("balance_sheet_input.txt", "r", stdin);

  int T;
  cin >> T;
  for (int testCase = 1; testCase <= T; testCase++) {
    int N, K;
    cin >> N >> K;

    vector<Event> events;
    for (int i = 0; i < N; i++) {
      int A, B, X, Y;
      cin >> A >> B >> X >> Y;

      // B : buy, S : sell
      // sell > buy
      events.push_back({A, X, 'B', i});
      events.push_back({B, Y, 'S', i});
    }

    long long result = solution(N, K, events);
    cout << "Case #" << testCase << ": " << result << "\n";
  }

  return 0;
}
