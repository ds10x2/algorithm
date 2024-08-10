/*

백준 2665

n*n 사이즈의 방이 있음
흰 방으로 이동 가능
검은 방은 이동이 불가능하나 흰 방으로 바꾸어서 이동 가능
(0,0), (n-1, n-1)은 각각 시작, 끝 방으로 항상 흰 방

시작->끝으로 이동하려할 때 흰 방으로 바꾸어야 할 최소의 검은 방 수 출력

visited 배열에 지금까지 바꾼 검은 방의 수를 저장 같거나 큰 경우에는 더 이상 이동하지 않음

*/


#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

char map[51][51];
int map_size;
int visited_cnt[51][51];
bool visited[51][51];
int result = 2500;

int d[4][2] = { {1, 0}, {-1, 0}, {0, 1}, {0, -1} };

void BFS() {
	queue<pair<pair<int, int>, int>> q; // {{row, col}, 바꾼 방의 수}
	
	//시작 방
	q.push({ {0, 0}, 0 });
	visited[0][0] = true;
	
	while (!q.empty()) {

		
		int x = q.front().first.first;
		int y = q.front().first.second;
		int cnt = q.front().second;

		q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = x + d[i][0];
			int ny = y + d[i][1];
			int n_cnt = cnt;

			//방 범위를 넘어가면 continue
			if (nx < 0 || nx >= map_size || ny < 0 || ny >= map_size) continue;

			if (nx == map_size - 1 && ny == map_size - 1) {
				result = min(result, n_cnt);
				continue;
			}


			// 방문을 했는데 기존 방문 당시 cnt 수가 현재보다 큰 경우면 이동
			if (visited[nx][ny]) {


				//검은 방
				if (map[nx][ny] == '0') {
					if (visited_cnt[nx][ny] > n_cnt + 1) n_cnt++;
					else continue;
				}
				else if (map[nx][ny] == '1')
					if (visited_cnt[nx][ny]<= n_cnt) continue;

			}
			// 방문을 안 했을 경우
			else if (!visited[nx][ny]) {
				//검은 방
				if (map[nx][ny] == '0') n_cnt++;
			}
			else continue;

			//다음 방 방문
			q.push({ { nx, ny }, n_cnt });
			visited[nx][ny] = true;
			visited_cnt[nx][ny] = n_cnt;
		}
	}
}

int main() {
	
	cin >> map_size;
	for (int row = 0; row < map_size; row++) {
		for (int col = 0; col < map_size; col++) {
			cin >> map[row][col];
		}
	}

	BFS();

	cout << result << endl;

	return 0;
}