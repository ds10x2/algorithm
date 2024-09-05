#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int n, m;
vector<pair<int, int>> v[1001];
int dist[1001];

void bfs(int n1, int n2) {
	bool visited[1001] = { false, };
	queue<int> q;
	q.push(n1);

	visited[n1] = true;
	dist[n1] = 0;

	while (!q.empty()) {
		int pos = q.front();
		visited[pos] = true;

		q.pop();

		if (pos == n2)
			return;

		for (int i = 0; i < v[pos].size(); i++) {
			int newPos = v[pos][i].first;
			int distance = v[pos][i].second;

			if (visited[newPos])continue;
			if (dist[newPos] >= 0) continue;
			
			dist[newPos] = dist[pos] + distance;
			q.push(newPos);
		}
	}
	return;
	
}

int main() {
	cin.tie(NULL);
	cin.sync_with_stdio(false);

	cin >> n >> m;

	for (int i = 0; i < n-1; i++) {
		int n1, n2, dis;
		cin >> n1 >> n2 >> dis;
		v[n1].push_back({ n2, dis });
		v[n2].push_back({ n1, dis });
	}

	for (int i = 0; i < m; i++) {
		int n1, n2;
		cin >> n1 >> n2;

		for (int i = 0; i < n + 1; i++)
			dist[i] = -1;

		bfs(n1, n2);
		cout << dist[n2] << "\n";


	}

	return 0;
}