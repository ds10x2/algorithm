#include <iostream>
#include <queue>
using namespace std;

#define MAXSIZE 101

queue<pair<int, int>> q;
int maze[MAXSIZE][MAXSIZE];
int visited[MAXSIZE][MAXSIZE];
int N, M;
int dx[] = { 1, -1, 0, 0 };
int dy[] = { 0, 0, 1, -1 };

void bfs() {

	q.push({ 0,0 });
	visited[0][0] = 0;

	int posx, posy;

	while (!q.empty()) {
		posx = q.front().first;
		posy = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = posx + dx[i];
			int ny = posy + dy[i];

			if(nx < 0 || ny < 0 || nx >= M || ny >= N) continue;
			if (maze[nx][ny] == 1) {
				if (visited[nx][ny] > visited[posx][posy] + 1) {
					visited[nx][ny] = visited[posx][posy] + 1;
					q.push({ nx, ny });
				}
			}
			else if (maze[nx][ny] == 0) {
				if (visited[nx][ny] > visited[posx][posy]) {
					visited[nx][ny] = visited[posx][posy];
					q.push({ nx, ny });
				}
			}
		}



	}

}


int main() {
	cin.tie(NULL);
	cin.sync_with_stdio(false);

	cin >> N >> M;

	char c;

	for (int i = 0; i < M; i++) {
		for (int j = 0; j < N; j++) {
			cin >> c;
			maze[i][j] = c - '0';
			visited[i][j] = 100001;
		}
	}

	bfs();

	cout << visited[M-1][N-1];

	return 0;
}