#include <iostream>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <queue>
#include <stack>
#include <algorithm>
#include <utility>
using namespace std;

int board[6][6];
int check[6][6];

int cntcheck(int cnt) {
    if (cnt > 2) return 1;
    return 0;
}

int bingocheck() {
    int row, col, diag, cnt;
    cnt = 0;

    for (int i = 0; i < 5; i++) {
        row = 0;
        for (int j = 0; j < 5; j++) {
            if (check[i][j] == 1) row++;
            if (row == 5) {
                cnt++;
            }
            if (cntcheck(cnt)) return 1;
        }
    }

    for (int i = 0; i < 5; i++) {
        col = 0;
        for (int j = 0; j < 5; j++) {
            if (check[j][i] == 1) col++;
            if (col == 5) {
                cnt++;
            }
            if (cntcheck(cnt)) return 1;
        }
    }

    diag = 0;
    for (int i = 0; i < 5; i++) {
        if (check[i][i] == 1) diag++;
        if (diag == 5) {
            cnt++;
        }
        if (cntcheck(cnt)) return 1;
    }

    diag = 0;
    for (int i = 0; i < 5; i++) {
        if (check[i][4 - i] == 1) diag++;
        if (diag == 5) {
            cnt++;
        }
        if (cntcheck(cnt)) return 1;
    }

    if (cntcheck(cnt)) return 1;
    return 0;
}

void printboard() {
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            cout << check[i][j] << " ";
        }
        cout << endl;
    }
}

int main(int argc, char** argv) {

    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            cin >> board[i][j];
        }
    }

    int input;
    for (int i = 0; i < 25; i++) {
        cin >> input;
        for (int j = 0; j < 5; j++) {
            for (int k = 0; k < 5; k++) {
                if (board[j][k] == input) {
                    check[j][k] = 1;
                }
                if (bingocheck()) {
                    //printboard();
                    cout << i + 1;
                    return 0;
                }
            }
        }
    }

    return 0;
}