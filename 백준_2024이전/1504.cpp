#include <iostream>
#include <vector>
#include <queue>
#define INF 2147483647
using namespace std;

int n, m; //n개의 정점, m개의 간선
int a, b, c;
int u, v;
vector <pair <int, int>> graph[801];
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>pq;
int length[801];

void di(int x) {
	for (int i = 0; i <= n; i++) {
		length[i] = INF;
	}
	length[x] = 0;
	pq.push({ 0, x });

	while(!pq.empty()) {
		int dist = pq.top().first;
		int point = pq.top().second;
		pq.pop();

		for (int i = 0; i < graph[point].size(); i++) {
			int k = graph[point][i].first;
			int w = graph[point][i].second;

			if (dist + w < length[k]) {
				length[k] = dist + w;
				pq.push({ dist + w, k });
			}
		}
	}

}


int main() {

	cin.tie(NULL);
	cin.sync_with_stdio(false);

	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		cin >> a >> b >> c;
		graph[a].push_back({ b, c });
		graph[b].push_back({ a, c });
	}

	cin >> u >> v;

	di(u);
	int ONEtoU = length[1];
	int UtoV = length[v];
	int UtoN = length[n];

	di(v);
	int ONEtoV = length[1];
	int VtoN = length[n];

	int sum1, sum2;

	if (ONEtoU != INF && UtoV != INF && VtoN != INF)
		sum1 = ONEtoU + UtoV + VtoN;
	else
		sum1 = INF;

	if (ONEtoV != INF && UtoV != INF && UtoN != INF)
		sum2 = ONEtoV + UtoV + UtoN;
	else
		sum2 = INF;


	if (sum1 == INF && sum2 == INF) cout << -1;
	else if (sum1 < sum2) cout << sum1;
	else cout << sum2;


	return 0;

}