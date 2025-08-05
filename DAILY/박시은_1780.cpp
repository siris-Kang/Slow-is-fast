#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

vector<vector<int>>paper;

int DAT[3] = { 0, };  // [index: 의미론적 값] 0: -1 , 1: 0, 2: 1


// 종이가 모두 같은 수로 되어있는지 확인
bool checkUniformity(int startPointY, int startPointX, int size) {

    if (size == 1) {
        return true;
    }

    for (int i = startPointY; i < size + startPointY; i++) {
        for (int j = startPointX; j < size + startPointX; j++) {
            if (paper[startPointY][startPointX] != paper[i][j]) {
                return false;
            }
        }
    }
    return true; // 모두 같은 경우
}



// 종이를 자르는 재귀함수
void checkAndDevide(int startPointY, int startPointX, int size) {

    // 종료조건
    if (checkUniformity(startPointY, startPointX, size)) {
        // 종이 자르기가 완료되었으므로 종이 수를 count
        DAT[paper[startPointY][startPointX] + 1]++;
        return;
    }

    // 종료조건 성립되지 않았을 경우, 9분할
    int iterY = startPointY;
    int iterX = startPointX;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            // 9분할된 시작 좌표 Y, X를 계산해 재귀함수 호출 인자로 던져준다.
            // size가 9인 경우: (y, x) -> (0, 0) (0, 3) (0, 6) (3, 0) (3, 3) ...
            checkAndDevide(iterY, iterX, size / 3);
            iterX += size / 3;
        }
        iterY += size / 3;
        iterX = startPointX; // X 좌표는 Y 좌표 변환될 때마다 다시 시작점부터.
    }
}





int main() {

    // 종이 크기와 종이에 적힌 수를 입력받는다.
    int n;
    cin >> n;
        
    paper.resize(n, vector<int>(n));     // new!! 벡터 초기화 함수(알아두자) vector.resize(새 사이즈, 할당할 값(option));

    for (int i = 0; i < n; i++) {
        paper[i] = vector<int>(n);

        for (int j = 0; j < n; j++) {
            cin >> paper[i][j];
        }
    }
    // 재귀함수 호출하여 종이사용여부 체크 + 종이개수 count + 종이미사용 시 함수 호출
    checkAndDevide(0, 0, n);

    // -1, 0, 1 적힌 종이 수 체크
    for (int i = 0; i < 3; i++) {
        cout << DAT[i] << "\n";
    }

    return 0;
}
