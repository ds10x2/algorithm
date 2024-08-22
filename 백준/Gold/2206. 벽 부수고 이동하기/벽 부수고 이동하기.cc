#include <iostream>
#include <queue>
using namespace std;

int N, M;
int dx[] = { 1, -1, 0, 0 };
int dy[] = { 0, 0, 1, -1 };

int visited[1001][1001][2];
int graph[1001][1001];

queue<pair<pair<int, int>, bool>> q;


void BFS() {
	visited[1][1][0] = 1;
	visited[1][1][1] = 1;
	
	q.push({ {1, 1},false });

	while (!q.empty()) {
		int x = q.front().first.first;
		int y = q.front().first.second;

		bool broken = q.front().second;

		q.pop();

		for (int i = 0; i < 4; i++) {
			int next_x = x + dx[i];
			int next_y = y + dy[i];

			if (next_x < 1 || next_x > N || next_y < 1 || next_y > M) continue;
			if (broken && graph[next_x][next_y] == 1) continue;

			if (broken) {
				if (visited[next_x][next_y][1] > visited[x][y][1] + 1) {
					visited[next_x][next_y][1] = visited[x][y][1] + 1;
					q.push({ {next_x, next_y}, true });
				}
			}
			else {
				if (graph[next_x][next_y] == 0 && visited[next_x][next_y][0] > visited[x][y][0] + 1) {
					visited[next_x][next_y][0] = visited[x][y][0] + 1;
					q.push({{ next_x, next_y }, false});
				}
				else if (graph[next_x][next_y] == 1 && visited[next_x][next_y][1] > visited[x][y][0] + 1) {
					visited[next_x][next_y][1] = visited[x][y][0] + 1;
					q.push({ {next_x, next_y}, true });
				}
			}


		}
	}
	
}


int main() {
	cin.tie(NULL);
	cin.sync_with_stdio(false);

	cin >> N >> M;

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			char c;
			cin >> c;
			graph[i][j] = c - '0';
			visited[i][j][0] = 1000001;
			visited[i][j][1] = 1000001;
		}
	}



	BFS();


	if (visited[N][M][1] == 1000001 && visited[N][M][0] == 1000001)
		cout << -1;
	else 
		cout << min(visited[N][M][0], visited[N][M][1]);

	return 0;
}