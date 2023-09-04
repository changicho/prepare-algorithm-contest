class Solution {
public:
    string makeSmallestPalindrome(string s) {
        for (int i=0; i<s.size()/2; i++){
            char minChar = min(s[i], s[s.size()-1-i]);
            s[i] = s[s.size()-1-i] = minChar;
        }
        return s;
    }
};
