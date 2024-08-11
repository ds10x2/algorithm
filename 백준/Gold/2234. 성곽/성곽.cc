/*

백준 2234 성곽


남동북서
1 1 1 1 

11이면 남(8) 북(3) 서(1)

칸에 방문 -> 이동할 수 있는 칸을 확인 ( & (1 << n) 으로 체크)

1. 이 성에 있는 방의 개수
2. 가장 넓은 방의 넓이
3. 하나의 벽을 제거하여 얻을 수 있는 가장 넓은 방의 크기

*/


#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

int row_size, col_size;
bool visited[51][51];
int map_idx[51][51];
int map[51][51];
int room_size[2501];

int cnt;
int max_room_size;
int max_two_room_size;

int tmp;
int tmp_size;

//서 북 동 남
int d[4][2] = { {0, -1}, {-1, 0}, {0, 1}, {1, 0} };


void BFS(int x, int y, int idx) {

	queue<pair<int, int>> q;
	q.push({ x, y });
	visited[x][y] = true;

	while (!q.empty()) {

		int x = q.front().first;
		int y = q.front().second;

		q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = x + d[i][0];
			int ny = y + d[i][1];

			//지도 범위 벗어나면 넘어감
			if (nx < 0 || nx >= row_size || ny < 0 || ny >= col_size) continue;
			//방문한 적이 있으면 넘어감

			//벽 체크
			//벽이 있음
			if (map[x][y] & (1 << i)) {
				//벽 넘어 방이 넓이 체크가 끝난 방이면
				if (map_idx[nx][ny] != 0) { 

					tmp = max(tmp, room_size[map_idx[nx][ny]]);
				
				}
			}
			//벽이 없음
			else {
				if (visited[nx][ny]) continue;

				map_idx[nx][ny] = idx;
				visited[nx][ny] = true;

				tmp_size++;
				q.push({ nx, ny });

			}
		}

	}


}


int main() {
	

	// 성곽의 사이즈를 입력받고 
	cin >> col_size >> row_size;
	for (int row = 0; row < row_size; row++) {
		for (int col = 0; col < col_size; col++) {
			cin >> map[row][col];
		}
	}


	for (int row = 0; row < row_size; row++) {
		for (int col = 0; col < col_size; col++) {
			
			//이미 인덱스가 찍혀있는 칸은 탐색하지 않음
			if (map_idx[row][col] != 0) continue;

			cnt++;
			tmp_size = 1;
			tmp = 0;
			
			map_idx[row][col] = cnt;
			BFS(row, col, cnt);
			room_size[cnt] = tmp_size;

			max_room_size = max(max_room_size, tmp_size);
			max_two_room_size = max(max_two_room_size, tmp_size + tmp);
		}
	}

	cout << cnt << "\n" << max_room_size << "\n" << max_two_room_size << "\n";

	return 0;
}