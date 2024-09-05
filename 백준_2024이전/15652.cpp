#include <iostream>
using namespace std;

int n, m;
int arr[9];


void recur(int cnt) {
	if (cnt == m) {
		for (int i = 0; i < m; i++)
			cout << arr[i] << " ";
		cout << "\n";
		return;
	}
	int st = 1;
	if (cnt != 0)
		st = arr[cnt - 1];
	for (int i = st; i <= n; i++) {
		arr[cnt] = i;
		recur(cnt + 1);
	}

}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> n >> m; //1 <= m <= n <= 7

	recur(0);


	return 0;
}