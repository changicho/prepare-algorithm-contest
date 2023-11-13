class Solution {
public:
    long long distributeCandies(int n, int limit) {
        long long ans = 0;
        int minA = max(0, n - limit * 2), maxA = min(limit, n);
        for (int i=minA; i<=maxA; i++){
            int bPlusC = n - i;
            if (bPlusC > limit * 2) continue;
            int secondMin = max(0, n - i - limit);
            int secondMax = min(limit, n - i);
            ans += secondMax - secondMin + 1;
        }
        return ans;
    }
};

/*
a+b+c = n AND a,b,c <= limit 을 만족하는 경우의 수를 계산해라.

a, b+c 를 나누어서 생각한다.
a = min(0, n - limit * 2) ~ max(n, limit)개를 줄 수 있다.
a가 정해지면 b+c도 계산 가능하다.
b+c = k라 하면, b=0/c=k, b=1,c=k-1 ... 이므로 k+1개의 조합이 가능하다.
따라서 b+c의 min, max를 구해 max - min + 1을 각각 더한다.

O(n) / O(1)


*/
