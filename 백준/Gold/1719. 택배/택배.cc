/*



*/


#include <iostream>
#include <algorithm>
using namespace std;

int n, m; //집하장의 개수, 집하장 간의 경로 개수
int map[201][201];
int result[201][201];


int main() {

	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int x, y;
		cin >> x >> y;
		cin >> map[x][y];

		map[y][x] = map[x][y];
		result[x][y] = y;
		result[y][x] = x;

	}

	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			if (i == k) continue;
			if (map[i][k] == 0) continue;
			for (int j = 1; j <= n; j++) {

				if (i == j || k == j) continue;

				if (map[k][j] == 0) continue;
				if (map[i][j] == 0 ||
					map[i][j] > map[i][k] + map[k][j]) {

					map[i][j] = map[i][k] + map[k][j];
					result[i][j] = result[i][k];
				}

			}
		}
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (result[i][j] == 0)
				cout << "- ";
			else cout << result[i][j] << " ";
		}
		cout << "\n";
	}

	return 0;
}