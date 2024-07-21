/*

백준 1613 역사

<입력>
사건의 개수 n(400 이하의 자연수), 사건의 전후 관계의 개수 k(50000 이하의 자연수)
전 후관계를 알고 있는 두 사건의 번호
사건의 전후 관계를 알고 싶은 사건 쌍의 수 s (50000이하의 자연수)

<출력>
a b의 입력일 때 a가 먼저 일어났으면 -1, 나중에 일어났으면 1, 유추할 수 없다면 0

*/


#include <iostream>
using namespace std;

int history[401][401];
int n, k, s;

int main() {
	cin.tie(NULL);
	cin.sync_with_stdio(false);

	cin >> n >> k;
	
	for (int idx = 0; idx < k; idx++) {
		int a, b;
		cin >> a >> b;
		history[a][b] = 1; //a가 b보다 먼저 일어난 사건 
	}

	//플로이드-워샬
	for (int idx = 1; idx <= n; idx++) {
		for (int a = 1; a <= n; a++) {
			if (history[a][idx] != 1) continue;
			for (int b = 1; b <= n; b++) {
				if (history[idx][b] == 1)
					history[a][b] = 1;
			}
		}
	}

	cin >> s;
	int a, b;
	for (int idx = 0; idx < s; idx++) {
		cin >> a >> b;
		if (history[a][b] == 1)
			cout << -1 << "\n";
		else if (history[b][a] == 1)
			cout << 1 << "\n";
		else cout << 0 << "\n";
	}

	return 0;
}