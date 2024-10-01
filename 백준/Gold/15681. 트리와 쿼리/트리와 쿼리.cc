#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cmath>
using namespace std;

/*

백준 15681번 트리와 쿼리

간선에 가중치와 방향성이 없는 임의의 루트 있는 트리가 주어짐

정점U를 루트로 하는 서브트리에 속한 정점의 수를 출력


<입력>
트리의 정점의 수 N, 루트의 번호 R,  쿼리의 수 Q
U V의 형태로 트리에 속한 간선의 정보가 주어짐
U와 V를 양 끝점으로 하는 간선이 트리에 속함을 의미
Q줄에 걸쳐 U가 주어짐

*/

int N, R, Q; 
int u, v;
vector<int> tree[100001];
int sub_nodes[100001]; //N번 정점의 서브트리 정점 수
bool visited[100001];

int get_sub_nodes(int node) {

	if (visited[node]) return sub_nodes[node];
	visited[node] = true;

	
	for (int idx = 0; idx < tree[node].size(); idx++) {

		int next = tree[node][idx];
		if (visited[next]) continue;

		sub_nodes[node] += get_sub_nodes(next);

	}

	return sub_nodes[node];

}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> R >> Q;

	for (int idx = 0; idx < N-1; idx++) {
		cin >> u >> v;
		tree[u].push_back(v);
		tree[v].push_back(u);
	}

	for (int idx = 1; idx <= N; idx++)
		sub_nodes[idx] = 1;

	get_sub_nodes(R);


	for (int idx = 0; idx < Q; idx++) {
		cin >> u;

		cout << sub_nodes[u] << "\n";
	}


	return 0;
}