#include <iostream>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <queue>
#include <stack>
#include <algorithm>
#include <utility>
using namespace std;

int main(int argc, char** argv) {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    /*
        문제 정의
        H W가 주어진다.
        W만큼 블록이 주어진다.
        높은 블록 사이의 공간에는 물이 고인다.
        물의 총량을 출력한다.

        각각의 블록마다 왼쪽과 오른쪽을 모두 살핀다.
        자신보다 큰 높은 블록이 있으면 왼쪽 최대값과 오른쪽 최대값을 업데이트한다.
        min(leftmax, rightmax) - 자기 블록 높이를 sum에 누적한다.

    */

    int H, W;
    cin >> H >> W;
    int blocks[501];
    int mark[501] = {0, };
    int sum = 0;
    for (int i = 0; i < W; i++) {
        cin >> blocks[i];
    }

    int leftmax, rightmax;
    for(int i=1; i < W - 1; i++) {
        leftmax = rightmax = 0;
        for(int j=0; j < W; j++) {
            if(blocks[i - j] > leftmax && i - j >= 0) leftmax = blocks[i - j];
            if(blocks[i + j] > rightmax && i + j < W) rightmax = blocks[i + j];
        }
        // cout << "i = " << i << " j = " << j << " max = " << leftmax << " " << rightmax << " sum : " << blocks[i] << " " << min(leftmax, rightmax) << endl;
        sum += min(leftmax, rightmax) - blocks[i];

        // cout << sum << endl;
    }

    cout << sum << "\n";

    return 0;
}