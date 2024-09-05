#include <iostream>
#include <queue>
using namespace std;

queue<pair<int, int>> q;
bool visited[1001][1001];
int map[1001][1001];
int dist[1001][1001];

int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };

int n, m;
int x, y;

void bfs() {
	q.push({ x, y });
	visited[x][y] = true;
	dist[x][y] = 0;

	while(!q.empty()) {
		int posX = q.front().first;
		int posY = q.front().second;

		q.pop();

		for (int i = 0; i < 4; i++) {
			int newX = posX + dx[i];
			int newY = posY + dy[i];

			if (visited[newX][newY]) continue;
			if ( newX < 1 || newX > n || newY < 1 || newY > m) continue;

			if (map[newX][newY] == 0) {
				visited[newX][newY] = true;
				continue;
			}

			dist[newX][newY] = dist[posX][posY] + 1;
			visited[newX][newY] = true;
			q.push({ newX, newY });
		}
	}
}

int main() {
	cin.tie(NULL);
	cin.sync_with_stdio(false);

	cin >> n >> m;
	for (int i = 1; i < n + 1; i++) {
		for (int j = 1; j < m + 1; j++) {
			int p;
			cin >> p;
			map[i][j] = p;
			if (p == 2) {
				x = i;
				y = j;
			}
			if(p != 0) dist[i][j] = -1;

		}
	}

	bfs();

	for (int i = 1; i < n + 1; i++) {
		for (int j = 1; j < m + 1; j++) {
			cout << dist[i][j] << " ";
		}
		cout << "\n";
	}


	return 0;
}