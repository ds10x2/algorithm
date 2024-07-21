/*

백준 2458 키 순서


<입력>
학생들의 수, 두 학생 키를 비교한 횟수
a < b


*/


#include <iostream>
using namespace std;

int students[501][501];
int stu_cnt, com_cnt;


int main() {
	cin.tie(NULL);
	cin.sync_with_stdio(false);

	cin >> stu_cnt >> com_cnt;

	int a, b;
	for (int idx = 0; idx < com_cnt; idx++) {
		cin >> a >> b;
		students[a][b] = 1;
	}

	for (int k = 1; k <= stu_cnt; k++) {
		for (int i = 1; i <= stu_cnt; i++) {
			if (students[i][k] != 1) continue;
			for (int j = 1; j <= stu_cnt; j++) {
				if (students[k][j] == 1) students[i][j] = 1;
			}
		}
	}

	int result = 0;

	for (int idx = 1; idx <= stu_cnt; idx++) {
		int cnt = 0;
		for (int s = 1; s <= stu_cnt; s++) {
			if (students[idx][s] == 1 || students[s][idx] == 1) cnt++;
		}
		if (cnt == stu_cnt - 1) result++;
	}
	
	cout << result;

	return 0;
}