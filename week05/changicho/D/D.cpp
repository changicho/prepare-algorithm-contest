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

// time :

int convert(string time) {
  int minute = (time[3] - '0') * 10 + (time[4] - '0');
  int hour = (time[0] - '0') * 10 + (time[1] - '0');

  return hour * 60 + minute;
}

string convertTimeToS(int minutes) {
  int hour = minutes / 60;
  int minute = minutes % 60;

  string line = "";
  if (hour < 10) {
    line += "0";
  }
  line += to_string(hour);
  line += ":";
  if (minute < 10) {
    line += "0";
  }
  line += to_string(minute);
  return line;
}

bool isPalindrome(string &s) {
  int length = s.length();
  for (int i = 0; i < length / 2; i++) {
    if (s[i] != s[length - 1 - i]) return false;
  }
  return true;
}

int solution(string &time, int x) {
  int minute = convert(time);

  unordered_set<int> times;

  while (times.count(minute) == 0) {
    // cout << minute << " ";
    times.insert(minute);
    minute += x;
    minute %= 24 * 60;
  }

  int count = 0;
  for (int time : times) {
    string str = convertTimeToS(time);
    // cout << str << endl;

    if (isPalindrome(str)) count++;
  }

  return count;
}

int main() {
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  // freopen("./input.txt", "r", stdin);

  int T;
  cin >> T;

  for (int testCase = 1; testCase <= T; testCase++) {
    string time;
    int X;

    cin >> time >> X;

    int ret = solution(time, X);

    cout << ret << "\n";
  }

  return 0;
}