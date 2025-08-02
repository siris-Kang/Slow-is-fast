#include <iostream>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <queue>
#include <stack>
#include <algorithm>
#include <utility>
using namespace std;

vector<pair<int, int>> price;
int table[1000001] = { 0, };

int main(int argc, char** argv) {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    /*
        문제 정의
        N개의 가격이 주어진다.
        하루에 하나의 주식을 살 수 있다.
        가격이 최대가 되는 값을 출력한다.

        그냥 1~N까지 2중 for문 돌린다.
        1 가격 < max(2, 3, ... N) 이면 그 날에 판다.
        -> 안됨 1000000 * 1000000 = 1조 -> 10000초임

        정렬한다.
        정렬할 때 price, idx로 정렬한다.
        1번째 요소를 검사해서, 뒤에 나오는 모든 원소들에 대해서
        n.idx < 1.idx인 경우 sum에 추가한다.
        -> 1번 방법이랑 똑같음

        테이블을 만든다.
        현재 날짜 이후에 나오는 최대값을 저장할 것이다.
        가격이 1 3 5 7 6 3 5이면
               7 7 7 6 5 5 0
        -> 최대값이 자기보다 작으면 0으로 바꾼다.
               7 7 7 0 0 5 0

        테이블 값 - 자신 가격의 sum이 정답

        테이블 만드는 방법
        맨 뒤 인덱스부터 확인하면서 i-1번째 인덱스의 가격이 i번째 인덱스 가격보다 크면 갱신한다.
        i-1번째 인덱스의 가격이 i번째 인덱스 가격보다 작은 경우 최대값을 갱신한다.

        가격이 낮은 순서로 정렬한다.

        DAT사용하기

    */

    int T, N;
    cin >> T;
    for (int t = 0; t < T; t++) {
        cin >> N;
        price.clear();
        for (int i = 0; i < N; i++) {
            int input;
            cin >> input;
            table[i] = 0;
            price.push_back({ input, i });
        }


        int nexp, nexi, maxp;
        maxp = price[N - 1].first;
        for (int i = N - 1; i >= 1; i--) {
            nexp = price[i - 1].first;
            nexi = price[i - 1].second;

            if (maxp > nexp) {
                table[nexi] = maxp;
            }
            else {
                table[nexi] = 0;
                maxp = nexp;
            }
        }

        long long sum = 0;
        for (int i = 0; i < N; i++) {
            //cout << "price, table : " << price[i].first << " " << table[i] << "\n";
            if (table[i]) {
                sum += (table[i] - price[i].first);
            }
        }

        cout << sum << "\n";


    }

    return 0;
}