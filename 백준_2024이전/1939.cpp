#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
using namespace std;

int n, m;
vector<pair<int, int>> v[100001];
bool visited[100001] = { false, };
int island1, island2;
int Max = 0;

bool bfs(int cost) {
	queue<int> q;

	q.push(island1);
	visited[island1] = true;
	
	while (!q.empty()) {
		int x = q.front();

		q.pop();

		if (x == island2) return true;

		for (int i = 0; i < v[x].size(); i++) {
			int y = v[x][i].first;
			int next_cost = v[x][i].second;

			if (!visited[y] && cost <= next_cost) {
				visited[y] = true;
				q.push(y);
			}
		}
	}
	return false;
}


void binary() {
	int low = 0;
	int high = Max;
	while (low <= high) {
		memset(visited, false, sizeof(visited));
		int mid = (low + high) / 2;
		if (bfs(mid))
			low = mid + 1;
		else
			high = mid - 1;
	}

	cout << high;
}


int main() {
	cin.tie(NULL);
	cin.sync_with_stdio(false);

	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		v[a].push_back({ b, c });
		v[b].push_back({ a, c });

		Max = max(Max, c);
	}

	cin >> island1 >> island2;

	binary();



	return 0;
}