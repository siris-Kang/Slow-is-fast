#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <vector>
#include <queue>
using namespace std;

priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;

int main(void) {
    int N;
    cin >> N;
    for (int i = 0; i < N; i++) {
        int x;
        cin >> x;
        if (x == 0) {
            if (pq.empty()) cout << "0\n";
            else if (pq.top().second < 0) {
                cout << -pq.top().first << "\n";
                pq.pop();
            }
            else {
                cout << pq.top().first << "\n";
                pq.pop();
            }
        }
        else {
            if (x < 0) {
                pq.push({ -x, -1 });
            }
            else {
                pq.push({ x, 1 });
            }
        }
    }

    return 0;
}