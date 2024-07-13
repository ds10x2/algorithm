/*

백준 4179번

# 벽
. 지나갈 수 있는 공간
J 지훈이 초기 위치
F 불이 난 공간

탈출: 가장자리에 접한 공간 (0, x) 혹은 (x 0) 혹은 (n-1, x) (x, n-1)
*/


#include <iostream>
#include <queue>
#include <vector>
using namespace std;

char map[1001][1001];
int row, col;
int j_row, j_col;

queue<pair<int, int>> fire;
pair<int, int > d[4] = { {1, 0}, {-1, 0}, {0, 1}, {0, -1} };
bool visited[1001][1001];
int result = -1;

void print_map() {
	for (int r = 0; r < row; r++) {
		for (int c = 0; c < col; c++)
			cout << map[r][c] << " ";
		cout << "\n";
	}
	cout << endl;
}

void extend_fire() {
	queue<pair<int, int>> new_fire;

	while (!fire.empty()) {
		int x = fire.front().first;
		int y = fire.front().second;

		fire.pop();

		for (int idx = 0; idx < 4; idx++) {
			int next_x = x + d[idx].first;
			int next_y = y + d[idx].second;

			if (next_x < 0 || next_x >= row || next_y < 0 || next_y >= col) continue;
			if (map[next_x][next_y] == '.' || map[next_x][next_y] == 'J') {
				new_fire.push({ next_x, next_y });
				map[next_x][next_y] = 'F';
			}
		}
	}

	fire = new_fire;
}


void BFS() {
	queue<pair<pair<int, int>, int>> q; //위치, 시간
	q.push({ { j_row, j_col }, 0 });
	visited[j_row][j_col] = true;

	int check_point = -1;

	while (!q.empty()) {

		int x = q.front().first.first;
		int y = q.front().first.second;
		int now = q.front().second;
		q.pop();

		if (check_point < now) {
			extend_fire();
			check_point++;
		}

		for (int idx = 0; idx < 4; idx++) {
			int next_x = x + d[idx].first;
			int next_y = y + d[idx].second;

			if (next_x < 0 || next_x >= row || next_y < 0 || next_y >= col) continue;
			if (visited[next_x][next_y]) continue;

			//지나갈 수 없음(벽)
			if (map[next_x][next_y] == '#') continue;
			//지나갈 수 없음(불)
			if (map[next_x][next_y] == 'F') continue;

			//지나갈 수 있는 공간
			if (map[next_x][next_y] == '.') {
				//탈출
				if (next_x == 0 || next_x == row - 1 || next_y == 0 || next_y == col - 1) {
					//cout << next_x << " " << next_y << " " << now + 1 << endl;
					result = now + 1;
					return;
				}
				//cout << next_x << " " << next_y << " " << now + 1 << endl;

				//위치를 옮김
				q.push({ {next_x, next_y}, now + 1 });
				visited[next_x][next_y] = true;
			}
		}

		
	}
}


int main() {
	cin.tie(NULL);
	cin.sync_with_stdio(false);

	// 미로 정보를 입력 받음
	cin >> row >> col;
	for (int r = 0; r < row; r++) {
		for (int c = 0; c < col; c++) {
			cin >> map[r][c];
			
			//지훈이의 초기 위치
			if (map[r][c] == 'J') {
				j_row = r;
				j_col = c;
			}
			//불이 난 공간
			else if (map[r][c] == 'F') {
				fire.push({ r, c });
			}
		}
	}

	if (j_row == 0 || j_row == row - 1 || j_col == 0 || j_col == col - 1) {
		result = 0;
	}
	else
		BFS();

	if (result == -1)
		cout << "IMPOSSIBLE" << endl;
	else
		cout << result + 1 << endl;

	return 0;
}