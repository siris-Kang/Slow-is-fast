#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

int map[101][101] = {0, };
vector<pair<int, pair<int, int>>> graph[101][101];
int N, M;
int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };
int dist[101][101];
priority_queue<pair<int,pair<int, int>>> pq; // dist, y, x

int checkbound(int y, int x) {
	if (y < 0 || x < 0 || y > N || x > M) return 0;
	return 1;
}

int main(int argc, char** argv) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> M >> N;
	// cin으로 개행 문자를 읽고 버퍼를 비워주기 위해 추가
	string dummy;
	getline(cin, dummy);

	for (int i = 1; i <= N; i++) {
		string row;
		cin >> row;
		for (int j = 1; j <= M; j++) {
			map[i][j] = row[j - 1] - '0';
		}
	}

	//for (int i = 1; i <= N; i++) {
	//	for (int j = 1; j <= M; j++) {
	//		cout << map[i][j];
	//	}
	//	cout << "\n";
	//}

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			dist[i][j] = INT_MAX;
			for (int k = 0; k < 4; k++) {
				if (checkbound(i + dy[k], j + dx[k])) {
					graph[i][j].push_back({ map[i + dy[k]][j + dx[k]],{ i + dy[k], j + dx[k] } });
				}
			}
		}
	}

	dist[1][1] = 0;
	pq.push({ 0,{ 1,1 } });
	while (!pq.empty()) {
		auto t = pq.top();
		int cost = -t.first;
		int cury = t.second.first;
		int curx = t.second.second;
		//cout << "ncost: " << cost << "\n";
		pq.pop();
		if (cost > dist[cury][curx]) continue;

		for (auto i = graph[cury][curx].begin(); i != graph[cury][curx].end(); i++) {
			int ncost = i->first + cost;
			int ny = i->second.first;
			int nx = i->second.second;

			if (ncost < dist[ny][nx]) {
				dist[ny][nx] = ncost;
				pq.push({ -ncost,{ny,nx} });
			}
		}
	}

	//for (int i = 1; i <= N; i++) {
	//	for (int j = 1; j <= M; j++) {
	//		cout << dist[i][j] << " ";
	//	}
	//	cout << "\n";
	//}

	cout << dist[N][M];

	return 0;
}