#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

struct val {
	int weight, node;
	bool operator> (const val& other) const {
		return weight > other.weight;
	}
};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int V, E, K;
	cin >> V >> E >> K;
	int u, v, w;
	vector<vector<val>> graph(V + 1);
	for (int i = 0; i < E; i++) {
		cin >> u >> v >> w;
		graph[u].push_back({ w, v });
	}

	priority_queue<val, vector<val>, greater<>> pque;
	vector<int> dist(V + 1, INT_MAX);
	pque.push({ 0, K });
	dist[K] = 0;

	while (!pque.empty()) {
		val now = pque.top();
		pque.pop();

		if (now.weight > dist[now.node]) {
			continue;
		}

		for (auto next : graph[now.node]) {
			if (dist[next.node] > dist[now.node] + next.weight) {
				dist[next.node] = dist[now.node] + next.weight;
				pque.push({ dist[next.node], next.node });
			}
		}
	}

	for (int i = 1; i <= V; i++) {
		if (dist[i] != INT_MAX)
			cout << dist[i] << "\n";
		else
			cout << "INF\n";
	}

	return 0;
}