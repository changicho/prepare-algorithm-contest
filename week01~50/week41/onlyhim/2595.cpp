class Solution {
public:
    vector<int> evenOddBit(int n) {
        vector<int> ans(2, 0);
        string str;
        while (n){
            str = str + (n%2 ? '1' : '0');
            n/=2;
        }
        for (int i=0; i<str.size(); i++){
            if (str[i] == '1'){
                ans[i%2]++;
            }
        }
        return ans;
    }
};
