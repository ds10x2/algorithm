#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

const int MAX = 1 << 21;

int k, treeSize;
int result;
int arr[MAX];


int dfs(int idx) {
	if (idx * 2 >= treeSize) {
		result += arr[idx];
		return arr[idx];
	}
	else {
		int leftNode = dfs(idx * 2);
		int rightNode = dfs(idx * 2 + 1);
		result += arr[idx] + abs(leftNode - rightNode);
		return arr[idx] + max(leftNode, rightNode);
	}
}

int main() {
	cin.tie(NULL);
	cin.sync_with_stdio(false);

	cin >> k;

	treeSize = 1 << (k + 1);
	for (int i = 2; i < treeSize; i++) {
		cin >> arr[i];

	}

	dfs(1);

	cout << result << "\n";



	return 0;
}