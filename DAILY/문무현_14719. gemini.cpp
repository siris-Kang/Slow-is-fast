#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int H, W;
    cin >> H >> W;

    vector<int> blocks(W);
    for (int i = 0; i < W; i++) {
        cin >> blocks[i];
    }

    if (W < 3) {
        cout << 0 << "\n";
        return 0;
    }

    int total_water = 0;
    int left = 0, right = W - 1;
    int left_max = 0, right_max = 0;

    while (left < right) {
        // 더 낮은 쪽을 기준으로 벽(max)을 설정하고 포인터를 이동시킨다.
        if (blocks[left] < blocks[right]) {
            // 현재 왼쪽 블록 높이가 왼쪽 최대 높이보다 크거나 같으면, 물이 고일 수 없으므로 max를 갱신한다.
            if (blocks[left] >= left_max) {
                left_max = blocks[left];
            } else {
            // 현재 블록 높이가 왼쪽 최대 높이보다 낮으면, 그 차이만큼 물이 고인다.
                total_water += left_max - blocks[left];
            }
            left++;
        } else {
            // 현재 오른쪽 블록 높이가 오른쪽 최대 높이보다 크거나 같으면, 물이 고일 수 없으므로 max를 갱신한다.
            if (blocks[right] >= right_max) {
                right_max = blocks[right];
            } else {
            // 현재 블록 높이가 오른쪽 최대 높이보다 낮으면, 그 차이만큼 물이 고인다.
                total_water += right_max - blocks[right];
            }
            right--;
        }
    }

    cout << total_water << "\n";

    return 0;
}