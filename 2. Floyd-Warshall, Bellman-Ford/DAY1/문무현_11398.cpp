#include <iostream>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <queue>
#include <stack>
#include <algorithm>
#include <utility>
using namespace std;

int graph[1001][1001];
int visited[1001] = { 0, };
priority_queue<pair<int, int>> pq;

int main(int argc, char** argv) {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int N;
    cin >> N;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            int input;
            cin >> input;
            graph[i][j] = input;
        }
    }

    pq.push({ 0,0 });
    int cnt = 0;
    long long sum = 0;

    while (!pq.empty() && cnt < N) {
        int cost = -pq.top().first;
        int pos = pq.top().second;
        pq.pop();

        if(visited[pos]) continue;
        cnt++;
        sum += cost;
        visited[pos] = 1;

        for (int i = 0; i < N; i++) {
            int ncost = graph[pos][i];
            int npos = i;
            if (ncost && !visited[npos]) {
                pq.push({ -ncost, npos });
            }
        }
    }

    cout << sum;

    return 0;
}