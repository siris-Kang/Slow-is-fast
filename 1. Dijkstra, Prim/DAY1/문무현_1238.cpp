#include <iostream>
#include <algorithm>
#include <queue>
#include <climits>
using namespace std;

const int INF = INT_MAX;

vector<pair<int, int>> graph[10001];

int dist[1001] = {0, };
int distX[1001] = {0, }; 

vector<int> ans;

int main(void) {
    int N, M, X;
    scanf("%d %d %d", &N, &M, &X);
    int a, b, d;
    ans.push_back(0);

    for (int i = 0; i < M; i++) {
        scanf("%d %d %d", &a, &b, &d);
        graph[a].push_back(make_pair(b, d));
    }

    for (int n = 1; n <= N; n++) {
        for (int i = 1; i <= N; i++) {
            dist[i] = INF;
        }

        dist[n] = 0;

        priority_queue<pair<int, int>> pq;
        pq.push(make_pair(0, n));

        while (!pq.empty()) {
            auto cur = pq.top();
            int curdist = -cur.first;
            int curnode = cur.second;
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

        ans.push_back(dist[X]);
    }


    for (int i = 1; i <= N; i++) {
        distX[i] = INF;
    }
    distX[X] = 0;

    priority_queue<pair<int, int>> pqX;
    pqX.push(make_pair(0, X));

    while (!pqX.empty()) {
        auto cur = pqX.top();
        int curdist = -cur.first;
        int curnode = cur.second;
        pqX.pop();

        for (int i = 0; i < graph[curnode].size(); i++) {
            int nnode = graph[curnode][i].first;
            int ndist = curdist + graph[curnode][i].second;
            if (ndist < distX[nnode]) {
                distX[nnode] = ndist;
                pqX.push(make_pair(-ndist, nnode));
            }
        }
    }

    /*for (int i = 1; i < ans.size(); i++)
    {
        printf("%d ", ans[i]);
    }
    printf("\n");
    for (int i = 1; i <= N; i++)
    {
        printf("%d ", distX[i]);
    }*/

    int max = 0;
    for (int i = 1; i <= N; i++) {
        if (ans[i] + distX[i] > max) max = ans[i] + distX[i];
    }
    
    printf("%d\n", max);

    return 0;
}
