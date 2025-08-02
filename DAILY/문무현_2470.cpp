#include <iostream>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <queue>
#include <stack>
#include <algorithm>
#include <utility>
#include <climits>
using namespace std;

long long fl[100001];

int main(int argc, char** argv) {

    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> fl[i];
    }

    sort(fl, fl + n);

    int start, end;
    start = 0;
    end = n - 1;

    int res = INT_MAX;
    int rs, re;
    while (start < end) {
        if (abs(fl[start] + fl[end]) < res) {
            res = abs(fl[start] + fl[end]);
            rs = start;
            re = end;
        }
        if (fl[start] + fl[end] > 0) {
            end--;
        }
        else if (fl[start] + fl[end] < 0) {
            start++;
        }
        else {
            cout << fl[start] << " " << fl[end];
            return 0;
        }
    }
    cout << fl[rs] << " " << fl[re];

    return 0;
}