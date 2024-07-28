/*

백준 17182 우주탐사선


탐사 후 다시 시작 행성으로 돌아올 필요는 없으며 이미 방문한 행성도 중복해서 갈 수 있다.
-> 플로이드 워샬을 통해 최소거리를 구하는 과정에서 중복이 발생할 수 있음

최소거리를 구했으므로 이후부턴 중복되지 않게 최단거리를 구함


*/


#include <iostream>
#include <algorithm>
using namespace std;

int arr[11][11];
int space_cnt;
int start; //발사되는 행성 번호
int result = 100000;


void DFS(int s, int d, int visited, int cnt) {

	if (d >= result) return;

	if (cnt == space_cnt) {
		result = min(result, d);
		return;
	}

	for (int idx = 0; idx < space_cnt; idx++) {
		if (visited & (1 << idx)) continue;

		int temp = visited;

		visited |= (1 << idx);
		DFS(idx, d + arr[s][idx], visited, cnt + 1);	
		visited = temp;
	}
}


int main() {
	cin.tie(NULL);
	cin.sync_with_stdio(false);

	cin >> space_cnt >> start;

	for (int row_idx = 0; row_idx < space_cnt; row_idx++) {
		for (int col_idx = 0; col_idx < space_cnt; col_idx++) {
			cin >> arr[row_idx][col_idx];
		}
	}

	//플로이드워샬
	for (int i = 0; i < space_cnt; i++) {
		for (int j = 0; j < space_cnt; j++) {
			if (i == j) continue;
			for (int k = 0; k < space_cnt; k++) {
				arr[i][j] = min(arr[i][k] + arr[k][j], arr[i][j]);
			}
		}
	}



	//최소거리 구하기

	DFS(start, 0, (1 << start), 1);

	cout << result;


	return 0;
}