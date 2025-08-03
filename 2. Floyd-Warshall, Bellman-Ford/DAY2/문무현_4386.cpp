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

int n;
pair<double,double> star[101]; // idx = 별, 값 = x, y 좌표
bool visited[101] = { false, };
double min_edge[101] = { 0, };
priority_queue<pair<double, int>> pq; // 가중치, 점

int main(int argc, char** argv) {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    cin >> n;
    for (int i = 0; i < n; i++) {
        double x, y;
        cin >> x >> y;
        star[i] = { x,y };
        min_edge[i] = INT_MAX;
    }

    int cnt = 0;
    double sum = 0;
    min_edge[0] = 0;
    visited[0] = 0;
    pq.push({ -0.0, 0 });

    while (!pq.empty() && cnt < n) {
        double cost = -pq.top().first;
        int pos = pq.top().second;
        pq.pop();

        if (visited[pos] || cost > min_edge[pos]) continue;
        visited[pos] = 1;
        cnt++;
        sum += cost;

        for (int i = 0; i < n; i++) {
            if (i == pos) continue;
            double xdif = star[pos].first - star[i].first;
            double ydif = star[pos].second - star[i].second;
            double ncost = sqrt((xdif * xdif) + (ydif * ydif));
            int npos = i;

            if (!visited[npos] && ncost < min_edge[npos]) {
                pq.push({ -ncost, npos });
                min_edge[npos] = ncost;
            }
        }

    }

    //cout << "visited : ";
    //for (int i = 0; i < n; i++) {
    //    cout << visited[i] << " ";
    //}
    //cout << "\nedge : ";
    //for (int i = 0; i < n; i++) {
    //    cout << min_edge[i] << " ";
    //}
    //cout << "\n";
    cout.precision(2);
    cout << fixed << sum;
    

    return 0;
}