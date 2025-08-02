#include <iostream>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <queue>
#include <stack>
#include <algorithm>
#include <utility>
using namespace std;

vector<pair<int, int>> graph[10001];
int mark[10001] = { 0, };
priority_queue<pair<int, int>> pq;

int main(int argc, char** argv) {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int V, E;
    cin >> V >> E;
    for (int i = 0; i < E; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        graph[a].push_back({ c,b });
        graph[b].push_back({ c,a });
    }

    pq.push({ 0,1 });

    int sum = 0;
    int cnt = 0;
    while (!pq.empty() && cnt < V) {
        int cost = -pq.top().first;
        int pos = pq.top().second;
        pq.pop();

        if (mark[pos]) continue;
        sum += cost;
        mark[pos] = 1;
        cnt++;

        for (auto i = graph[pos].begin(); i != graph[pos].end(); i++) {
            int ncost = i->first;
            int npos = i->second;

            if (!mark[npos]) {
                pq.push({ -ncost, npos });
            }
        }
    }

    cout << sum;


    return 0;
}