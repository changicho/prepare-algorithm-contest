class Solution {
public:
    int minOperations(vector<int>& v) {
        int ans = 0;
        for (int i = v.size() - 2; i >= 0; i--) {
            if (v[i] > v[i + 1]) {
                for (int j = 2; j * j <= v[i]; j++) {
                    if (v[i] % j == 0) {
                        v[i] = j;
                        ans++;
                        break;
                    }
                }
                if (v[i] > v[i + 1])  return -1;
            }

        }
        return ans;
    }
};

/*
    정수 배열 v가 주어진다. |v| <= 10^5
    v[i] > x 이고 v[i] % x == 0인 x를 proper divisor라 한다.
    1번의 연산으로 v[i] = greatest proper divisor of v[i]로 바꿀 수 있다. ex) v[i] = 12 -> 6
    v[i]를 non decreasing array로 변경하기 위한 연산의 최소 횟수를 계산해라

    연산을 통해 v[i]는 항상 원래의 값보다 작아진다.
    v[i]를 바꿨을 때 v[j](j<i) > v[i]일 수 있으므로 단순 순회는 불가능 (ex. 14, 169, 28)
    v를 역순으로 순회하면서 v[i] > v[i+1]인 경우 v[i]를 가장 큰 divisor로 나눈다. ex) 24 -> 24/12 = 2
    
    
    O(N * sqrt(N)) 이므로 약 O(10^7)
*/
