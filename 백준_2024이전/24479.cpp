#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, m, r;
vector<int> v[100001];

int visited[100001] = { 0, };
int dist[100001] = { 0, };
int cnt = 1;

void dfs(int node) {

	dist[node] = cnt;
	visited[node] = 1;
	cnt++;

	for (int i = 0; i < v[node].size(); i++) {
		if(visited[v[node][i]] == 0) dfs(v[node][i]);
	}
	

}

int main() {
	cin.tie(NULL);
	cin.sync_with_stdio(false);

	cin >> n >> m >> r;
	for (int i = 0; i < m; i++){
		int x, y;
		cin >> x >> y;
		v[x].push_back(y);
		v[y].push_back(x);
	}

	for (int i = 1; i < n + 1; i++) {
		sort(v[i].begin(), v[i].end());
	}



	dfs(r);

	for (int i = 1; i < n + 1; i++) {
		cout << dist[i] << "\n";
	}

	return 0;
}