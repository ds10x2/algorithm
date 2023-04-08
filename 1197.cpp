#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int V, E;
int a, b, c;
vector<pair <int, int>> edge[10001];
priority_queue<pair<int, int>, vector<pair <int, int>>, greater<pair <int, int>>>  q;
bool visited[10001] = { false, };

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> V >> E;
	for (int i = 0; i < E; i++) {
		cin >> a >> b >> c;
		edge[a].push_back({ c, b });
		edge[b].push_back({ c, a });
	}

	int sum = 0;
	q.push({ 0,1 });

	while (!q.empty()) {
		int dist = q.top().first;
		int node = q.top().second;

		q.pop();

		if (visited[node])
			continue;
		visited[node] = true;
		sum += dist;

		for (int i = 0; i < edge[node].size(); i++) {
			if (!visited[edge[node][i].second])
				q.push(edge[node][i]);
		}
	}

	cout << sum;
	return 0;
}