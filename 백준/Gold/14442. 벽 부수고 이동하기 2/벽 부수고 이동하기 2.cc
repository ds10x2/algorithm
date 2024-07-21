/*

백준 14442 벽 부수고 이동하기2

벽을 K개까지 부수는 것이 가능할 때 N, M까지 이동하는 데에 걸리는 최단 경로 구하기

<입력>
N, M
맵 

0: 이동할 수 있는 곳
1: 이동할 수 없는 벽

(1, 1)에서 시작해서 (N, M)에 도착

1 <= N, M <= 1000
1 <= K <= 10

*/


#include <iostream>
#include <queue>
using namespace std;

int map[1001][1001];
int row_size, col_size, wall_cnt;
int visited[1001][1001];
int d[4][2] = { {1, 0}, {-1, 0}, {0, 1}, {0, -1} };
int result = -1;

void BFS() {
	queue < pair<pair<int, int>, pair<int, int>>> q; //{좌표} {현재까지 이동거리, 남은 벽}

	q.push({ {1, 1}, {1, wall_cnt} });
	visited[1][1] |= (1 << 10); //부술 수 있는 벽이 10개 남아있을 때 방문함


	while (!q.empty()) {

		int x = q.front().first.first;
		int y = q.front().first.second;

		int cnt = q.front().second.first;
		int wall = q.front().second.second;

		q.pop();

		for (int idx = 0; idx < 4; idx++) {

			int nx = x + d[idx][0];
			int ny = y + d[idx][1];

			if (nx < 1 || nx > row_size || ny < 1 || ny > col_size) continue;

			//도착
			if (nx == row_size && ny == col_size) {
				result = cnt + 1;
				return;
			}
			
			//벽인 경우
			if (map[nx][ny] == 1) {

				if (visited[nx][ny] & (1 << (wall - 1))) continue;
				if (wall == 0) continue;
				q.push({ {nx, ny}, {cnt + 1, wall - 1} });
				visited[nx][ny] |= (1 << (wall - 1));

			}

			//이동할 수 있는 경우
			else if (map[nx][ny] == 0) {
				//이미 가봤던 칸인 경우
				if ((visited[nx][ny] & (1 << wall))) continue;

				//다음 칸으로 이동
				q.push({ {nx, ny}, {cnt + 1, wall} });
				visited[nx][ny] |= (1 << wall);
			}

		}

	}

}

int main() {
	cin.tie(NULL);
	cin.sync_with_stdio(false);

	cin >> row_size >> col_size >> wall_cnt;

	char c;
	for (int row = 1; row <= row_size; row++) {
		for (int col = 1; col <= col_size; col++) {
			cin >> c;
			map[row][col] = c - '0';
		}
	}

	BFS();

	if (row_size == 1 && col_size == 1) result = 1;

	cout << result;

	return 0;
}