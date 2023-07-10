#include <iostream>
using namespace std;

int N, M;
int map[1025][1025] = { 0, };

int main() {
	cin.tie(NULL);
	cin.sync_with_stdio(false);

	cin >> N >> M;
	for (int i = 1; i < N+1; i++) {
		int sum = 0;

		for (int j = 1; j < N + 1; j++) {
			int input;

			cin >> input;

			sum += input;

			map[i][j] = sum;
		}
	}

	for (int i = 0; i < M; i++) {
		int x1, y1, x2, y2;

		cin >> x1 >> y1 >> x2 >> y2;

		int sum = 0;

		for (int j = x1; j <= x2; j++) {
			sum += (map[j][y2] - map[j][y1 - 1]);
		}
		

		cout << sum << "\n";

	}

	return 0;
}