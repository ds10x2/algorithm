#include <iostream>
using namespace std;

int n, m;
int arr[8];
bool visited[8] = { 0, };


void dfs(int cnt) {
	if (cnt == m) {
		for (int i = 0; i < m; i++)
			cout << arr[i] << " ";
		cout << "\n";
		return;
	}
	for (int i = 1; i <= n; i++) {
		visited[i] = true;
		arr[cnt] = i;
		dfs(cnt + 1);
		visited[i] = false;
	}

}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> n >> m; //1 <= m <= n <= 7

	dfs(0);


	return 0;
}