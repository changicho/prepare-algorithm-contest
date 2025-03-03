#include <string>
#include <vector>

using namespace std;

int solution(int n, int w, int num) {
    int ans = 0, curHeight = num % w == 0 ? num / w : num / w + 1;
    int curBox = num;

    while (1) {
        int next, nextBox;
        next = w * curHeight;

        nextBox = curBox + (next - curBox) * 2 + 1;
        if (nextBox > n)    break;
        else {
            curBox = nextBox;
            ans++;
            curHeight++;
        }
    }
    return ans+1;
}

/*
  현재 box의 height에서 height+1의 box 넘버를 계산하고, 이를 전체 box 갯수를 넘지 않을 때 까지 갱신시킨다.
*/
