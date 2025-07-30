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

int N, M, K;
int a, b, c;

vector<pair<int, int>> graph[10001];
long long dist[10001][21];
priority_queue<pair<long long, pair<int, int>>> pq;

int main(int argc, char** argv) {

    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    cin >> N >> M >> K;
    for (int i = 0; i < M; i++) {
        cin >> a >> b >> c;
        graph[a].push_back({ c,b });
        graph[b].push_back({ c,a });
    }

    for (int i = 0; i <= N; i++) {
        for(int j=0; j<=K; j++) dist[i][j] = LLONG_MAX;
    }

    dist[1][0] = 0;
    pq.push({ 0, { 0,1 } }); // cost, K, node

    while (!pq.empty()) {
        long long cost = -pq.top().first;
        int k_used = pq.top().second.first;
        int pos = pq.top().second.second;
        pq.pop();
        if (cost > dist[pos][k_used]) continue;

        for (auto i = graph[pos].begin(); i != graph[pos].end(); i++) {
            long long ncost = i->first + cost;
            int npos = i->second;

            if (ncost < dist[npos][k_used]) {
                dist[npos][k_used] = ncost;
                pq.push({ -ncost, {k_used, npos } });
            }

            if (k_used < K && cost < dist[npos][k_used + 1]) {
                dist[npos][k_used + 1] = cost;
                pq.push({ -cost, {k_used + 1, npos } });
            }
        }
    }

    /*
        N으로 가는 모든 경로와 그 값을 구한다.
        해당 경로들을 정렬한 후 큰 순서대로 K개 만큼의 비용을 제거한다.
        제거하고 남은 경로들 중 최소값이 정답.
        -> 시간 복잡도가 너무 커서 안된다..

        2차원 배열로 만들어서 도로 지우기 횟수를 소모하는 최단 경로 배열을 만든다.
        -> 제미니 컨닝
    */

    //for (int i = 1; i <= N; i++) {
    //    for (int j = 0; j <= K; j++) {
    //        cout << dist[i][j] << " ";
    //    }
    //    cout << "\n";
    //}

    long long res = LLONG_MAX;
    for (int i = 0; i <= K; i++) {
        if (dist[N][i] < res) res = dist[N][i];
    }
    cout << res;

    return 0;
}