#include <iostream>
#include <queue>
#include <vector>
#include <cmath>
using namespace std;

int n, m;
int ladder[101];
int snake[101];
int dice[6] = { 1, 2, 3, 4, 5, 6 };
queue<pair<int, int>> q;
bool visited[101];
int ans = 1000000000;

void Input() {
	cin >> n >> m;

	for (int i = 1; i < n + 1; i++) {
		int x, y;
		cin >> x >> y;
		ladder[x] = y;
	}

	for (int i = 1; i < m + 1; i++) {
		int u, v;
		cin >> u >> v;
		snake[u] = v;
	}
}

void bfs() {
	q.push({ 1, 0 });
	visited[1] = true;

	while (!q.empty()) {
		int p = q.front().first;
		int cnt = q.front().second;

		q.pop();
		if (p == 100) {
			ans = min(cnt, ans);
			continue;
		}

		for (int i = 0; i < 6; i++) {
			int np = p + dice[i];

			if (visited[np] || np > 100) continue;

			visited[np] = true;

			if (ladder[np] != 0)
				np = ladder[np];
			else if (snake[np] != 0)
				np = snake[np];

			q.push({ np, cnt + 1 });

		}
	}
}

int main() {
	cin.tie(NULL);
	cin.sync_with_stdio(false);

	Input();
	bfs();
	cout << ans;

	return 0;
}