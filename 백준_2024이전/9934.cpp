#include <iostream>
#include <cmath>
#include <vector>
using namespace std;
//중위 순회

int K;
int inorder[1024];
vector<int> tree[10];

//st = 1, ed = node
void traverse(int depth, int st, int ed) {
	
	if (st > ed) return;

	int root = (st + ed) / 2;

	tree[depth].push_back(inorder[root]);

	traverse(depth + 1, st, root - 1);
	traverse(depth + 1, root + 1, ed);

}

int main() {
	cin.tie(NULL);
	cin.sync_with_stdio(false);

	cin >> K;

	int node = pow(2, K) - 1;
	
	for (int i = 1; i <= node; i++) {
		cin >> inorder[i];
	}

	traverse(0, 1, node);

	for (int i = 0; i < K; i++) {
		for (int j = 0; j < tree[i].size(); j++) {
			cout << tree[i][j] << " ";
		}
		cout << "\n";
	}

	return 0;
}