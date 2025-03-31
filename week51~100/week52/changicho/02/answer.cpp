#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

struct Song {
  string name;
  int length;
};

string getPrefix(string &a, string &b) {
  int size = min(a.size(), b.size());
  string temp = "";
  for (int i = 0; i < size; i++) {
    if (a[i] != b[i]) break;
    temp += a[i];
  }
  return temp;
}

string compare(string &a, string &b) {
  if (a.size() > b.size()) return a;
  if (a.size() < b.size()) return b;
  return min(a, b);
}

string solution(vector<Song> &songs, int k) {
  int size = songs.size();

  vector<string> before(k + 1, "");
  vector<string> prefixes(size, "");
  for (int i = 1; i < size; i++) {
    prefixes[i] = getPrefix(songs[i - 1].name, songs[i].name);
  }

  before[songs[0].length] = songs[0].name;
  for (int i = 1; i < size; i++) {
    vector<string> temp(k + 1, "");
    string name = songs[i].name;
    int length = songs[i].length;

    for (int time = 0; time <= k; time++) {
      if (before[time] == "") continue;

      temp[time] = compare(before[time], temp[time]);

      int nextTime = time + length;
      if (nextTime > k) continue;

      string nextName = getPrefix(before[time], name);
      temp[nextTime] = compare(temp[nextTime], nextName);
    }
    temp[length] = compare(temp[length], name);

    before = temp;
  }

  string answer = before[k];

  return answer;
}

int main() {
  ios_base::sync_with_stdio(false);

  cin.tie(NULL);
  cout.tie(NULL);

  // freopen("input.txt", "r", stdin);

  int N, K;
  cin >> N >> K;

  vector<Song> songs(N);
  for (int i = 0; i < N; i++) {
    cin >> songs[i].name >> songs[i].length;
  }
  sort(songs.begin(), songs.end(),
       [](Song &a, Song &b) { return a.name < b.name; });

  string answer = solution(songs, K);

  if (answer == "") {
    cout << "0" << endl;
  } else {
    cout << answer.size() << " " << answer << endl;
  }
  return 0;
}