int go(string& s, int idx, vector<string>& v) {
    if (v.size() > 0 && v.back()[0] == '0')    return 1e9;
    if (idx == s.size()) {
        bool isInvalid = 0;
        for (int i = 0; i < v.size() && !isInvalid; i++) {
            int val = stoi(v[i], 0, 2);
            while (!isInvalid) {
                if (val == 1)   break;
                if (val % 5 != 0)   isInvalid = 1;
                val /= 5;
            }
        }
        if (isInvalid)  
            return 1e9;
        else
            return v.size();
    }
    int ans = 1e9, len = 1;
    for (int i = idx; i <s.size(); i++) {
        string str = s.substr(idx, len);
        v.push_back(str);
        ans = min(ans, go(s, i + 1, v));
        v.pop_back();
        len++;
    }
    return ans;
}

class Solution {
public:
    int minimumBeautifulSubstrings(string s) {
        vector<string> v;
        int ans = go(s, 0, v);
        return ans == 1e9 ? -1 : ans;
    }
};
