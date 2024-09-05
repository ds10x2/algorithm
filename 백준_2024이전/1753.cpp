#include <iostream>
#include <vector>
#include <queue>
#define Inf 3000001
using namespace std;

int V, E, K;
vector <pair <int, int>> graph[20001];
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>pq;
int length[20001];

int main() {

	cin.tie(NULL);
	cin.sync_with_stdio(false);

	cin >> V >> E;
	cin >> K; //시작 번호

	for (int i = 0; i < E; i++) {
		int n1, n2, len;
		cin >> n1 >> n2 >> len;
		graph[n1].push_back({ n2, len });
	}

	for (int i = 0; i <= V; i++) {
		length[i] = Inf;
	}
	length[K] = 0;
	pq.push({ 0, K });

	while (!pq.empty()) {
		int x = pq.top().first;
		int u = pq.top().second;
		pq.pop();

		for (int i = 0; i < graph[u].size(); i++) {
			int v = graph[u][i].first;
			int w = graph[u][i].second;

			if (x + w < length[v]) {
				length[v] = x + w;
				pq.push({ x + w, v });
			}
		}
	}

	for (int i = 1; i <= V; i++) {
		if (length[i] == Inf) cout << "INF\n";
		else cout << length[i] << "\n";
	}

	return 0;
}