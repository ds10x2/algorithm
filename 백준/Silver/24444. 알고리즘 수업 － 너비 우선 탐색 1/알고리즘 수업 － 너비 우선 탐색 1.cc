#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <queue>
using namespace std;

vector<int> graph[100001];
bool visited[100001];
int result[100001];
int cnt;

int main() {
	cin.tie(NULL);
	cin.sync_with_stdio(false);

	int n, m, r; //정점의 수 n, 간선의 수 m, 시작 정점 r

	cin >> n >> m >> r;

	for (int idx = 0; idx < m; idx++) {
		int u, v;
		cin >> u >> v;
		graph[u].push_back(v);
		graph[v].push_back(u);
	}

	for (int idx = 1; idx <= n; idx++)
		sort(graph[idx].begin(), graph[idx].end());

	//BFS
	queue<int> q;
	q.push(r);
	visited[r] = true;

	cnt = 1;
	result[r] = cnt;
	cnt++;

	while (!q.empty()) {
		int point = q.front();
		q.pop();

		for (int idx = 0; idx < graph[point].size(); idx++) {
			if (visited[graph[point][idx]]) continue;

			q.push(graph[point][idx]);
			visited[graph[point][idx]] = true;

			result[graph[point][idx]] = cnt;
			cnt++;
		}
	}

	for (int idx = 1; idx <= n; idx++)
		cout << result[idx] << "\n";

	return 0;
}