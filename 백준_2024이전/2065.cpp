#include <iostream>
#include <queue>
using namespace std;

#define MAX 100000001

int M, t, N;

queue<pair<int, int>> Left;
queue<pair<int, int>> Right;

int result[10001];

void Input() {
	for (int i = 1; i < N + 1; i++) {
		int time;
		string pos;
		cin >> time >> pos;


		if (pos == "left") {
			Left.push({ time, i });
		}
		else if (pos == "right") {
			Right.push({ time, i });
		}
	}
	Left.push({ MAX, -1 });
	Right.push({ MAX, -1 });
}

void boat() {
	int idx = 1; // left

	int people = 0;

	int clock = 0;

	queue<int> q;

	while (!(Left.front().first == MAX && Right.front().first == MAX)) {


		if (idx == 1) { //배가 왼쪽에 있는 경우


			while (Left.front().first != MAX && clock >= Left.front().first) { //왼쪽에 있는 사람들만큼 더함
				q.push(Left.front().second);
				Left.pop();
				if (q.size() == M)
					break;
			}

			if (q.empty()) {
				if (Left.front().first <= Right.front().first) {
					if (Left.front().first >= clock)
						clock = Left.front().first;

				}
				else {
					idx = 2;
					if (clock > Right.front().first)
						clock += t;
					else
						clock = Right.front().first + t;

				}
			}

		}
		else if (idx == 2) {


			while (Right.front().first != MAX && clock >= Right.front().first) {
				q.push(Right.front().second);
				Right.pop();
				if (q.size() == M)
					break;
			}

			if (q.empty()) {
				if (Left.front().first >= Right.front().first) {
					if (Right.front().first >= clock)
						clock = Right.front().first;
				}
				else {
					idx = 1;

					if (clock > Left.front().first)
						clock += t;
					else
						clock = Left.front().first + t;
				}
			}

		}

		if (!q.empty()) { //배에 탑승한 사람이 1명 이상일 경우 시간 출력
			
			if (idx == 1) idx = 2; //배 이동
			else idx = 1;

			clock += t;
			
			while (!q.empty()) {
				int x = q.front();
				result[x] = clock;
				q.pop();
			}
		}


	}
}

void Print() {
	for (int i = 1; i < N + 1; i++) {
		cout << result[i] << "\n";
	}
}

int main() {
	cin.tie(NULL);
	cin.sync_with_stdio(false);

	cin >> M >> t >> N;

	Input();
	boat();
	Print();

	return 0;
}