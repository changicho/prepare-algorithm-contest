#include <vector>
#include <string>
using namespace std;

bool go(int n, int idx, string& str, vector<int>& v) {
    if (idx == str.size()) {
        int sums = 0;
        for (int i = 0; i < v.size(); i++)  sums += v[i];
        return sums == n;
    }
    bool ans = 0;
    for (int i = 1; idx + i <= str.size(); i++) {
        v.push_back(stoi(str.substr(idx, i)));
        ans |= go(n, idx + i, str, v);
        v.pop_back();
    }
    return ans;
}

class Solution {
public:
    int punishmentNumber(int n) {
        int ans = 0;
        for (int i = 1; i <= n; i++) {
            vector<int> v;
            string str = to_string(i * i);
            if (go(i, 0, str, v)) ans += i * i;
        }
        return ans;
    }
};
