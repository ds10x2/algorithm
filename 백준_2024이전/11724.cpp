#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int N, M;
int u, v;
bool visited[1001] = { false, };
vector <int> graph[1001];
queue <int> q;
int cnt = 0;

void bfs(int node) {
	visited[node] = true;
	q.push(node);

	while (!q.empty()) {
		int now = q.front();
		q.pop();

		for (int i = 0; i < graph[now].size(); i++) {
			int next = graph[now][i];
			if (!visited[next]) {
				q.push(next);
				visited[next] = true;
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		cin >> u >> v;

		graph[u].push_back(v);
		graph[v].push_back(u);
	}

	for (int i = 1; i <= N; i++) {
		if (visited[i])
			continue;
		bfs(i);
		cnt++;
	}

	cout << cnt;


	return 0;
}