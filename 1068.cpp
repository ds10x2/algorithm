#include <iostream>
#include <vector>
using namespace std;


int N, D;
int root;
vector<int> node[51];
int cnt = 0;

int DFS(int n) {
	
	if (n == D) return -1;

	if (!node[n].size()) {
		cnt++;
		return 0;
	}
	for (int i = 0; i < node[n].size(); i++) {
		int tmp = DFS(node[n][i]);
		if (tmp == -1 && node[n].size() == 1)
			cnt++;
	}
	return 0;
	
}


int main() {
	cin.tie(NULL);
	cin.sync_with_stdio(false);

	cin >> N;

	for (int i = 0; i < N; i++) {
		int n;
		cin >> n;
		if (n == -1) {
			root = i;
		} 
		else 
			node[n].push_back(i);
	}

	cin >> D;

	if (D == root) { //root가 삭제되는 경우
		cout << 0;
		return 0;
	}


	DFS(root);


	cout << cnt;

	return 0;
}