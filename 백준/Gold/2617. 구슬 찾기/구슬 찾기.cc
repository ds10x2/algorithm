#include <iostream>
#include <algorithm>
using namespace std;

/*
2617 구슬 찾기
*/

int n, m;
bool arr[100][100];

int main() {

	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int x, y;
		cin >> x >> y;
		arr[x][y] = true;
	}

	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			if (!arr[i][k]) continue;
			for (int j = 1; j <= n; j++) {

				if (!arr[k][j]) continue;
				if (i == j) continue;

				arr[i][j] = true;

			}
		}
	}

	int result = 0;

	for (int i = 1; i <= n; i++) {
		int check1 = 0;
		int check2 = 0;
		for (int j = 1; j <= n; j++) {
			if (arr[i][j]) check1++; //자신보다 무거운 것 세기
			if (arr[j][i]) check2++; //자신보다 가벼운 것 세기
		}

		if (check1 >= (n / 2 + 1) || check2 >= (n / 2 + 1))
			result++;
	}

	cout << result << "\n";

	return 0;
}