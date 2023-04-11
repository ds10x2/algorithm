#include <iostream>
#include <math.h>
using namespace std;

int n;
int arr[21][21];
bool visited[21] = { false, };
int MIN = 10000000;

void check() {
	int starScore = 0;
	int linkSocre = 0;

	int res;

	for (int i = 1; i < n; i++) {
		for (int j = i + 1; j <= n; j++) {
			if (visited[i] && visited[j]) {
				starScore += arr[i][j];
				starScore += arr[j][i];
			}else if (!visited[i] && !visited[j]) {
				linkSocre += arr[i][j];
				linkSocre += arr[j][i];
			}
		}
	}
	res = abs(starScore - linkSocre);
	MIN = res < MIN ? res : MIN;
}

void select(int cnt, int index) {
	if (cnt == n / 2) {
		check();
		return;
	}

	for (int i = index; i <= n; i++) {
		visited[i] = true;
		select(cnt + 1, i + 1);
		visited[i] = false;
	}

}

int main() {

	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> n;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> arr[i][j];
		}
	}

	select(0, 1);
	cout << MIN;



	return 0;
}