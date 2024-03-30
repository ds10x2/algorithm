#include <iostream>
#include <queue>
using namespace std;

/*

백준 5558번 チーズ 치즈

지도에는 치즈 공장, 장애물, 비어있는 곳이 있음
쥐는 소굴에서 출발하고 모든 치즈 공장을 돌면서 치즈를 1개씩 먹음
이 마을에는 N개의 치즈 공장이 있고 모든 치즈 공장은 치즈를 1개씩만 생산하고 있음
1부터 N까지의 강도를 가진 치즈(각 공장에서 생산하는 강도는 한 종류임)

쥐의 초기 체력은 1, 치즈를 먹으면 1씩 늘어남
자신의 체력보다 단단한 치즈는 먹을 수 없음
동서남북으로 한칸씩 이동 가능, 장애물 이동 불가, 치즈를 먹지 않고 치즈 공장을 방문할 수 있음

모든 치즈를 먹는 최소 이동 거리를 구하기


<입력>
지도의 높이, 너비, 공장의 개수 (H, W, N) (1<= H, W <= 1000, 1<= N <= 9)
지도의 정보(S: 쥐의 출발점, X: 장애물, .: 비어있는 공간, 1~9: 치즈 공장)

쥐는 자신의 체력보다 단단한 치즈는 먹을 수 없음 -> 1번부터 N번까지의 치즈를 순서대로 먹어야함
-> 다음번호까지의 최단 거리를 구해야함
방문처리: 체력이 같을 때 여러번 방문하지 않게 함

*/

int row_size, col_size; //지도의 크기
char map[1001][1001]; //지도
int factory_cnt; //공장의 개수
int visited[1001][1001]; //방문처리 배열
char input; //입력으로 받을 지도 정보

int start_row, start_col; //쥐의 출발점
pair<int, int> factory_list[11]; //각 공장의 위치


int stamina; //쥐의 체력

int d[4][2] = { {-1, 0}, {1, 0}, {0, -1}, {0, 1} }; //상하좌우 이동에 사용


//BFS를 이용한 치즈 찾기
int eat_cheese(int st, int ed, int row, int col) {
	queue<pair<pair<int, int>, int>> move_queue; //BFS 탐색에 사용 row, col, cnt
	move_queue.push({ {st, ed}, 0 });
	visited[st][ed] = stamina;

	while (!move_queue.empty()) {

		int curr_row = move_queue.front().first.first;
		int curr_col = move_queue.front().first.second;
		int curr_cnt = move_queue.front().second;

		move_queue.pop();

		for (int d_idx = 0; d_idx < 4; d_idx++) {
			int next_row = curr_row + d[d_idx][0];
			int next_col = curr_col + d[d_idx][1];

			//지도 범위를 넘어가면 continue
			if (next_row < 1 || next_row > row_size || next_col < 1 || next_col > col_size) continue;
			//현재 체력과 같은 체력일 때 방문한 적 있는 칸이면 continue
			if (visited[next_row][next_col] == stamina) continue;
			//장애물이 있는 칸이면 이동 불가
			if (map[next_row][next_col] == 'X') continue;

			//공장에 도착하면 return
			if (next_row == row && next_col == col) {
				stamina++;
				return curr_cnt + 1;
			}

			//다음 지점 방문
			move_queue.push({ {next_row, next_col}, curr_cnt + 1 });
			visited[next_row][next_col] = stamina;
		}

	}

}

int main() {
	cin.tie(NULL);
	cin.sync_with_stdio(false);

	//지도의 크기, 공장의 개수 입력 받기
	cin >> row_size >> col_size >> factory_cnt;

	//지도의 정보 입력 받기
	for (int row_idx = 1; row_idx <= row_size; row_idx++) {
		for (int col_idx = 1; col_idx <= col_size; col_idx++) {
			cin >> map[row_idx][col_idx];

			//입력받은 곳이 치즈 공장일 경우
			if (map[row_idx][col_idx] - '0' >= 1 && map[row_idx][col_idx] - '0' <= 9) {
				factory_list[map[row_idx][col_idx] - '0'] = { row_idx, col_idx };
			}
			//입력 받은 곳이 쥐의 출발점일 경우
			else if (map[row_idx][col_idx] == 'S') {
				factory_list[0] = { row_idx, col_idx };
			}
		}
	}


	int result = 0;
	stamina = 1;
	for (int idx = 1; idx <= factory_cnt; idx++) {
		result += eat_cheese(factory_list[idx - 1].first, factory_list[idx - 1].second
								,factory_list[idx].first, factory_list[idx].second);
	}
	cout << result << "\n";

	return 0;
}