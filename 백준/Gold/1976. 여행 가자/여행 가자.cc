#include <iostream>
#include <algorithm>
using namespace std;

int n, m, cnt;
int arr[201];

int find(int x) {
	if (arr[x] == x) return x;
	return arr[x] = find(arr[x]);
}

void union_node(int a, int b) {
	a = find(a);
	b = find(b);
	if (a < b) arr[b] = a;
	else arr[a] = b;
}

int main() {
	cin.tie(NULL);
	cin.sync_with_stdio(false);

	cin >> n >> m;
	for (int idx = 1; idx <= n; idx++) {
		arr[idx] = idx;
	}
	for (int row = 1; row <= n; row++) {
		for (int col = 1; col <= n; col++) {
			int num;
			cin >> num;
			if (num == 1) union_node(row, col);
		}
	}

	int root;
	for (int idx = 0; idx < m; idx++) {
		int num;
		cin >> num;
		if (idx == 0) root = find(num);
		else {
			if (find(root) != find(num)) {
				cout << "NO";
				return 0;
			}
		}
	}
	cout << "YES";
	return 0;
}