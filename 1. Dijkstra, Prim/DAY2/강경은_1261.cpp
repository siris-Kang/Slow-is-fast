#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <climits>

using namespace std;

int N, M;
int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };
vector<string> map;

struct node {
    int cost, x, y;
    bool operator>(const node& other) const {
        return cost > other.cost;
    }
};

int dijkstra() {
    vector<vector<int>> dist(N, vector<int>(M, INT_MAX));
    priority_queue<node, vector<node>, greater<>> pq;

    dist[0][0] = 0;
    pq.push({ 0, 0, 0 });

    while (!pq.empty()) {
        node now = pq.top();
        pq.pop();

        if (now.x == N - 1 && now.y == M - 1)
            return now.cost;

        for (int d = 0; d < 4; d++) {
            int nx = now.x + dx[d];
            int ny = now.y + dy[d];

            if (nx >= 0 && nx < N && ny >= 0 && ny < M) {
                int nextCost = now.cost + (map[nx][ny] - '0');
                if (dist[nx][ny] > nextCost) {
                    dist[nx][ny] = nextCost;
                    pq.push({ nextCost, nx, ny });
                }
            }
        }
    }
    return -1;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> M >> N;
    map.resize(N);
    for (int i = 0; i < N; i++) {
        cin >> map[i];
    }

    cout << dijkstra() << "\n";
    return 0;
}
