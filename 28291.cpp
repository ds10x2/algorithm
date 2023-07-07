#include <iostream>
#include <string>
#include <vector>
#include <queue>
using namespace std;

int W, H;
int N; //회로 블록 수
int block[51][51];
vector<pair<int, int>> lamp;

int xd[4] = { 1, -1, 0, 0 };
int yd[4] = { 0, 0, 1, -1 };

bool visited[51][51] = { false, };

queue<pair<pair<int, int>, int>> q;

bool find(int a, int b) {

	q.push({ {a, b}, 15 });

	while (!q.empty()) {
		int x = q.front().first.first;
		int y = q.front().first.second;
		int cnt = q.front().second;

		q.pop();

		if (cnt == 0)
			continue;


		for (int j = 0; j < 4; j++) {
			int posX = x + xd[j];
			int posY = y + yd[j];

			if (posX < 0 || posX > W - 1 || posY < 0 || posY > H - 1) continue;
			if (visited[posX][posY]) continue;

			if (block[posX][posY] == 2)
				return true;
			else if (block[posX][posY] == 1) {
				visited[posX][posY] = true;
				q.push({{ posX, posY }, cnt - 1});
			}

		}
	}

	return false;


	
}

int main() {
	cin.tie(NULL);
	cin.sync_with_stdio(false);

	cin >> W >> H;
	cin >> N;

	for (int i = 0; i < N; i++) {
		string t;
		int x, y;
		cin >> t >> x >> y;

		if (t == "redstone_dust")
			block[x][y] = 1;
		else if (t == "redstone_block") {
			block[x][y] = 2;
		}
		else if (t == "redstone_lamp") {
			block[x][y] = 3;
			lamp.push_back({ x,y });
		}
	}


	for (int i = 0; i < lamp.size(); i++) {


		int x = lamp[i].first;
		int y = lamp[i].second;

		bool result = find(x, y);

		if (result == false) {
			cout << "failed";
			return 0;
		}
		
		for (int j = 0; j < W; j++) {
			for (int k = 0; k < H; k++) {
				visited[j][k] = false;
			}
		}
	}

	cout << "success";

	return 0;
}
