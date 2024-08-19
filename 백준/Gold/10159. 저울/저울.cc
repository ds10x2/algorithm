#include <iostream>
#include <algorithm>
using namespace std;

/*
10159 저울
물건 개수 N과 일부 물건 쌍의 비교 결과가 주어졌을 때,
각 물건과의 비교 결과를 알 수 없는 물건의 개수를 출력

5 <= N <= 100
0 <= M <= 2000

앞의 물건이 뒤의 물건보다 무거움

*/

int cnt, com_cnt;
int arr[101][101];


int main() {

	cin >> cnt >> com_cnt;
	for (int i = 0; i < com_cnt; i++) {
		int x, y;
		cin >> x >> y;
		arr[y][x] = 1; //y가 x보다 가벼움
		arr[x][y] = -1; // x가 y보다 무거움

	}


	for (int k = 1; k <= cnt; k++) {
		for (int i = 1; i <= cnt; i++) {
			if (arr[i][k] == 0) continue;
			for (int j = 1; j <= cnt; j++) {
				if (arr[k][j] == 0) continue;

				
				if (arr[i][k] == 1 && arr[k][j] == 1) arr[i][j] = 1;
				else if (arr[i][k] == -1 && arr[k][j] == -1) arr[i][j] = -1;

			}
		}
	}



	int result = 0;

	for (int i = 1; i <= cnt; i++) {
		int c = 0;
		for (int j = 1; j <= cnt; j++) {
			if (arr[i][j] == 0) c++;
		}
		cout << c - 1<< "\n";
	}



	return 0;
}