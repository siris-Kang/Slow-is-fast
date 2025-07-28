#include <iostream>
#include <algorithm>
#include <queue>
#include <climits>
using namespace std;

const int INF = INT_MAX;

vector<pair<int, int>> graph[300001];

int dist[20001] = { 0, };

int main(void) {
    int N, M;
    scanf("%d %d", &N, &M);
    int a, b, d;

    int start;
    scanf("%d", &start);

    for (int i = 0; i < M; i++) {
        scanf("%d %d %d", &a, &b, &d);
        graph[a].push_back(make_pair(b, d));
    }

    for (int i = 1; i <= N; i++) {
        dist[i] = INF;
    }

    dist[start] = 0;

    priority_queue<pair<int, int>> pq;
    pq.push(make_pair(0, start));

    while (!pq.empty()) {
        auto cur = pq.top();
        int curdist = -cur.first;
        int curnode = cur.second;
        if(curdist > dist[curnode]) continue;
        pq.pop();

        for (int i = 0; i < graph[curnode].size(); i++) {
            int nnode = graph[curnode][i].first;
            int ndist = curdist + graph[curnode][i].second;
            if (ndist < dist[nnode]) {
                dist[nnode] = ndist;
                pq.push(make_pair(-ndist, nnode));
            }
        }

    }

    for (int i = 1; i <= N; i++) {
        if (dist[i] == INF) printf("INF\n");
        else printf("%d\n", dist[i]);
    }

    return 0;
}
