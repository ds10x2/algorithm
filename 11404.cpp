#include <iostream>
#include <vector>
#define INF 362880000000
using namespace std;

int n, m; //n개의 정점, m개의 간선
vector <pair <int, int>> graph[101];
long long cost[101][101]; //비용은 100000보다 작거나 같은 자연수

int main() {

	cin.tie(NULL);
	cin.sync_with_stdio(false);

	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int st, en, co;
		cin >> st >> en >> co;
		graph[st].push_back({ en, co });
	}

	for (int i = 0; i < 101; i++) {
		for (int j = 0; j < 101; j++)
			cost[i][j] = INF;
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			for (int k = 0; k < graph[i].size(); k++) {
				if (j == graph[i][k].first) {
					if (graph[i][k].second < cost[i][j])
						cost[i][j] = graph[i][k].second;
				}
			}
			if (i == j)
				cost[i][j] = 0;
		}
	}


	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				cost[i][j] = min(cost[i][j], cost[i][k] + cost[k][j]);
			}
		}
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (cost[i][j] == INF)
				cout << 0 << " ";
			else cout << cost[i][j] << " ";
		}
		cout << "\n";
	}

	return 0;
}