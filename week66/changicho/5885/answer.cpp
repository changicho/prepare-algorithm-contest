#include <algorithm>
#include <iostream>
#include <set>
#include <string>
#include <unordered_set>
#include <vector>

using namespace std;

struct Land {
  int x, h;
  bool operator<(const Land &b) const { return h < b.h; }
};

int solution(vector<int> &heights) {
  // 100,000
  int size = heights.size();

  vector<bool> underwater(size, false);

  vector<Land> lands;
  for (int x = 0; x < size; x++) {
    lands.push_back({x, heights[x]});
  }

  sort(lands.begin(), lands.end());

  int numIslands = 1;
  int maxIslands = 1;
  for (int i = 0; i < size; i++) {
    int x = lands[i].x;

    underwater[x] = true;
    bool landToLeft = (x > 0 && !underwater[x - 1]);
    bool landToRight = (x < size - 1 && !underwater[x + 1]);

    if (landToLeft && landToRight) {
      numIslands++;
    } else if (!landToLeft && !landToRight) {
      numIslands--;
    }

    if ((i == size - 1 || lands[i + 1].h > lands[i].h) &&
        numIslands > maxIslands) {
      maxIslands = numIslands;
    }
  }

  return maxIslands;
}

int main() {
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  freopen("input.txt", "r", stdin);

  int N;
  cin >> N;

  vector<int> H(N);
  for (int i = 0; i < N; i++) {
    cin >> H[i];
  }

  int answer = solution(H);
  cout << answer << "\n";

  return 0;
}