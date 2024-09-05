#include <iostream>
#include <cmath>
using namespace std;

#define INF 100000;

int N;
int dis[101][101];


void floydWarshall() {

	for (int k = 0; k < N; k++) { //거쳐가는 노드
		for (int i = 0; i < N; i++) { //출발 노드
			for (int j = 0; j < N; j++) { //도착 노드
				dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
			}
		}
	}

}

int main() {
	cin.tie(NULL);
	cin.sync_with_stdio(false);

	cin >> N;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			int x;
			cin >> x;

			if (x == 1) dis[i][j] = 1;
			else if (x == 0) dis[i][j] = INF;

		}
	}

	floydWarshall();

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (dis[i][j] >= 100000) cout << 0 << " ";
			else cout << 1 << " ";
		}
		cout << "\n";
	}



	return 0;
}