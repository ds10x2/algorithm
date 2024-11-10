#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

#define INF 4444444

int v, e;
int arr[401][401];
int result = INF;

void input() {
	cin >> v >> e;
	for (int i = 1; i < v + 1; i++) {
		for (int j = 1; j < v + 1; j++) {
			arr[i][j] = INF;
		}
	}
	for (int i = 0; i < e; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		arr[a][b] = c;
	}
}

int main() {
	cin.tie(NULL);
	cin.sync_with_stdio(false);

	input();

	for (int k = 1; k < v + 1; k++) {
		for (int i = 1; i < v + 1; i++) {
			for (int j = 1; j < v + 1; j++) {
				if (arr[i][k] + arr[k][j] < arr[i][j]) {
					arr[i][j] = arr[i][k] + arr[k][j];
				}
			}
		}
	}

	for (int i = 1; i < v + 1; i++) {
		for (int j = 1; j < v + 1; j++) {
			if (i == j) continue;
			result = min(result, arr[i][j] + arr[j][i]);
		}
	}

	result = result == INF ? -1 : result;
	cout << result << "\n";
	return 0;


	return 0;

}