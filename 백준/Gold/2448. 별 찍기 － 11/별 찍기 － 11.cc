#include <iostream>
#include <algorithm>
using namespace std;

char map[3072][6144];

void star(int x, int y, int n) {
	if (n == 3) {
		map[x][y] = '*';
		map[x + 1][y - 1] = '*';
		map[x + 1][y + 1] = '*';
		for (int j = y - 2; j <= y + 2; j++)
			map[x + 2][j] = '*';
		return;
	}

	star(x, y, n / 2);
	star(x + n / 2, y - n / 2, n / 2);
	star(x + n / 2, y + n / 2, n / 2);
}

int main() {
	cin.tie(NULL);
	cin.sync_with_stdio(false);

	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 2 * n; j++)
			map[i][j] = ' ';
	}

	star(0, n - 1, n);

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 2 * n - 1; j++)
			cout << map[i][j];
		cout << "\n";
	}

	return 0;
}